#ifndef PortSetBox_H
#define PortSetBox_H

#include <QDialog>

namespace Ui {
class PortSetBox;
}

class PortSetBox : public QDialog
{
    Q_OBJECT

public:
    explicit PortSetBox(QWidget *parent = nullptr);
    ~PortSetBox();

private:
    Ui::PortSetBox *ui;
};

#endif // PortSetBox_H
