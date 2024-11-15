# CMakeList.txt: Tetris 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
set(SDL2_Dir Dependences)
add_subdirectory ("../Application" "Application")
find_package(SDL2)
# 将源代码添加到此项目的可执行文件。
add_executable (Tetris "Tetris.c" "Tetris.h" "../Application/draw.c" "../Application/draw.h")
target_link_libraries(Tetris app SDL2 SDL2main  SDL2_image SDL2_mixer SDL2_ttf  widgets)
#no mxml4

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Tetris PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
