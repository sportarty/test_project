#include "endpoint_ipv4.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> //IPPROTO_TCP
#include <cstring>


endpoint_ipv4::endpoint_ipv4(const std::string& ip, std::uint16_t port) noexcept
: endpoint(ip, port) 
{
    sa_.sin_family = get_domain();
    sa_.sin_port = htons(get_port());
    sa_.sin_addr.s_addr = inet_addr(get_ip().c_str());

    slen_ = (socklen_t)(sizeof(struct sockaddr_in));

	std::cout<<"endpoint_ipv4"<<std::endl;
}
endpoint_ipv4::endpoint_ipv4() noexcept : endpoint("", 0)
{
    slen_ = sizeof(struct sockaddr_in);
    std::memset(&sa_, 0x00, slen_);
}

endpoint_ipv4::~endpoint_ipv4()
{
	std::cout<<"~endpoint_ipv4"<<std::endl;
}

int endpoint_ipv4::get_domain() const { return AF_INET; }

int endpoint_ipv4::get_type() const { return SOCK_STREAM; }
   
int endpoint_ipv4::get_protocol() const { return IPPROTO_TCP; }

const struct sockaddr* endpoint_ipv4::get_sockaddr() const
{ return (const sockaddr*)&sa_; }

const socklen_t* endpoint_ipv4::get_sockaddr_len() const
{ return &slen_; }
