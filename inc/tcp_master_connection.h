#ifndef _TCP_MASTER_CONNECTION_H_
#define _TCP_MASTER_CONNECTION_H_

#include "master_connection.h"
#include "endpoint.h"

#include <memory>

class tcp_master_connection : public master_connection
{
public:
    tcp_master_connection(std::unique_ptr<endpoint> &ep);
    ~tcp_master_connection();

    virtual slave_connection* wait_connect() override;

    //запрещать копирование
private:
    tcp_master_connection();

    void create_socket();

    void bind_socket();

    void listen_socket();
};

#endif //_TCP_MASTER_CONNECTION_H
