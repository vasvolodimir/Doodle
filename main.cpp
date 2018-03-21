#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller;
    controller.getMainScreen()->show();

    return a.exec();
}
