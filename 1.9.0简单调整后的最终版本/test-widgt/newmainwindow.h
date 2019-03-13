#ifndef NEWMAINWINDOW_H
#define NEWMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class newmainwindow;
}

class newmainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newmainwindow(QWidget *parent = 0);
    ~newmainwindow();

private:
    Ui::newmainwindow *ui;
};

#endif // NEWMAINWINDOW_H
