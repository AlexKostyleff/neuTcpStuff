#include <QCoreApplication>
#include "ClientH.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client myclient ;
    myclient.connectToHost("127.0.0.1");
    return a.exec();
}
