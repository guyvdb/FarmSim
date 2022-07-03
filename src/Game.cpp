
#include "Game.h"
#include "GameState.h"



#include <imgui.h>
#include <imgui-SFML.h>

namespace fsim {

        
    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */
    Game::Game(sf::VideoMode mode) : mWindow(mode, "FSIM"), mMode(mode) {
        this->mWindow.setFramerateLimit(60);
        ImGui::SFML::Init(this->mWindow);

        this->mStoryLog = new story::Log();
        this->mSimulation = new simulation::Simulation(this->mStoryLog, 1000, 10);
    }


    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */
    Game::~Game() {

        if(this->mSimulation->IsRunning()) {
            this->mSimulation->Stop();
        }

        delete this->mSimulation;

        delete this->mStoryLog;


        while(!this->mStates.empty()) {
            this->popState();
        }
    }
    

    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */
    void Game::run() {
        sf::Clock clock;



        



        while (mWindow.isOpen()) {  
            sf::Time dt = clock.restart();
           // float dt = deltaTime.asSeconds();

            if(this->peekState() == nullptr) {
                continue;
            }

            this->peekState()->handleInput();
            this->peekState()->update(dt);
            this->mWindow.clear(sf::Color::Black);
            this->peekState()->draw(dt);
            this->mWindow.display();
        }

    }

    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */
    void Game::pushState(GameState *state) {
        this->mStates.push(state);
    }

    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */
    void Game::popState() {
        delete this->mStates.top();
        this->mStates.pop();
    }

    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */               
    void Game::changeState(GameState *state) {
        if(!this->mStates.empty()) {
            this->popState();
        }

        this->pushState(state);
    }


    /* -------------------------------------------------------------
     *
     * ------------------------------------------------------------ */
    GameState* Game::peekState() {
        if(this->mStates.empty()) {
            return nullptr;
        }

        return this->mStates.top();
    }







}


