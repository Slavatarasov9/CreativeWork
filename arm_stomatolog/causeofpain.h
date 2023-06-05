#ifndef CAUSEOFPAIN_H
#define CAUSEOFPAIN_H

#include <QWidget>

namespace Ui {
class CauseOfPain;
}

class CauseOfPain : public QWidget
{
    Q_OBJECT

public:
    explicit CauseOfPain(QWidget *parent = nullptr);
    ~CauseOfPain();

private slots:
    void on_signUp_clicked();

    void on_Check_clicked();

    void on_reset_clicked();

private:
    Ui::CauseOfPain *ui;
};

#endif // CAUSEOFPAIN_H
