cmake_minimum_required(VERSION 3.5)

project(ParallelMatrixMultiply LANGUAGES C)

add_executable(ParallelMatrixMultiply main.c)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(ParallelMatrixMultiply PRIVATE Threads::Threads)
