cmake_minimum_required(VERSION 3.20)
project(image_classifier)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR "C:/OpenCV/opencv/build")

find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
#message(STATUS "OpenCV library status:")
#message(STATUS "    config: ${OpenCV_DIR}")
#message(STATUS "    version: ${OpenCV_VERSION}")
#message(STATUS "    libraries: ${OpenCV_LIBS}")
#message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")


file(GLOB srcs *.cpp *.c)
file(GLOB hdrs *.hpp *.h)
include_directories("${CMAKE_CURRENT_LIST_DIR}")

# Since there are a lot of examples I'm going to use a macro to simplify this
# CMakeLists.txt file.  However, usually you will create only one executable in
# your cmake projects and use the syntax shown above.


add_executable(image_classifier main.cpp)
target_link_libraries(image_classifier PRIVATE ${OpenCV_LIBS})
target_compile_features(image_classifier PRIVATE cxx_std_17)