#!/usr/bin/env python3
import os
import sys
import shutil


def copy_path(src, dst):
    if os.path.isdir(src):
        if os.path.exists(dst):
            try:
                if os.path.isdir(dst):
                    shutil.rmtree(dst)
                    print(f"Removed existing directory {dst}")
                else:
                    os.remove(dst)
                    print(f"Removed existing file {dst}")
            except (OSError, PermissionError) as e:
                print(f"Warning: Could not remove {dst}: {e}")
                sys.exit(1)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copytree(src, dst)
        print(f"Copied directory {src} to {dst}")
    elif os.path.isfile(src):
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy2(src, dst)
        print(f"Copied file {src} to {dst}")
    else:
        print(f"Error: Source path {src} does not exist or is not a file/directory.")
        sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: copy.py <source_path> <dest_path>")
        sys.exit(1)

    MESON_SOURCE_ROOT = os.getenv('MESON_SOURCE_ROOT')
    MESON_BUILD_ROOT = os.getenv('MESON_BUILD_ROOT')
    MESON_SUBDIR = os.getenv('MESON_SUBDIR', '')

    if MESON_SOURCE_ROOT and MESON_BUILD_ROOT:
        input_path = os.path.join(MESON_SOURCE_ROOT, MESON_SUBDIR, sys.argv[1])
        output_path = os.path.join(MESON_BUILD_ROOT, MESON_SUBDIR, sys.argv[2])
    else:
        input_path = sys.argv[1]
        output_path = sys.argv[2]

    copy_path(input_path, output_path)
