#pragma once

#include <stdexcept>
#include <string>
namespace bean_engine::exceptions {
    class FileIOException final : public std::runtime_error {
        std::string file_path;
    public:
        FileIOException(const std::string& message, const std::string& path)
            : std::runtime_error(message), file_path(path) {}

        const std::string& getPath() const { return file_path; }
    };
}
