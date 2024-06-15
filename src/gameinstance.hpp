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

namespace gm {
    class Path{
        public:
        std::string ns= "core";
        std::string type;
        std::string id;
        std::string getFilePath(){
            std::string s;
            s.append("assets/").append(ns).append("/").append(type).append("/").append(id);
            return s;
        }
        bool operator==(const Path&) const = default;
    };
}
template<> struct std::hash<gm::Path>{
    std::size_t operator()(const gm::Path& s) const noexcept {
        std::size_t h1 = std::hash<std::string>{}(s.ns);
        std::size_t h2 = std::hash<std::string>{}(s.type);
        std::size_t h3 = std::hash<std::string>{}(s.id);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};
namespace gm{
    class GameInstance{
        struct timespec lastexec, now;
        double elaspedTime = 0;
        int framerate = 60;
        std::unordered_map<Path,std::string> assetMap;
        public:
        GameInstance();
        virtual void tick();
        void loop();
        std::string getAsset(Path p);
    };
}

#endif