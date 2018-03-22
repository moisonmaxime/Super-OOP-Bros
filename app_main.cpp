#include "App.h"

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
    App* myApp = new App("Super OOP Bros", 50, 50, 1600, 900);

	// Start the app
    myApp->run();
}
