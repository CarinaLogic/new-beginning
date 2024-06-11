#ifndef GAMEINSTANCE_HPP
#define GAMEINSTANCE_HPP

#include <chrono>
#include <ctime>
#include <curses.h>
#include <thread>
#include <time.h>
namespace gm {
    class GameInstance{
        struct timespec lastexec, now;
        double elaspedTime = 0;
        int framerate = 60;
        public:
        void tick();
        void loop();
    };
}


#endif