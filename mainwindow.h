
/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <help.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void keyPressEvent(QKeyEvent *key);

    Help help;

public slots:

    void show_help();

private:
    Ui::MainWindow *ui;

    QMessageBox msgBox;
    int ret;
};

#endif // MAINWINDOW_H
