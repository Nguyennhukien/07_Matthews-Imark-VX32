#include "SerialPort.h"
#include <QDebug>

SerialPort::SerialPort()
{
    std::cout << "SerialPort::SerialPort()";
}

void SerialPort::test() {
    asio::io_service  io;
    asio::serial_port port(io);

    qInfo() << "asdf1";
    try {
        qInfo() << "asdf1";
        port.open("COM1");
    } catch (...) {
        qInfo() << "asdf2";

    }
    port.set_option(asio::serial_port_base::baud_rate(115200));
    qInfo() << "asdf3";
//    while (true) {
        boost::asio::write(port, boost::asio::buffer("\x02"
                                                     "0401032A0\x03"sv));

        //$02 $30 $34 $30 $31 $30 $33 $32 $41 $03
        std::cout << "reading" << std::endl;
        std::vector<uint8_t> obuf(10, 0);
        auto n = asio::read(port, asio::buffer(obuf));
        obuf.resize(n);

        for (int i : obuf) {
            std::cout << std::hex << std::showbase << " " << i;
        }
        std::cout << std::endl;
//    }
}
