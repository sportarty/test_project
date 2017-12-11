#ifndef _SLAVE_CONNECTION_H_
#define _SLAVE_CONNECTION_H_

#include "types.h"
#include <endpoint.h>
#include <vector>

class slave_connection
{
public:
    slave_connection(int sock_client, endpoint* ep_client);
    virtual ~slave_connection();

    virtual void send_msg(const std::vector<ubyte>&) = 0;
    virtual std::vector<ubyte> recv_msg(std::size_t) = 0;

    //TODO: дальнейшаяя реализация
    //std::string get_ip() const;
    //std::uint16_t get_port() const;
    slave_connection(const slave_connection&) = delete;
    slave_connection& operator =(const slave_connection&) = delete;
protected:
    int sock_client_;
    endpoint* ep_client_;
};

#endif //_SLAVE_CONNECTION_H_
