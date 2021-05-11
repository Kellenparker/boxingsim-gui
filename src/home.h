#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QComboBox>
#include "Roster.h"
#include "time.h"
#include "Fighter.h"
#include <vector>

#define ROWS 100
#define COLUMNS 5

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT
private:
    void generateTable();

public:
    Home(QWidget *parent = nullptr, Roster *rost = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    QStandardItemModel *model;
    Roster *roster;
    int weightClass;

};
#endif // HOME_H
