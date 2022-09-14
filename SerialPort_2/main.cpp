#include <QCoreApplication>
//#include "SerialPort.h"
#include <QDebug>
#include "api/serial.h"
#include <QString>
#include <iostream>
#include "common.h"
#include "VX32Print.h"
#include "SerialPort.h"

//using namespace serial;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "test\n";

//    SerialPort mPort;
//    mPort.test();

//    qInfo() << "mPort.test() done ";

    VX32Print mVX32;

    while (1) {
        qInfo() << "-------------------------";
        mSERIAL->scan();
        qInfo() << "Set port: ";
        std::string portCom;
        std::cin >> portCom;
        mSERIAL->setPort(portCom);
        mSERIAL->open();

        if(mSERIAL->isOpen()) {
            mVX32.choose();
        } else {
            qInfo() << "Can't connect to " << QString::fromStdString(portCom);
        }
    }



//    std::string strCOM = "COM1";
////    qInfo() << "Connecting to " << QString::fromStdString(strCOM) << "...";
//    serial::Serial mSerial(strCOM);
//    mSerial.scan();

//    qInfo() << "Set port: ";
//    std::string portCom;
//    std::cin >> portCom;
//    mSerial.setPort(portCom);
//    mSerial.open();

//    if(mSerial.isOpen()) {
//        qInfo() << "Connected to " << QString::fromStdString(strCOM);

//        int option = 0;
//        std::string data = "";
//        while (1) {
//            qInfo() << "1. Clean print head";
//            qInfo() << "2. Clean print head Marker";
//            std::cin >> option;
//            switch (option) {
//            case 1:
//                qInfo() << "Cleanning print head";
//                data = "<ESC>INST<FS>Production Line 1<ETB>";
//                mSerial.write(data);
//                data = "<ESC>T_CLEAN<ETB>";
//                mSerial.write(data);
//                break;
//            case 2:
//                qInfo() << "Cleanning print head Marker";
//                data = "<ESC>INST<FS>Production Line 1<ETB>";
//                mSerial.write(data);
//                data = "<ESC>T_CLEAN_MARKER<FS>Operator Side<ETB>";
//                mSerial.write(data);
//            default:
//                break;
//            }
//        }

//    } else {
//        qInfo() << "Can't connect to " << QString::fromStdString(strCOM);
//    }

    qInfo() << "Done";
    return a.exec();
}
