include_directories(../src)

set(EXAMPLE_HAL_WINDOW_SRC
    hal_window/main.cpp
    )

set(EXAMPLE_ODSL_COMPILER_SRC
    odsl_compiler/main.cpp
    )

add_executable(hal_window ${EXAMPLE_HAL_WINDOW_SRC})
target_link_libraries(hal_window od_graphics od_platform)

add_executable(odsl_compiler ${EXAMPLE_ODSL_COMPILER_SRC})
target_link_libraries(odsl_compiler od_graphics)

