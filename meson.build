project('BeanEngine', 'cpp', 'cuda',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

fmod_inc = include_directories('./source/thirdparty/fmod/core/inc')

fmod_lib_path = './source/thirdparty/fmod/core/lib/x64'
fmod_lib = declare_dependency(
        include_directories: fmod_inc,
        link_args: [
                join_paths(fmod_lib_path, 'fmod_vc.lib')
        ]
)


subdir('source/engine')
subdir('source/game')