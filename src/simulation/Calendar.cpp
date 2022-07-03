#include "Calendar.h"

#include <iostream>

namespace fsim {
    namespace simulation {
        Calendar::Calendar() {
            std::cout << "Calendar - Created\n";
        }

        Calendar::~Calendar() {
            std::cout << "Calendar - Destroyed\n";
        }


        void Calendar::Increment(int amount, Duration duration) {
            switch (duration) {
                case Minute:
                    this->IncrementMinute(amount);
                    break;
                case Hour:
                    this->IncrementHour(amount);
                    break;
                case Day:
                    this->IncrementDay(amount);
                    break;
                case Month:
                    this->IncrementMonth(amount);
                    break;
                case Year:
                    this->IncrementYear(amount);
                    break;
            }
        }

        void Calendar::IncrementMinute(int amount){}
        void Calendar::IncrementHour(int amount){}
        void Calendar::IncrementDay(int amount){}
        void Calendar::IncrementMonth(int amount){}
        void Calendar::IncrementYear(int amount){}


    }
}