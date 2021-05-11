#include "home.h"
#include "Roster.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Roster roster;
    Home w(nullptr, &roster);
    w.show();
    return a.exec();
}
