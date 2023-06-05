#pragma execution_character_set("cp1251")

#include "goods.h"
#include "ui_goods.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QTextCodec>

Goods::Goods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Goods)
{
    ui->setupUi(this);

    ui->PriceOne->setText("149");
    ui->PriceTwo->setText("490");
    ui->PriceThree->setText("9990");
    ui->PriceFour->setText("329");
    ui->PriceFive->setText("819");
    ui->PriceSix->setText("379");
    ui->PriceSeven->setText("419");
}

Goods::~Goods()
{
    delete ui;
}

void Goods::on_Add_clicked()
{
    QString p_one = ui->first_push->text();
    QString p_two = ui->second_push->text();
    QString p_three = ui->third_push->text();
    QString p_four = ui->fourth_push->text();
    QString p_five = ui->fifth_push->text();
    QString p_six = ui->sixth_push->text();
    QString p_seven = ui->seventh_push->text();

    QString lv1 = ui->PriceOne->text(); // Получить текст из QLabel
    int value1 = lv1.toInt(); // Преобразовать текст в int
    QString lv2 = ui->PriceTwo->text();
    int value2 = lv2.toInt();
    QString lv3 = ui->PriceThree->text();
    int value3 = lv3.toInt();
    QString lv4 = ui->PriceFour->text();
    int value4 = lv4.toInt();
    QString lv5 = ui->PriceFive->text();
    int value5 = lv5.toInt();
    QString lv6 = ui->PriceSix->text();
    int value6 = lv6.toInt();
    QString lv7 = ui->PriceSeven->text();
    int value7 = lv7.toInt();

    QString fileName = "Goods.txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);
        // (p_one.toInt() * value1) - произведение денежной суммы и количества товара
        stream << "Dentamete Gel: " << p_one << " - " << "Total: " << (p_one.toInt() * value1) << endl;
        stream << "Interdental brush: " << p_two << " - " << "Total: " << (p_two.toInt() * value2) << endl;
        stream << "Набор отбеливания зубов: " << p_three << " - " << "Total: " << (p_three.toInt() * value3) << endl;
        stream << "Teeth Whitening Kit: " << p_four << " - " << "Total: " << (p_four.toInt() * value4) << endl;
        stream << "Korega-cream: " << p_five << " - " << "Total: " << (p_five.toInt() * value5) << endl;
        stream << "Veneers: " << p_six << " - " << "Total: " << (p_six.toInt() * value6) << endl;
        stream << "Orthodontic chain: " << p_seven << " - " << "Total: " << (p_seven.toInt() * value7) << endl;
        stream << "Total price: " << (p_one.toInt() * value1)+(p_two.toInt() * value2)+(p_three.toInt() * value3)+(p_four.toInt() * value4)+(p_five.toInt() * value5)+(p_six.toInt() * value6)+(p_seven.toInt() * value7);
        stream << endl;

        file.close();

        ui->first_push->clear();
        ui->second_push->clear();
        ui->third_push->clear();
        ui->fourth_push->clear();
        ui->fifth_push->clear();
        ui->sixth_push->clear();
        ui->seventh_push->clear();
    }
}


void Goods::on_check_clicked()
{
    QString fileName = "Goods.txt";
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                QString line = in.readLine();
                qDebug().noquote() << line;
            }
            file.close();

            QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
        }
    }
}


void Goods::on_order_clicked()
{
    QString fileName = "Goods.txt";
    QFile file(fileName);
    if (file.remove())
    {
        ui->True->setText("Заказ успешно совершен! Спасибо за покупку");
    }
    else
    {
        ui->False->setText("Произошла ошибка с выполнение заказа!");
    }
}

