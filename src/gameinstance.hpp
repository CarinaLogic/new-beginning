#ifndef GAMEINSTANCE_HPP
#define GAMEINSTANCE_HPP

#include <chrono>
#include <ctime>
#include <curses.h>
#include <functional>
#include <string>
#include <thread>
#include <time.h>
#include <unordered_map>

namespace gm{
    class GameInstance{
        struct timespec lastexec, now;
        double elaspedTime = 0;
        int framerate = 60;
        std::unordered_map<std::string,std::string> assetMap;
        public:
        GameInstance(){}
        virtual void tick() = 0;
        void loop();
        std::string getAsset(std::string p);
    };
}

#endif