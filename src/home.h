#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include "Roster.h"
#include "time.h"
#include "Fighter.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT
private:
    void generateTable(int maxRows, int maxCols, Roster *rost);

public:
    Home(QWidget *parent = nullptr, Roster *rost = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    QStandardItemModel *model;
    int weightClass;

};
#endif // HOME_H
