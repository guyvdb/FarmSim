#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "Game.h"

#include <SFML/System/Time.hpp>


namespace fsim {


    class GameState {
        public:

            virtual void draw(sf::Time dt) = 0;
            virtual void update(sf::Time dt) = 0;
            virtual void handleInput() = 0;


        protected:
            Game *mGame;

    };

}

#endif