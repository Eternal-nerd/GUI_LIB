// TEST application for the GUI "library"

#include <SDL3/SDL_main.h>

#include "gui.h"

int main(int argc, char** argv) {
	printf("main function invocation\n");

	// create a pointer to a gui struct and config filename
	const char* filename = "../config/default.cfg";
	gui_p gui_pointer = NULL;

	// init 
	if (!init_gui(&gui_pointer, filename)) {
		printf("ERROR: failed to initialize GUI\n");
		return -1;
	}
	
	if (gui_pointer == NULL) {
		printf("ERROR: gui_pointer is NULL\n");
		return -1;
	}

	// DO STUFF HERE BEFORE RUNNING, if u want

	// main loop
	if (!run_gui(gui_pointer)) {
		printf("ERROR: failed to run GUI\n");
		return -1;
	}

	// after running, destroy
	if (!destroy_gui(&gui_pointer)) {
		printf("ERROR: failed to destroy GUI\n");
		return -1;
	}

	if (gui_pointer != NULL) {
		printf("ERROR: GUI ptr is not NULL\n");
		return -1;
	}

	printf("main function exit success\n");
	return 0;
}


