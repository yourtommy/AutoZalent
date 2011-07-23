#include "autozalent.h"
#include "addin.h"
#include "ui_autozalent.h"

AutoZalent::AutoZalent(QWidget *pParent) :
    QMainWindow(pParent),
    ui(new Ui::AutoZalent)
{
    ui->setupUi(this);
}

AutoZalent::~AutoZalent()
{
    delete ui;
}
