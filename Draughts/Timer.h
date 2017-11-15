#pragma once
#include <ctime>

class Timer
    {
        public:
            static void applyTimeDelayInSeconds(double delayTime)
            {
                clock_t startTime = clock(); //Start timer
                double timePassed;
                bool flag = true;
 
                while (flag)
                {
                    timePassed = (clock() - startTime) / CLOCKS_PER_SEC;
                    // stop the timer after the delayed time has passed
                    if (timePassed >= delayTime)
                        flag = false;
                }
 
            }
        private:
            Timer() = delete;
    };