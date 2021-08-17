
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB_RECURSE MODULE_SRC *.cpp *.cc *.cxx *.c)
add_library(${MODULE_NAME} STATIC ${MODULE_SRC})