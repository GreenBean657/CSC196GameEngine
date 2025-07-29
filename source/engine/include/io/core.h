#pragma once
#include <string>
#include <vector>

namespace bean_engine::file_io {
    /**
     * Get the working directory for the file manager.
     * @brief Get working directory.
     * @return Working directory.
     */
    std::string getCurrentDirectory();
    /**
    * @brief Change the working directory.
    * @param fpath Path to set as the working directory.
    * @throws std::filesystem::filesystem_error failure to set working directory.
    */
    void setCurrentDirectory(const std::string &fpath);
    /**
     * @brief Get the Extension of a file.
     * @param fpath Filepath.
     * @return File extension with a dot. (.json, .txt)
     */
    std::string getExtension(const std::string &fpath) noexcept;

    /**
     * Get the file name of a file, without the extension.
     * @brief Get file path.
     * @param fpath Filepath.
     * @return File path. "~/Home/foobar/Downloads/myfile.txt -> myfile"
     */
    std::string getFileName(const std::string &fpath) noexcept;

    /**
     * @brief Check if a file exists.
     * @param fpath Filepath.
     * @return TRUE/FALSE (Exists / Does not)
     */
    bool exists(const std::string &fpath) noexcept;

    /**
     * @brief Get all files in a path.
     * Get all the files in a file path. Excludes directories.
     * @param fpath Filepath.
     * @return Array of strings representing the directory of each file.
     */
    std::vector<std::string> listFiles(const std::string &fpath);

    /**
     * @brief Get all directories in a path.
     * Get all the directories in a file path. Excludes files.
     * @param fpath Filepath.
     * @return Array of strings representing the directory of each directory.
     */
    std::vector<std::string> listDirs(const std::string &fpath);

    /**
     * @brief Read the contexts of a text file.
     * @param fpath File path.
     * @return File contents.
     * @throws std::filesystem::filesystem_error Failed to locate the file, or the file is locked.
     */
    std::string ReadTextFile(const std::string& fpath);

    /**
     * @brief Write to a text file.
     * @param fpath File path.
     * @param content Content to write to the file.
     * @param append Should the file be replaced, or appended? (TRUE = APPEND)
     * @throws std::filesystem::filesystem_error Failed to locate the file, or the file is locked.
     */
    void WriteTextFile(const std::string &fpath, const std::string &content, const bool append = false);
}
