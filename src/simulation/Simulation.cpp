
#include "Simulation.h"
#include "Calendar.h"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <ostream>
#include <thread>
#include <iostream>
#include <chrono>


namespace fsim {

    namespace simulation {



        Simulation::Simulation(story::Log *storyLog, int tickFrequencyMilliseconds, int tickWorldMinutes) : 
            mStoryLog(storyLog), mTickFrequencyMilliseconds(tickFrequencyMilliseconds), mTickWorldMinutes(tickWorldMinutes), 
            mRunning(false), mThread(nullptr) {
            this->mCalendar = new Calendar();
            std::cout << "Simulation -> Constructed\n";
        }

        Simulation::~Simulation() {
            delete this->mCalendar;
        }

        void Simulation::AddAgent(agent::Agent *agent) {

        }

        void Simulation::DeleteAgent(agent:: Agent *agent) {

        }

        void Simulation::Start() {
            std::cout << "Simulation -> Start\n";
            if(this->mRunning) {
                this->Stop();
            }

            this->mRunning = true;
            this->mThread = new std::thread(&Simulation::Run, this);


        }


        void Simulation::Stop() {
            std::cout << "Simulation -> Stop\n";
            if(!this->mRunning) {
                return;
            }
            this->mRunning = false;
            this->mThread->join();
            delete this->mThread;      
            this->mThread = nullptr;  
        }

        void Simulation::Run() {
            sf::Clock clock;
            std::cout << "Simulation -> Run\n";



            // get the start time .... 



            while(this->mRunning) {
                // start timer 
                sf::Time dt = clock.restart();

                // do simulation here 
                std::cout << "[simulate]\n" << std::flush;

                // how long did simulation take 
                

                // sleep if needed
                int delta = this->mTickFrequencyMilliseconds - dt.asMilliseconds();
                std::cout << "simulation duration: " << dt.asMicroseconds() << "us" << ", sleep: " << delta << "ms\n" << std::flush;
                std::cout << "dt=" << dt.asSeconds() << "s, " 
                                   << dt.asMilliseconds() << "ms, " 
                                   << dt.asMicroseconds() << "us " 
                                   
                << "\n" << std::flush;
                if(delta > 0) {
                    std::this_thread::sleep_for (std::chrono::milliseconds(delta));
                }
                
            }

            std::cout << "Simulation -> Run/End\n";
        }
    }
}