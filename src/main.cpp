#include "home.h"
#include "Roster.h"
#include "Time.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Roster roster;
    Time time(2021);
    Home w(nullptr, &roster, &time);
    w.show();
    return a.exec();
}
