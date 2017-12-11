#include "endpoint.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> //IPPROTO_TCP

struct endpoint::impl
{
    std::string ip_;     // _ поля класса в UNIX стиле
    std::uint16_t port_;
};

endpoint::endpoint(const std::string& ip, std::uint16_t port) 
    : d_(std::make_unique<impl>())
{
    if(!d_) return;

    d_->ip_ = ip;
    d_->port_ = port;

    std::cout<<"endpoint"<<std::endl;
} //список инициализацции

uint16_t endpoint::get_port() const { return d_->port_; }
std::string endpoint::get_ip() const { return d_->ip_; }

endpoint::endpoint(const endpoint& rhs) : d_(nullptr)
{
    if(rhs.d_)
    {
        d_->ip_ = rhs.d_->ip_;
        d_->port_ = rhs.d_->port_;
    }
}

endpoint& endpoint::operator =(const endpoint& rhs)
{
    if(!rhs.d_) d_.reset();
    else if(!d_)
    {
        d_ = std::unique_ptr<impl>();
        d_->ip_= rhs.d_->ip_;
        d_->port_ = rhs.d_->port_;
    }
    else if(this != &rhs)
    {
       *d_ = *rhs.d_;
    }
}

endpoint::endpoint(endpoint&& rhs) = default;

endpoint& endpoint::operator=(endpoint&& rhs) = default;

endpoint::~endpoint()
{
    std::cout<<"~endpoint"<<std::endl;
}

