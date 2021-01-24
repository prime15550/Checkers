//-----------------------------------------------------
// Title: file
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class is for ui design.
//-----------------------------------------------------
#include "file.h"
#include "ui_file.h"

File::File(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);
}

File::~File()
{
    delete ui;
}
