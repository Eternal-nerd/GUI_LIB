#include "gui.h"

#define STB_IMAGE_IMPLEMENTATION

#ifdef NDEBUG
const b8 enable_validation_layers = false;
#else
const b8 enable_validation_layers = true;
#endif

/*
-----~~~~~=====<<<<<{_API_FUNCTIONS_}>>>>>=====~~~~~-----
*/
b8 init_gui(gui_pp gui_ptr_ptr, const char* config_filename) {
	printf("initializing/allocation memory for GUI\n");

	// calloc gui
	*gui_ptr_ptr = (gui_p)calloc(1, sizeof(gui));
	if (*gui_ptr_ptr == NULL) {
		printf("ERROR: failed to allocate memory for GUI\n");
		return -1;
	}

	// create a pointer for use in this function
	gui_p gui_ptr = *gui_ptr_ptr;

	printf("parsing config file\n");

	//strcpy_s(gui_ptr->config.app_name, sizeof(teststr), teststr);

	char window_name[MAX_NAME_LENGTH] = { 0 };
	b8 result = get_config_string(config_filename, window_name, "GUI_CONFIG", "window_name");

	printf("window_name gotten: %s\n", window_name);

	//printf("gui_ptr->config.app_name: %s\n", gui_ptr->config.app_name);

	/*guiptr->config.window_name;
	guiptr->config.window_width;
	guiptr->config.window_height;
	guiptr->config.app_name;*/


	return true;
}

b8 run_gui(gui_p gui_ptr) {

	return true;
}

b8 destroy_gui(gui_pp gui_ptr_ptr) {
	printf("freeing GUI\n");
	free(*gui_ptr_ptr);
	*gui_ptr_ptr = NULL;

	return true;
}



/*
-----~~~~~=====<<<<<{_HELPER_FUNCTIONS_}>>>>>=====~~~~~-----
*/
b8 get_config_string(const char* config_filename, const char destination[MAX_NAME_LENGTH], const char config_object[MAX_NAME_LENGTH], const char config_attribute[MAX_NAME_LENGTH]) {
	printf("\n");

	printf("config_filename: %s\n", config_filename);
	printf("config_object: %s\n", config_object);
	printf("config_attribute: %s\n", config_attribute);



	char* teststr = "hellow!";
	strcpy_s(destination, sizeof(teststr), teststr);

	printf("\n");
	return true;
}

