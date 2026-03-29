cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
project(pico_logitech_mouse)

pico_sdk_init()

add_executable(pico_logitech_mouse
    main.c
)

target_include_directories(pico_logitech_mouse PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(pico_logitech_mouse
    pico_stdlib
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(pico_logitech_mouse)
