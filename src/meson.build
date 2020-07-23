buildtutorlia_sources = [
  'main.c',
  'sqlconn.h',
]

buildtutorlia_deps = [
  dependency('glib-2.0'),
  dependency('gtk+-3.0'),
  dependency('gmodule-2.0'),
  dependency('libpq'),
]

executable('buildtutorlia', buildtutorlia_sources,
  dependencies: buildtutorlia_deps,
  install: true,
)
