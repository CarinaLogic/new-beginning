
#include "client.hpp"
#include "server.hpp"
#include <chrono>
#include <ctime>
#include <curses.h>
#include <thread>
#include <time.h>

gm::Client client;
gm::Server server;
std::thread tclient, tserver;
int main(){
    client = gm::Client();
    server = gm::Server();
    tclient = std::thread(&gm::Client::loop,client);
    tserver = std::thread(&gm::Server::loop,server);
}
