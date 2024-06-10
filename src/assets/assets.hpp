#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <string>
#include <unordered_map>
namespace assets {
    class Path {

    }
    class AssetManager {
        public:
        std::unordered_map<Path,std::string> map;
        std::string get(Path p){
            
        } 
    }
}


#endif