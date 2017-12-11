#include "tcp_slave_connection.h"
#include <sys/socket.h>
#include <sys/types.h>

tcp_slave_connection::tcp_slave_connection(int sock_client, endpoint* ep_client)
    : slave_connection(sock_client, ep_client)
{
    std::cout << "tcp_slave_connection" << std::endl;
}

tcp_slave_connection::~tcp_slave_connection()
{

    std::cout << "~tcp_slave_connection" << std::endl;
}

void tcp_slave_connection::send_msg(const std::vector<ubyte>& buf)
{
    send(sock_client_, buf.data(), buf.size(), MSG_NOSIGNAL);
}

std::vector<ubyte> tcp_slave_connection::recv_msg(std::size_t size)
{
    std::vector<ubyte> buf(size);
    recv(sock_client_, buf.data(), size, MSG_NOSIGNAL);
    return buf;
}



