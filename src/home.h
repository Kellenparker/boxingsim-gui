#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "Roster.h"
#include "Time.h"
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
    Home(QWidget *parent = nullptr, Roster *rost = nullptr, Time *time = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    QStandardItemModel *model;
    Roster *roster;
    Time *timeptr;
    int weightClass;

private slots:
    void on_advanceBtn_clicked();

signals:

};
#endif // HOME_H
