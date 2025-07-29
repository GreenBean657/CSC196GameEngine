fs = import('fs')

copy = find_program('copy.py')

# Get the source and build directories
source_dir = meson.current_source_dir()
build_dir = meson.current_build_dir()

# Create a custom target that generates a dummy file
copy_imported = custom_target('copy_imported',
                              output: 'copy_stamp.h',
                              command: [
                                  copy,
                                  join_paths(source_dir, 'Imported'),     # Full source path
                                  join_paths(build_dir, 'Imported'),      # Full destination path
                                  '&&', 'echo', '"// Copy completed"', '>', '@OUTPUT@'
                              ],
                              build_always_stale: true
)

# Game executable
game_sources = files('main.cpp')

game = executable('game',
                  [game_sources, copy_imported],
                  dependencies: [engine_dep],
                  install: true,
                  install_dir: 'bin'
)