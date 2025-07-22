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
)

engine_lib = static_library('engine',
                            engine_sources,
                            include_directories : engine_inc,
                            dependencies : [
                                dependency('fmt', required: false),
                                dependency('cuda', required: true),
                                dependency('hip', required: true),
                                dependency('sdl3', required: true),
                                dependency('sdl3-ttf', required: true)                            ],
                            install : true,
)

engine_dep = declare_dependency(
    link_with : engine_lib,
    include_directories : engine_inc
)

