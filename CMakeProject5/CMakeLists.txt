add_executable (CMakeProject5 "maing.cpp" "Graph.h" "graph.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject5 PROPERTY CXX_STANDARD 20)
endif()

