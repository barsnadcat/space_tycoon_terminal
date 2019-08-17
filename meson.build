project('space_tycoon_terminal', 'cpp')
src = ['src/Main.cpp']


compiler = meson.get_compiler('cpp')
readline_dep = compiler.find_library('readline')

space_tycoon_model_dep = dependency('space_tycoon_model', fallback : ['space_tycoon_model', 'space_tycoon_model_dep'])

executable('space_tycoon', src, dependencies : [space_tycoon_model_dep, readline_dep],  install : true)
