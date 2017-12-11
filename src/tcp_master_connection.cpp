#include "tcp_master_connection.h"
#include "sys/socket.h"
#include "endpoint_ipv4.h"
#include <iostream>
#include <tcp_slave_connection.h>
#include <memory>

tcp_master_connection::tcp_master_connection(std::unique_ptr<endpoint>& ep)
    : tcp_master_connection() // делигирующий конструктор С++11
// для безопасности искулючений в конструкторе
{
    if(!ep) throw std::logic_error("nullptr param");
    ep_ = std::move(ep);

    create_socket();
    bind_socket();
    listen_socket();
}

tcp_master_connection::tcp_master_connection()
    : master_connection() { }

tcp_master_connection::~tcp_master_connection()
{
    shutdown(socket_, SHUT_RDWR);
    std::cout<< "~tcp_master_connection()" <<std::endl;
}

void tcp_master_connection::create_socket()
{
    socket_ = socket(ep_->get_domain(), ep_->get_type(), ep_->get_protocol());
    if(socket_ <= 0) throw std::runtime_error("Socket create error!");
}

void tcp_master_connection::bind_socket()
{
    const sockaddr* sa = ep_->get_sockaddr();
    if(!sa) throw std::logic_error("null ptr result");

    if(bind(socket_, sa, *ep_->get_sockaddr_len()) != 0)
        throw std::runtime_error("Bind error!");
}

void tcp_master_connection::listen_socket()
{
    if(listen(socket_, SOMAXCONN) != 0)
        throw std::runtime_error("Listen error");
}

slave_connection* tcp_master_connection::wait_connect()
{
    endpoint* slave_ep = new endpoint_ipv4();
    int slave_socket = accept(socket_, const_cast<sockaddr*>(slave_ep->get_sockaddr()),
                                  const_cast<socklen_t*>(slave_ep->get_sockaddr_len()));
    slave_connection* new_connection = new tcp_slave_connection(slave_socket, slave_ep);
    return new_connection;
}
