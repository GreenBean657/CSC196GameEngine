
#include <iostream>
#include <bits/ostream.tcc>
#include <SDL3/SDL.h>

#include <thread>

#include "core/math.h"

#define CPU_R_RANDOM_LINES 300
#define CPU_R_RANDOM_DOTS 60000

namespace engine::cpurender {
    /**
     * Fill an array with random values, in a thread safe manner.
     * @param start Start of the array to write on.
     * @param end Ending array to write on.
     * @param data Data to write.
     * @param maxVal Highest supported value for the operation.
     */
    void arrayFill(const size_t start, const size_t end, uint32_t* data, uint32_t maxVal) {
        for (int i = start; i < end; i++) {
            data[i] = math::getRandomInt(maxVal);
        }
    }

    /**
     * Sync an array of threads.
     * @param threads Threads to sync.
     * @param threadCt Thread array length.
     */
    void __threadSync(auto *threads, const size_t threadCt) {
        for (int i = 0; i < threadCt; i++) {
            threads[i].join();
        }
    }
    /**
     * Draw a window consisting of random dots and lines.
     * @param title Window title.
     * @param widthHeight Height of the window.
     * @return Error code - 1: ERR - 0: SUCCESS
     */
    [[nodiscard]] int drawRandomWindow(const std::string &title, const uint32_t &widthHeight) {

        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window* window = SDL_CreateWindow(title.c_str(), widthHeight, widthHeight, 0);

        if (window == nullptr) {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
        if (renderer == nullptr) {
            std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }


        {
            auto dotArray_Len = CPU_R_RANDOM_DOTS * 2;
            auto lineArray_Len = CPU_R_RANDOM_DOTS * 4;

            auto rgbArray_Len = (128 * 3);
            uint32_t dotArrayPos = 0;
            uint32_t lineArrayPos = 0;
            uint32_t rgbArrayPos = 0;

            auto* dotArray = new uint32_t[dotArray_Len];
            auto* lineArray = new uint32_t[lineArray_Len];
            auto* rgbArray = new uint32_t[rgbArray_Len];

            {
                uint32_t threadCt = std::thread::hardware_concurrency();
                if (threadCt == 0) {threadCt = 4;};
                auto* threads = new std::thread[threadCt];

                size_t workPerThread = std::ceil(static_cast<double>(dotArray_Len) / threadCt);
                for (int i = 0; i < threadCt; i++) {
                    size_t start = i * workPerThread;
                    size_t end = (i + 1) * workPerThread;
                    if (end > dotArray_Len) {end = dotArray_Len;};
                    threads[i] = std::thread(arrayFill, start, end, dotArray, widthHeight);

                }

                __threadSync(threads, threadCt);

                workPerThread = std::ceil(static_cast<double>(lineArray_Len) / threadCt);
                for (int i = 0; i < threadCt; i++) {
                    size_t start = i * workPerThread;
                    size_t end = (i + 1) * workPerThread;
                    if (end > dotArray_Len) {end = lineArray_Len;};
                    threads[i] = std::thread(arrayFill, start, end, lineArray, widthHeight);
                }

                __threadSync(threads, threadCt);

                workPerThread = std::ceil(static_cast<double>(rgbArray_Len) / threadCt);
                for (int i = 0; i < threadCt; i++) {
                    size_t start = i * workPerThread;
                    size_t end = (i + 1) * workPerThread;
                    if (end > rgbArray_Len) {end = rgbArray_Len;};
                    threads[i] = std::thread(arrayFill, start, end, rgbArray, 255);
                }

                __threadSync(threads, threadCt);
                delete[] threads;
            }



            SDL_Event event;
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_EVENT_QUIT) {
                        quit = true;
                    }
                }

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);

                //SDL is not thread safe, which is lame.
                for (uint32_t i = 0; i < CPU_R_RANDOM_DOTS; ++i) {
                    SDL_SetRenderDrawColor(
                        renderer,
                        rgbArray[++rgbArrayPos],
                        rgbArray[++rgbArrayPos],
                        rgbArray[++rgbArrayPos],
                        255);
                    SDL_RenderPoint(renderer, dotArray[++dotArrayPos], dotArray[++dotArrayPos]);
                    if (rgbArrayPos >= rgbArray_Len) {rgbArrayPos = 0;};
                }
                    rgbArrayPos = 0;

                for (uint32_t i = 0; i < CPU_R_RANDOM_LINES; i++) {
                    SDL_SetRenderDrawColor(
                        renderer,
                        rgbArray[++rgbArrayPos],
                        rgbArray[++rgbArrayPos],
                        rgbArray[++rgbArrayPos],
                        255);

                    if (rgbArrayPos >= rgbArray_Len) {rgbArrayPos = 0;};
                    SDL_RenderLine(renderer,
                    lineArray[++lineArrayPos],
                    lineArray[++lineArrayPos],
                    lineArray[++lineArrayPos],
                    lineArray[++lineArrayPos]
                        );
                }
                SDL_RenderPresent(renderer);

                lineArrayPos = 0;
                dotArrayPos = 0;
            }

            delete[] dotArray;
            delete[] lineArray;
            delete[] rgbArray;
        }
        return 0;
    }
}
