
add_library(ImagesLoader images.cpp)
target_link_libraries(ImagesLoader PUBLIC "${TORCH_LIBRARIES}")

add_executable(GUI gui.cpp)
target_link_libraries(GUI PUBLIC sfml-graphics ImagesLoader)
