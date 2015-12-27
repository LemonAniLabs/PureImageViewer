#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    virtual void keyPressEvent(QKeyEvent* event);
    bool m_Drag; //记录鼠标是否按下
        QPoint m_DragPosition;//记录鼠标位置
        //重写三个鼠标事件来实现窗口移动
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
