#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"

namespace fsim {

    class GamePlayState : public GameState {
        public:
            GamePlayState(Game *game);
            virtual void draw(sf::Time dt);
            virtual void update(sf::Time dt);
            virtual void handleInput();
        private:
            sf::View mGameView;
            sf::View mGuiView;

            sf::CircleShape mCircle;
    };


}


#endif
