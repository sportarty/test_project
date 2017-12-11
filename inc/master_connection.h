#ifndef _MASTER_CONNECTION_H_
#define _MASTER_CONNECTION_H_

#include "endpoint.h"
#include "slave_connection.h"

#include <memory>

class master_connection
{
public:
    master_connection();
    virtual ~master_connection() = default;

    virtual slave_connection* wait_connect() = 0;

    master_connection(const master_connection&) = delete;
    master_connection& operator=(const master_connection&) = delete;

protected:
    int socket_ = 0;
    std::unique_ptr<endpoint> ep_ = nullptr;
};

#endif //_MASTER_CONNECTION_H_
