#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <Game.h>
#include <MainMenuState.h>





int main(int argc, char **argv) {
  sf::VideoMode mode =  sf::VideoMode(640, 480);
  //sf::VideoMode mode = sf::VideoMode(1920, 1080);
  fsim::Game game = fsim::Game(mode);
  game.pushState(new fsim::MainMenuState(&game));
  game.run();
  return 0;    
}


