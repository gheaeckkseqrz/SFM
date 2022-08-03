
add_executable(TestImagesLoader images_loader.cpp)
target_link_libraries(TestImagesLoader ImagesLoader)
add_test(NAME TestImagesLoader COMMAND TestImagesLoader WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
