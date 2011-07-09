#include "autozalent.h"
#include "ui_autozalent.h"

AutoZalent::AutoZalent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutoZalent)
{
    ui->setupUi(this);
}

AutoZalent::~AutoZalent()
{
    delete ui;
}
