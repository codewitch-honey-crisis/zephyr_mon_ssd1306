cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_mon_ssd1306)
target_sources(app PRIVATE src/main.cpp src/ui.cpp)
