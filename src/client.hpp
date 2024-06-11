#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "gameinstance.hpp"
#include <iostream>
namespace gm {
    class Client: public GameInstance{
        public:
        void tick(){
            std::cout << "Client is working!" << std::endl;
        }
    };
}

#endif