# Find CUDA dependency

engine_inc = include_directories('include')
engine_sources = files(
    'src/engine.cpp',

    'src/audio/core.cpp',

    'src/renderer/core.cpp',
    'src/renderer/model.cpp',

    'src/renderer/font.cpp',
    'src/renderer/text.cpp',
    'src/input/core.cpp',

    'src/io/core.cpp',
    'src/env/actor.cpp',
    'src/env/player.cpp',
    'src/env/enemy.cpp',
    'src/env/scene.cpp'
)
fmod_inc = include_directories('../../source/thirdparty/fmod/core/inc')

fmod_lib_path = '/home/GreenBean/CLionProjects/CSC196/BeanEngine/source/thirdparty/fmod/core/lib/x86_64'
fmod_lib = declare_dependency(
    include_directories: fmod_inc,
    link_args: [
        join_paths(fmod_lib_path, 'libfmod.so')
    ]
)


engine_lib = static_library('engine',
                            engine_sources,
                            include_directories : engine_inc,
                            dependencies : [
                                dependency('fmt', required: false),
                                dependency('sdl3', required: true),
                                dependency('sdl3-ttf', required: true),
                                fmod_lib

                            ],
                            install : true,
)

engine_dep = declare_dependency(
    link_with : engine_lib,
    include_directories : engine_inc
)

