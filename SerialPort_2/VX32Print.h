#ifndef VX32PRINT_H
#define VX32PRINT_H

#include <QDebug>
#include <QString>


class VX32Print
{
public:
    VX32Print();
    ~VX32Print();
    void T_clean();
    void T_clean_marker();
    void version();
    void read();
    void readline();
    void start();
    void stop();
    void setClock();
    void state();
    void status();
    void varList();
    void messageList();
    void choose();
private:
//    serial::Serial mSerital;
    std::string mData;
};

#endif // VX32PRINT_H
