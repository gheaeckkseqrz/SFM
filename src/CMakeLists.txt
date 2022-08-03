
add_library(ImagesLoader images.cpp)
target_link_libraries(ImagesLoader PUBLIC "${TORCH_LIBRARIES}")
