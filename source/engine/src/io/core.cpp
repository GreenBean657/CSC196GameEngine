#include "include/io/core.h"


#include "include/exceptions/io.h"
#include <filesystem>
#include <fstream>
#include <system_error>
#include <chrono>
#include <thread>

namespace bean_engine::file_io {
    [[nodiscard]] std::string getCurrentDirectory() {
        std::error_code ec;
        const std::filesystem::path path = std::filesystem::current_path(ec);
        if (ec) {
            return {};
        }
        return path.string();

    }
    void setCurrentDirectory(const std::string &fpath) {
        std::error_code ec;
        std::filesystem::current_path(fpath, ec);
        if (ec) {
            throw exceptions::FileIOException("Failed to set working directory, unknown path.", fpath);
        }
    }
    [[nodiscard]] std::string getExtension(const std::string &fpath) {
        const std::filesystem::path file(fpath);
        return file.extension().string();
    }
    [[nodiscard]] std::string getFileStem(const std::string &fpath) {
        const std::filesystem::path file(fpath);
        return file.stem().generic_string();  // stem() strips the extension
    }


    [[nodiscard]] std::string getFileName(const std::string &fpath) {
        return getFileStem(fpath) + getExtension(fpath);
    }

    [[nodiscard]] bool exists(const std::string &fpath) {
        std::error_code ec;
        const bool result = std::filesystem::exists(fpath, ec);
        return result;
    }
    [[nodiscard]] std::vector<std::string> listFiles(const std::string& fpath) {
        std::vector<std::string> files;
        std::error_code ec;

        auto iter = std::filesystem::directory_iterator(fpath, ec);
        if (ec) return files;

        for (const auto& entry : iter) {
            if (entry.is_regular_file(ec) && !ec) {
                files.push_back(entry.path().string());
            }
        }

        return files;
    }
    [[nodiscard]] std::vector<std::string> listDirs(const std::string& fpath) {
        std::vector<std::string> directories;
        std::error_code ec;

        auto iter = std::filesystem::directory_iterator(fpath, ec);
        if (ec) return directories;

        for (const auto& entry : iter) {
            if (entry.is_directory(ec) && !ec) {
                directories.push_back(entry.path().string());
            }
        }

        return directories;
    }

    [[nodiscard]] std::string ReadTextFile(const std::string& fpath) {
        if (!exists(fpath)) {
            throw exceptions::FileIOException("File does not exist!", fpath);
        }
        std::ifstream file;
        for (size_t attempt = 0; attempt < 3; ++attempt) {
            file.open(fpath);
            if (file.is_open()) {
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if (!file.is_open()) {
            throw exceptions::FileIOException("File cannot be opened or is in use!", fpath);
        }
        std::ostringstream ss;
        ss << file.rdbuf();
        file.close();
        return ss.str();
    }

    void WriteTextFile(const std::string &fpath, const std::string &content, const bool append) {
            const std::ios::openmode mode = append ? std::ios::app : std::ios::out;
            std::ofstream file(fpath, mode);
            if (!file.is_open()) {
                throw exceptions::FileIOException("File cannot be opened or is in use!", fpath);
            }
            file << content;
    }
}
