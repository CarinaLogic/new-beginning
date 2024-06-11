#include "gameinstance.hpp"


void gm::GameInstance::loop(){
    while (true){
        clock_gettime(CLOCK_MONOTONIC, &now);
        elaspedTime = now.tv_sec - lastexec.tv_sec;
        elaspedTime += (double)(now.tv_nsec - lastexec.tv_nsec) / 1000000000;
        if (elaspedTime >= 1.0/framerate){
            tick();
            lastexec = now;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}
void gm::GameInstance::tick(){

}
