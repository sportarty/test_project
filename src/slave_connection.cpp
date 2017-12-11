#include <slave_connection.h>
#include <iostream>

slave_connection::slave_connection(int sock_client, endpoint* ep_client)
    : sock_client_(sock_client), ep_client_(ep_client)
{
    std::cout << "slave_connection" << std::endl;
}

slave_connection::~slave_connection()
{
    shutdown(sock_client_, SHUT_RDWR);
    delete ep_client_;
    std::cout << "~slave_connection;" << std::endl;
}
