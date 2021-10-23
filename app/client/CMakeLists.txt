set(LIB_NAME LIB_Client)
aux_source_directory(src SRC_FILES)

add_library(${LIB_NAME} ${BUILD_LIBRARY_TYPE} ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC inc)
