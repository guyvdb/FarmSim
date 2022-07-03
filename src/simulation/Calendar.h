#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <vector>

namespace fsim {
    namespace simulation {




        class Calendar {
        public:

            enum Duration {
                Minute,
                Hour, 
                Day,
                Month,
                Year
            };

        public:
            Calendar();
            ~Calendar();

            void Increment(int amount, Duration duration);

        private:
            void IncrementMinute(int amount);
            void IncrementHour(int amount);
            void IncrementDay(int amount);
            void IncrementMonth(int amount);
            void IncrementYear(int amount);
            
            

        private:
            int mDay;
            int mMonth;
            int mYear;

            int mHour;
            int mMinute;

            

            std::vector<std::string> mMonths{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};



        };
    }
}

#endif