set(HEADERS CSR_matrix.h
    dense_matrix.h
    three_diagonal_matrix.h
    vector_operations.h
    msi.h
    chebyshev_msi.h)
set(SOURCES thomas_method.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)




