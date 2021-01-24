#ifndef POPUP_H
#define POPUP_H
#include <QObject>
#include <QDialog>

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();

private:
    Ui::Popup *ui;
};

#endif // POPUP_H
