#ifndef GAME_H
#define GAME_H


#include <stack>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/VideoMode.hpp>


#include "simulation/Simulation.h"
#include "story/Log.h"



namespace fsim {

    class GameState;



    class Game {
    public:
        Game(sf::VideoMode mode);
        ~Game();
        void run();

        sf::RenderWindow* window() { return &mWindow; };

        void pushState(GameState* state);


        void StartSimulation() { this->mSimulation->Start(); };
        void StopSimulation() { this->mSimulation->Stop(); };
        void PauseSimulation() { this->mSimulation->Pause(); };

    private:    
        
        void popState();
        void changeState(GameState* state);
        GameState* peekState();


    private:
        sf::VideoMode mMode;
        sf::RenderWindow mWindow;
        
        std::stack<GameState*> mStates;
        simulation::Simulation *mSimulation;
        story::Log *mStoryLog;

        //sf::Sprite  mPlayer;
        //sf::Texture mPlayerTexture;
        //sf::Sprite mWorld;
        //sf::Texture mWorldTexture;

        

    };
}



#endif
