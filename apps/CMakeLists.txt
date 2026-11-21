add_executable(search main.cpp)
target_link_libraries(search PRIVATE search_lib)
target_compile_options(search PRIVATE -Wall -Wextra)    