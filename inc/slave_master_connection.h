#ifndef _TCP_MASTER_CONNECTION_H_
#define _TCP_MASTER_CONNECTION_H_

#include "master_connection.h"

class tcp_master_connection : public master_connection
{
public:
    tcp_master_connection(endpoint* ep);

    virtual connection* wait_connect() override;
};

#endif //_TCP_MASTER_CONNECTION_H
