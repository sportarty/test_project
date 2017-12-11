#ifndef _TCP_SLAVE_CONNECTION_H_
#define _TCP_SLAVE_CONNECTION_H_

#include "slave_connection.h"

class tcp_slave_connection : public slave_connection
{
public:
    tcp_slave_connection(int sock_client, endpoint* ep_client);
    ~tcp_slave_connection();

    void send_msg(const std::vector<ubyte>&) override;
    std::vector<ubyte> recv_msg(std::size_t) override;
};

#endif //_TCP_SLAVE_CONNECTION_H_
