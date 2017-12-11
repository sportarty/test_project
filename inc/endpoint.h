#ifndef _ENDPOINT_H_
#define _ENDPOINT_H_

#include <sys/socket.h>

#include <string>
#include <iostream>

class endpoint
{
public:
    endpoint(const std::string& ip, std::uint16_t port);
    virtual ~endpoint();

    virtual int get_domain() const = 0;
    virtual int get_type() const = 0;
    virtual int get_protocol() const = 0;
    virtual const struct sockaddr* get_sockaddr() const = 0;
    virtual const socklen_t* get_sockaddr_len() const = 0;

    uint16_t get_port() const;
    std::string get_ip() const;

protected:
    std::string ip_; // _ поля класса в UNIX стиле
    std::uint16_t port_;
};

#endif //_ENDPOINT_H_
