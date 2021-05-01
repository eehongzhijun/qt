#include "PortSetBox.h"
#include "ui_PortSetBox.h"

PortSetBox::PortSetBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortSetBox)
{
    ui->setupUi(this);
}

PortSetBox::~PortSetBox()
{
    delete ui;
}
