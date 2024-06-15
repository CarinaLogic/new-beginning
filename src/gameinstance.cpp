#include "gameinstance.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>


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
std::string gm::GameInstance::getAsset(gm::Path p){
    std::string str;
    try {
        str = assetMap.at(p);
    } catch (std::out_of_range er) {
        std::ifstream ifile(p.getFilePath());
        std::string buf;
        if (ifile.is_open()){
            while (std::getline(ifile,buf)) {
                str.append(buf);
                if (str.find_last_of("\n") != str.length()-1){
                    str.append("\n");
                }
            }
        }
        assetMap.insert(std::make_pair(p,str));
    }
    return str;
}
