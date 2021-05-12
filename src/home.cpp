#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent, Roster *rost, Time *time)
    : QMainWindow(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
    model = new QStandardItemModel(ROWS,COLUMNS,this);

    roster = rost;
    timeptr = time;

    connect(ui->advanceBtn, &QPushButton::clicked, [=]() {

        std::cout << "time keeps moving";
        timeptr->advance();
        generateTable();

    });

    weightClass = ui->comboBox->currentIndex();
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [=](int index){

        weightClass = index;
        generateTable();

    });

    // Attach the model to the view
    ui->fighterTable->setModel(model);
    ui->fighterTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->fighterTable->setColumnWidth(0, 200);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Record"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Overall"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Next Fight"));
    generateTable();
}

void Home::generateTable()
{

    // Generate data
    for(int row = 0; row < ROWS; row++)
    {
        Fighter *current = roster->getFighter(weightClass,row);
        for(int col = 0; col < COLUMNS; col++)
        {
            QModelIndex index = model->index(row,col,QModelIndex());
            if (col == 0)
                model->setData(index,current->GetName().c_str());
            else if (col == 1)
                model->setData(index,current->GetAttribute(6,false,0));
            else if (col == 2)
                model->setData(index,current->GetRecord().c_str());
            else if (col == 3)
                model->setData(index,current->overall);

        }
    }
}

void Home::advanceTime()
{
    std::cout << "time keeps moving";
    timeptr->advance();
    generateTable();
}

Home::~Home()
{
    delete ui;
}

