#include "master_connection.h"

#include <iostream>

master_connection::master_connection()
    : ep_(nullptr), socket_(0)
{
    std::cout<< "master_connection()" << std::endl;
}
