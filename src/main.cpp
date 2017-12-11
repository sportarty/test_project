#include <iostream> // cout
#include "endpoint_ipv4.h"
#include "master_connection.h"
#include "tcp_master_connection.h"
#include <sys/socket.h> // socket
#include <sys/un.h> // memset
#include <arpa/inet.h> // sockaddr_in
#include <memory> // std::unique_ptr
#include <thread>

void client_manager(slave_connection * new_connection) {
    std::vector<ubyte> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    new_connection->send_msg(v);
    v.clear();
    v = new_connection->recv_msg(5);

    for(auto it : v) { std::cout<<it; }

    delete new_connection;
}

int main() {

    std::unique_ptr<endpoint> ep_ptr
            =  std::make_unique<endpoint_ipv4>("127.0.0.1", 8000);
    //endpoint* ep = new endpoint_ipv4("127.0.0.1", 8000);

    try
    {

        master_connection* m_connection = new tcp_master_connection(ep_ptr);
        //TODO: дальнейшее реализация
        //        m_connection->set_reusaddr();
        //        m_connection->set_timeout();
        while(1) {
        slave_connection* new_connection = m_connection->wait_connect();
        std::thread t(&client_manager, std::ref(new_connection));
        t.detach();
        }
        delete m_connection;
    }
    catch(const std::exception& ex)
    {
        std::cout<<ex.what()<<std::endl;
    }

    //delete ep;

    return 0;
}
