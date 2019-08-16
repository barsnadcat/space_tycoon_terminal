project('space_tycoon_terminal', 'cpp')
src = ['Main.cpp']

space_tycoon_model_dep = dependency('space_tycoon_model', fallback : ['space_tycoon_model', 'space_tycoon_model_dep'])

executable('space_tycoon', src, dependencies : space_tycoon_model_dep,  install : true)
