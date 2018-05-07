#include "Game.hpp"
#include <iostream>

extern bool powerupEnabled;
//#define DEFAULT_SPEED 0.01
//#define GRAVITY -0.002

#define CHARACTER_IMAGE "images/flappy2.png"
#define DEAD_CHARACTER_IMAGE "images/fireball.bmp"
#define GROUND_IMAGE "ground.fw.bmp"
#define BACKGROUND_IMAGE "images/bg.png"

static Game* singleton;

Game::Game() {
    singleton = this;
    frame = 0;
    bg = new Background(BACKGROUND_IMAGE);
    gr = new Ground(GROUND_IMAGE);
    physics = new PhysicsController(DEFAULT_GRAVITY);
    player = new Character(CHARACTER_IMAGE, DEAD_CHARACTER_IMAGE, -0.5, 0.6);
    speed = DEFAULT_SPEED;
    pipes.push_back(new Pipe(1, 0.4, 0.6));
    pipes.push_back(new Pipe(2+WIDTH, 0.6, 0.6));
    pipes.push_back(new Pipe(3+WIDTH, -0.5, 0.6));
    powerups.push_back(new PowerUP(1, 0.4, 0.25));
    isPlaying = true;
}

void Game::jumpPress() {
    player->jump();
}

void Game::calculateNextFrame() {
    physics->applyforces(player);
    bg->incProgress(speed);
    gr->incProgress(speed);
    player->calculateNextFrame();

    if (player->getMinY() < -1)
        this->endGame();

    for (auto it = pipes.cbegin(); it != pipes.cend(); it++) {
        (*it)->calculateNextFrame();
        if ((*it)->collidesWith(player))
            this->endGame();
      }

    for (auto it = powerups.cbegin(); it != powerups.cend(); it++) {
      (*it)->calculateNextFrame();
      if ((*it)->collidesWith(player))
        powerupEnabled = true;
        cout << "Power UP: " << powerupEnabled << '\n';
    }

}

void Game::restart() {
    int i = 1;
    for (int i=0; i<3; i++)
        pipes[i]->setX((i+1+WIDTH));
    player->reset();
    isPlaying = true;
}

void Game::resume() {
    isPlaying = true;
    
}

void Game::pause() {
    isPlaying = false;
}

void Game::endGame() {
    player->die();
    isPlaying = false;
}

void Game::draw(){
    if (isPlaying) {
        calculateNextFrame();
        bg->draw();
        for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
            (*it)->draw();
        for (auto it = powerups.cbegin(); it != powerups.cend(); it++)
            (*it)->draw();
        player->draw();
        gr->draw();
        //bg->incProgress(speed);
        //gr->incProgress(speed);
    } else {
        bg->draw();
        for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
            (*it)->draw();
        player->draw();
        gr->draw();

    }
}
