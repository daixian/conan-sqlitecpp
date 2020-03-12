cmake_minimum_required(VERSION 3.1.2)
project(cmake_wrapper)

include(conanbuildinfo.cmake)
# conan_basic_setup(TARGETS)
#使用它这个没办法应用上,所以修改成下面我这样
conan_basic_setup()

add_subdirectory("source_subfolder")