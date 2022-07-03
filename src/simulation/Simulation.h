#ifndef SIMULATION_H
#define SIMULATION_H

#include "../story/Log.h"
#include "../agent/Agent.h"
#include "Calendar.h"
#include <vector>
#include <thread>

namespace fsim {

    namespace simulation {
    
    


        // Simulator runs on a seperate thread 
        class Simulation {

            public:

                Simulation(story::Log *log, int tickFrequencyMilliseconds, int tickWorldMinutes);
                ~Simulation();

                // Add an agent to the simulation
                void AddAgent(agent::Agent *agent);


                // Retire an agent from the simulation 
                void DeleteAgent(agent::Agent *agent);


                void Start();
                void Stop();
                void Pause();
                bool IsPaused() { return this->mPaused; }
                bool IsRunning() { return this->mRunning; }

            private:
                void Run();
                void Tick(Calendar *calendar);


            private:
                int mTickWorldMinutes;
                int mTickFrequencyMilliseconds;
                bool mRunning;
                bool mPaused;
                Calendar *mCalendar;
                story::Log* mStoryLog;
                std::vector<agent::Agent*> mAgents;
                std::thread *mThread;


        };
    }
}


#endif
