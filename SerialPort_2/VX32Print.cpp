#include "VX32Print.h"
#include "common.h"


VX32Print::VX32Print()
    : mData{""}
{

}

VX32Print::~VX32Print()
{
}

void VX32Print::T_clean()
{
    qInfo() << "Cleanning print head";
    mData = "<ESC>INST<FS>Production Line 1<ETB>";
    mSERIAL->write(mData);
    mData = "<ESC>T_CLEAN<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::T_clean_marker()
{
    qInfo() << "Cleanning print head Marker";
    mData = "<ESC>INST<FS>Production Line 1<ETB>";
    mSERIAL->write(mData);
    mData = "<ESC>T_CLEAN_MARKER<FS>Operator Side<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::version()
{
    mData = "<ESC>VERSION<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::read()
{
    qInfo() << "VX32Print::read";
    size_t count = mSERIAL->available();
    qInfo() << QString::fromStdString(mSERIAL->read(count));
}

void VX32Print::readline()
{
    return;
    qInfo() << "VX32Print::readline()";
    qInfo() << QString::fromStdString(mSERIAL->readline());
}

void VX32Print::start()
{
    qInfo() << "VX32Print::start()";
    mData = "<ESC>START<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::stop()
{
    qInfo() << "VX32Print::stop()";
    mData = "<ESC>STOP<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::setClock()
{
    qInfo() << "VX32Print::setClock()";
    mData = "<ESC>SET_CLOCK<FS>201411260838<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::state()
{
    qInfo() << "VX32Print::state()";
    mData = "<ESC>STATE<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::status()
{
    qInfo() << "VX32Print::status()";
    mData = "<ESC>STATUS<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::varList()
{
    qInfo() << "VX32Print::varList()";
    mData = "<ESC>VAR_LIST<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::messageList()
{
    qInfo() << "VX32Print::messageList()";
    mData = "<ESC>MSG_LIST<ETB>";
    mSERIAL->write(mData);
    read();
    readline();
}

void VX32Print::choose()
{
    qInfo() << "-------------------------";
    int mChoose=1;
    while (mChoose) {
        qInfo() << "1. Clean print head";
        qInfo() << "2. Clean print head Marker";
        qInfo() << "3. Start";
        qInfo() << "4. Stop";
        qInfo() << "5. set clock";
        qInfo() << "6. state";
        qInfo() << "7. status";
        qInfo() << "8. var list";
        qInfo() << "9. message list";
        qInfo() << "99. Version";
        qInfo() << "0. Exit";
        std::cin >> mChoose;
        switch (mChoose) {
        case 1:
            T_clean();
            break;
        case 2:
            T_clean_marker();
            break;
        case 3:
            start();
            break;
        case 4:
            stop();
            break;
        case 5:
            setClock();
            break;
        case 6:
            state();
            break;
        case 7:
            status();
            break;
        case 8:
            varList();
            break;
        case 9:
            messageList();
            break;
        case 99:
            version();
            break;
        case 0:
            mSERIAL->close();
            break;
        default:
            qInfo() << "Choose again.";
            break;
        }
    }
}
