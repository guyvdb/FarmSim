#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include <imgui.h>
#include <imgui-SFML.h>


#include <SFML/Graphics.hpp>
#include <Game.h>
#include <GameState.h>

namespace fsim {

    class MainMenuState : public GameState {
        public:
            MainMenuState(Game *game);
            virtual void draw(sf::Time dt);
            virtual void update(sf::Time dt);
            virtual void handleInput();

        private:
            sf::View mView;


            sf::CircleShape mCircle;

    };


}


#endif
