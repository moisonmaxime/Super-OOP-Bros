#include "App.hpp"
#include "Game.hpp"
#include <time.h>

using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    super_OOP_Bros = Game();
}

void App::draw() {
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to sky blue
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    super_OOP_Bros.draw();
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
    redraw();
}

void App::mouseDown(float x, float y) {
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == ' ')
        super_OOP_Bros.jumpPress();
    if (key == 3 || key == 'q' || key == 27)
        exit(0);
    if (key == 'r'){
        if(super_OOP_Bros.player->isDead()){
            super_OOP_Bros.restart();
        }
        else{
            super_OOP_Bros.resume();
        }
    }
    if (key == 'p')
        super_OOP_Bros.pause();
}

void App::keyUp(unsigned char key) { }
