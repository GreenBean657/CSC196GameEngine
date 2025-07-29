#pragma once
#include <iostream>
#include "io/file.h"

inline int demo() {
  
    // Get current directory path
    std::cout << "Directory Operations:\n";
    std::cout << "Current directory: " << bean_engine::file_io::getCurrentDirectory() << "\n";

    // Set current directory path (current path + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    bean_engine::file_io::setCurrentDirectory("Imported/Assets");
    std::cout << "New directory: " << bean_engine::file_io::getCurrentDirectory() << "\n\n";

    // Get filenames in the current directory
    std::cout << "Files in Directory:\n";
    auto filenames = bean_engine::file_io::listFiles(bean_engine::file_io::getCurrentDirectory());
    for (const auto& filename : filenames) {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // Get filename (filename.extension) only
    if (!filenames.empty()) {
        std::cout << "Path Analysis:\n";
        std::string filename = bean_engine::file_io::getFileName(filenames[0]);
        std::cout << "Filename only: " << filename << "\n";

        // Get extension only
        std::string ext = bean_engine::file_io::getExtension(filenames[0]);
        std::cout << "Extension: " << ext << "\n\n";
    }

    // Read and display text file
    std::cout << "Text File Reading:\n";
    const std::string str = bean_engine::file_io::ReadTextFile("test.txt");
    std::cout << str << "\n";
    return 0;
}
