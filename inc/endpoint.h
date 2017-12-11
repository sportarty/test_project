#ifndef _ENDPOINT_H_
#define _ENDPOINT_H_

#include "endpoint_traits.h"

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

    //конструктор копирования
    endpoint(const endpoint&);
    //оператор присваивания
    endpoint& operator =(const endpoint&);

    //конструктор перемещений
    endpoint(endpoint&& rhs);
    //оператор присваивания с перемещением
    endpoint& operator=(endpoint&& rhs);

protected:
    struct impl;
    std::unique_ptr<impl> d_;
};

#endif //_ENDPOINT_H_
