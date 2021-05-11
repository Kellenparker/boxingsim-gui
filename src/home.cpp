#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent, Roster *rost)
    : QMainWindow(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
    static const int columns = 5;
    static const int rows = 10;
    model = new QStandardItemModel(rows,columns,this);

    weightClass = 0;

    // Attach the model to the view
    ui->fighterTable->setModel(model);
    ui->fighterTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->fighterTable->setColumnWidth(0, 200);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Weight Class"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Overall"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Next Fight"));
    generateTable(rows, columns, rost);
}

void Home::generateTable(int maxRows, int maxCols, Roster *rost)
{

    // Generate data
    for(int row = 0; row < maxRows; row++)
    {
        Fighter *current = rost->getFighter(weightClass,row);
        for(int col = 0; col < maxCols; col++)
        {
            QModelIndex index = model->index(row,col,QModelIndex());
            if (col == 0)
                model->setData(index,current->GetName().c_str());
            else if (col == 1)
                model->setData(index,current->GetAttribute(6,false,0));
            else if (col == 2)
                model->setData(index,current->GetWeight());
            else if (col == 3)
                model->setData(index,current->overall);

        }
    }
}

Home::~Home()
{
    delete ui;
}

