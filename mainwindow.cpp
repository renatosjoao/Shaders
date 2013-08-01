
/*
* All right is reserved by Renato Stoffalette Joao
*
* renatosjoao@gmail.com
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::show_help()
{
    this->help.show();
}


void MainWindow::keyPressEvent(QKeyEvent *key)
{
    switch(key->key()){

    case Qt::Key_Escape: // Escape key
      //  msgBox.setText("The document has been modified.");
        msgBox.setText("Deseja realmente sair?");
        msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
        ret = msgBox.exec();
         switch (ret) {
                    case QMessageBox::No:
                           break;
                    case QMessageBox::Yes:
                                exit(EXIT_SUCCESS);
                                break;
         }
       // std::cout << "Tecla ESC" <<std::endl;
    case Qt::Key_Up:
        break;
    case Qt::Key_Down:
        break;
    case Qt::Key_Left:
        break;
    case Qt::Key_Right:
        break;
    }
}
