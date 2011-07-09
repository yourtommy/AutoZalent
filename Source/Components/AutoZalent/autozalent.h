#ifndef AUTOZALENT_H
#define AUTOZALENT_H

#include <QMainWindow>

namespace Ui {
    class AutoZalent;
}

class AutoZalent : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutoZalent(QWidget *parent = 0);
    ~AutoZalent();

private:
    Ui::AutoZalent *ui;
};

#endif // AUTOZALENT_H
