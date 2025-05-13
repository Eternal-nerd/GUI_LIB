#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// defines/typedefs
#define MAX_NAME_LENGTH 100

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;
typedef float f32;
typedef double f64;
typedef int b32;
typedef bool b8;

// structs
typedef struct gui_config {
	char window_name[MAX_NAME_LENGTH];
	u32 window_width;
	u32 window_height;
	char app_name[MAX_NAME_LENGTH];

} gui_config;

typedef struct gui {
	gui_config config;

	b8 running;
	b8 visible;

	// SDL stuff
	SDL_Event sdl_event;
	SDL_Window* sdl_window_ptr;

	// Vulkan stuff
	// device/queues
	VkDebugUtilsMessengerEXT vk_debug_messenger;
	VkInstance vk_instance;
	VkPhysicalDevice vk_physical_device;
	VkDevice vk_device;
	VkSurfaceKHR vk_surface;
	VkQueue vk_graphics_queue;
	VkQueue vk_present_queue;

	// swapchain
	u32 image_index;
	VkSwapchainKHR vk_swap_chain;
	// TODO: dynamic array of swapchain images std::vector<VkImage> swapChainImages_;
	VkFormat vk_swap_chain_image_format;
	VkExtent2D vk_swap_chain_extent;
	// TODO: dynamic array std::vector<VkImageView> swapChainImageViews_;
	// TODO: dynamic array std::vector<VkFramebuffer> swapChainFramebuffers_;
	VkImage vk_depth_image;
	VkDeviceMemory vk_depth_image_memory;
	VkImageView vk_depth_image_view;

	// graphics pipeline/descriptor stuff
	VkRenderPass vk_renderpass;
	VkDescriptorPool vk_descriptor_pool;
	VkDescriptorSetLayout vk_descriptor_set_layout;
	VkDescriptorSet vk_descriptor_set;
	VkPipelineLayout vk_pipeline_layout;
	VkPipelineCache vk_pipeline_cache;
	VkPipeline vk_pipeline;

	// buffers
	VkBuffer vk_vertex_buffer;
	VkDeviceMemory vk_vertex_buffer_memory;
	VkBuffer vk_index_buffer;
	VkDeviceMemory vk_index_buffer_memory;

	// command stuff
	u32 current_frame;
	VkCommandPool vk_command_pool;
	VkCommandBuffer vk_command_buffer; // TODO make an array for multiple command buffers

	// Vulkan synchronization ------------------------===< TODO
	//std::vector<VkSemaphore> imageAvailableSemaphores_;
	//std::vector<VkSemaphore> renderFinishedSemaphores_;
	//std::vector<VkFence> inFlightFences_;

} gui, *gui_p, **gui_pp;

// init/cleanup functions
b8 init_gui(gui_pp gui_ptr_ptr, const char* config_filename);
b8 destroy_gui(gui_pp gui_ptr_ptr);

// run/loop function
b8 run_gui(gui_p gui_ptr);

// interaction functions, to modify elements, etc.


// helper functions, probbly not to be used by app code
b8 get_config_string(const char* config_filename, const char destination[MAX_NAME_LENGTH], const char config_object[MAX_NAME_LENGTH], const char config_attribute[MAX_NAME_LENGTH]);
