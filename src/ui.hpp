#pragma once
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <uix.hpp>
#include <gfx.hpp>

using screen_t = uix::screen<320, 240, gfx::rgb_pixel<16>>;
using label_t = uix::label<typename screen_t::control_surface_type>;
using svg_box_t = uix::svg_box<typename screen_t::control_surface_type>;
using canvas_t = uix::canvas<typename screen_t::control_surface_type>;
// X11 colors (used for screen)
using color_t = gfx::color<typename screen_t::pixel_type>;
// RGBA8888 X11 colors (used for controls)
using color32_t = gfx::color<gfx::rgba_pixel<32>>;
// circular buffer for graphs
using buffer_t = data::circular_buffer<uint8_t,100>;

extern const struct device *display_dev;
constexpr static const size_t lcd_buffer_size = 64 * 1024;
extern uint8_t lcd_buffer[];
extern screen_t main_screen;
extern screen_t disconnected_screen;
extern screen_t* active_screen;
constexpr static const gfx::rgba_pixel<32> transparent(0, 0, 0, 0);

extern void uix_flush(const gfx::rect16 &bounds, const void *bmp, void *state);

// the buffers hold the graph data for the CPU
extern buffer_t cpu_buffers[];
// the array holds the bar/label data for the CPU
extern float cpu_values[];
// the max temperature received for the CPU
extern int cpu_max_temp;
// the colors for the CPU bar and graph
extern gfx::rgba_pixel<32> cpu_colors[];
// the buffers hold the graph data for the GPU
extern buffer_t gpu_buffers[];
// the array holds the bar/label data for the GPU
extern float gpu_values[];
// the max temperature received for the GPU
extern int gpu_max_temp;
// the colors for the GPU bar and graph
extern gfx::rgba_pixel<32> gpu_colors[];

// the controls for the CPU
extern label_t cpu_label;
extern label_t cpu_temp_label;
extern canvas_t cpu_bar;
extern canvas_t cpu_graph;

// the controls for the GPU
extern label_t gpu_label;
extern label_t gpu_temp_label;
extern canvas_t gpu_bar;
extern canvas_t gpu_graph;

// the controls for the disconnected screen
extern label_t disconnected_label;
extern svg_box_t disconnected_svg;

extern void main_screen_init();
extern void disconnected_screen_init();