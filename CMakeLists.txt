cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(logitech_m185_hid C CXX ASM)

pico_sdk_init()

add_executable(logitech_m185
    main.c
    usb_descriptors.c
)

target_include_directories(logitech_m185 PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(logitech_m185
    pico_stdlib
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(logitech_m185)
