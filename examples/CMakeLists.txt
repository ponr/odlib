include_directories(../src)

set(EXAMPLE_HAL_WINDOW_SRC
    hal_window/main.cpp
    )

add_executable(hal_window ${EXAMPLE_HAL_WINDOW_SRC})
target_link_libraries(hal_window od_graphics)

