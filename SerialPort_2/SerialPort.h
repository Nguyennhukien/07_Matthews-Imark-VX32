#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "boost/asio.hpp"
#include "boost/asio/serial_port.hpp"
#include <iostream>
namespace asio = boost::asio;
using namespace std::literals;

class SerialPort
{
public:
    SerialPort();
    void test();
};

#endif // SERIALPORT_H
