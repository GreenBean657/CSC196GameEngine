# Find CUDA dependency

engine_inc = include_directories('include')
engine_sources = files(
    'src/engine.cpp',
    'src/render/cpurender.cpp',
    'src/render/gpurender.cu',
    'src/render/renderer.cpp',
    'src/math/math.cpp',
    'src/input/inputsystem.cpp'
)

engine_lib = static_library('engine',
                            engine_sources,
                            include_directories : engine_inc,
                            dependencies : [
                                dependency('fmt', required: false),
                                dependency('cuda', required: true),
                                dependency('hip', required: true),
                                dependency('sdl3', required: true),
                            ],
                            install : true,
)

engine_dep = declare_dependency(
    link_with : engine_lib,
    include_directories : engine_inc
)

