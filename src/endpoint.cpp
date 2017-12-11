#include "endpoint.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> //IPPROTO_TCP

endpoint::endpoint(const std::string& ip, std::uint16_t port) 
    : ip_(ip), port_(port)
{
    std::cout<<"endpoint"<<std::endl;
} //список инициализацции

uint16_t endpoint::get_port() const { return port_; }
std::string endpoint::get_ip() const { return ip_; }

endpoint::~endpoint()
{
    std::cout<<"~endpoint"<<std::endl;
}
