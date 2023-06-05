#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "goods.h"
#include "causeofpain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_goods_clicked();

    void on_cop_clicked();

private:
    Ui::MainWindow *ui;
    Goods goods;
    CauseOfPain cop;
};
#endif // MAINWINDOW_H
