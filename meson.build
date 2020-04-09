project('space_tycoon_terminal', 'cpp')
src = ['src/Main.cpp']

compiler = meson.get_compiler('cpp')
readline_dep = compiler.find_library('readline', required: false)
if not readline_dep.found()
	message('Trying GnuWin32 directory C:\Program Files (x86)\GnuWin32\lib')
	readline_dep = compiler.find_library('readline', dirs: ['C:\Program Files (x86)\GnuWin32\lib'])
endif

easyloggingpp_dep = dependency('easyloggingpp', required : false)
if not easyloggingpp_dep.found()
	cmake = import('cmake')
	easyloggingpp_proj = cmake.subproject('easyloggingpp', cmake_options: '-Dbuild_static_lib=ON')
	easyloggingpp_dep = easyloggingpp_proj.get_variable('cm_easyloggingpp')
endif

space_tycoon_model_dep = dependency('space_tycoon_model', fallback : ['space_tycoon_model', 'space_tycoon_model_dep'])

executable('space_tycoon', src, install : true,
    dependencies : [space_tycoon_model_dep, readline_dep, easyloggingpp_dep])
