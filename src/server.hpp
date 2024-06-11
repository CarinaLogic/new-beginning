#ifndef SERVER_HPP
#define SERVER_HPP

#include "gameinstance.hpp"
#include <iostream>
namespace gm {
    class Server : public GameInstance{
        public:
        void tick(){
            std::cout << "Server is working!" << std::endl;
        }
    };
}

#endif