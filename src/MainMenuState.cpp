
#include <MainMenuState.h>
#include <GamePlayState.h>
#include <SFML/Graphics.hpp>

#include <iostream>


namespace fsim {

    MainMenuState::MainMenuState(Game *game) : mCircle(100.0f) {
        this->mGame = game;
        sf::Vector2f pos = sf::Vector2f(this->mGame->window()->getSize());
        this->mView.setSize(pos);
        pos *= 0.5f;
        this->mView.setCenter(pos);


        this->mCircle.setFillColor(sf::Color::Green);



        std::cout << "MainMenuState -> Constructed\n";
    }

    void MainMenuState::draw(sf::Time dt) {
        this->mGame->window()->setView(this->mView);
        this->mGame->window()->clear(sf::Color::Black);


        // Draw SFML Graphics
        this->mGame->window()->draw(this->mCircle);


        // Render the GUI
        ImGui::SFML::Render(*this->mGame->window());
    }

    void MainMenuState::update(sf::Time dt) {



        // Update the GUI
        ImGui::SFML::Update(*this->mGame->window(), dt);


       // ImGui::ShowDemoWindow();


        auto dialog = ImGui::Begin("Dialog Title");
    

        if(ImGui::Button("New Game")) {
            std::cout << "New Game Called\n";
            this->mGame->pushState(new fsim::GamePlayState(this->mGame));

            // this->game->pushState(new GameStateEditor(this->game));
        }
        
        
        
        if(ImGui::Button("Quit")) {
            
            std::cout << "Quit called\n";
            this->mGame->window()->close();
        }
        ImGui::End();

    }

    void MainMenuState::handleInput() {
        sf::Event event;

        

        while(this->mGame->window()->pollEvent(event)){
        
            ImGui::SFML::ProcessEvent(event);
        
            switch(event.type) {
                case sf::Event::Closed: {
                    this->mGame->window()->close();
                    break;
                }                
            }
        }
    }



    /*
    id GameStateStart::handleInput()
{
    sf::Event event;
 
    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window 
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            /* Resize the window 
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(
                    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close();
                break;
            }
            default: break;
        }
    }
 
    return;
}
*/

}
