set(LIB_NAME LIB_ThreadPool)
aux_source_directory(src SRC_FILES)

add_library(${LIB_NAME} ${BUILD_LIBRARY_TYPE} ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC inc)
target_link_libraries(${LIB_NAME} LIB_QueueSync)
target_link_libraries(${LIB_NAME} Threads::Threads)