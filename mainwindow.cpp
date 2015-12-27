#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}
void MainWindow::keyPressEvent(QKeyEvent* event){
    static int Index_Dede = 0;
    static bool Op_Inc = true;
    if(event->key() == Qt::Key_Up){
        this->setWindowTitle("Dede");
        if(Index_Dede>1){
            --Index_Dede;
            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://Image/Dede_1-"+ QString::number(Index_Dede) +".png);background-repeat:no-repeat;}");
        }
    }
    if(event->key() == Qt::Key_Down){
        this->setWindowTitle("Dede");
        if(Index_Dede<11){
            ++Index_Dede;
            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://Image/Dede_1-"+ QString::number(Index_Dede) +".png);background-repeat:no-repeat;}");
        }
    }
    if(event->key() == Qt::Key_I){
        this->setWindowTitle("Inc");
        if(Op_Inc){
            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://Image/Inc_1-1.png);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }else{
            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }
    }
    if(event->key() == Qt::Key_P){
        this->setWindowTitle("Popo");
        if(Op_Inc){
            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://Image/Popo_1-1.png);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }else{
            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }
    }
    if(event->key() == Qt::Key_T){
        this->setWindowTitle("Touch_1");

            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://Image/Touch_1-1.png);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }
    if(event->key() == Qt::Key_R){
        this->setWindowTitle("Touch_2");

            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://Image/Touch_1-2.png);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }
    if(event->key() == Qt::Key_Q){
//        this->setWindowTitle("N");

            ui->centralWidget->setStyleSheet("#centralWidget{background-image: url(://);background-repeat:no-repeat;}");
            Op_Inc = !Op_Inc;
        }

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_Drag = true;
        m_DragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_Drag && (event->buttons() && Qt::LeftButton))
    {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_Drag=false;
}
