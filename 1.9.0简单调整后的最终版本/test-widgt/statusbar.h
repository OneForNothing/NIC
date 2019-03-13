#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>

namespace Ui {
class statusbar;
}

class statusbar : public QWidget
{
    Q_OBJECT

public:
    explicit statusbar(QWidget *parent = 0);
    ~statusbar();

private:
    Ui::statusbar *ui;
};

#endif // STATUSBAR_H








