
engine_inc = include_directories('include')

engine_sources = files(
    'src/engine.cpp'
)

engine_lib = static_library('engine',
                            engine_sources,
                            include_directories : engine_inc,
                            dependencies : [
                                #Example dependency
                                dependency('fmt', version: '>=8.0.0'),
                            ],
                            install : true,
)

engine_dep = declare_dependency(
    link_with : engine_lib,
    include_directories : engine_inc
)

