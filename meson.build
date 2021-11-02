project('space_tycoon_terminal', 'cpp')

easyloggingpp_dep = dependency('easyloggingpp', required : false)
if not easyloggingpp_dep.found()
	cmake = import('cmake')
	easyloggingpp_proj = cmake.subproject('easyloggingpp', cmake_options: ['-Dbuild_static_lib=ON'])
    easyloggingpp_dep = easyloggingpp_proj.dependency('easyloggingpp')
endif

space_tycoon_model_prj = subproject('space_tycoon_model')

subdir('src')
inc = include_directories(['src', 'cpp-linenoise'])
executable('space_tycoon', src, include_directories: inc, 
    dependencies : [space_tycoon_model_prj.get_variable('space_tycoon_model_dep'), easyloggingpp_dep])
