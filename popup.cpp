//-----------------------------------------------------
// Title: popup
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class is for popup operation.
//-----------------------------------------------------
#include "popup.h"
#include "ui_popup.h"
#include <QObject>

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
}

Popup::~Popup()
{
    delete ui;
}
