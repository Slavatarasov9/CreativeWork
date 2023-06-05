#ifndef GOODS_H
#define GOODS_H

#include <QWidget>

namespace Ui {
class Goods;
}

class Goods : public QWidget
{
    Q_OBJECT

public:
    explicit Goods(QWidget *parent = nullptr);
    ~Goods();

private slots:
    void on_Add_clicked();

    void on_check_clicked();

    void on_order_clicked();

private:
    Ui::Goods *ui;
};

#endif // GOODS_H
