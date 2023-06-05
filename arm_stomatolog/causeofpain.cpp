#pragma execution_character_set("cp1251")

#include "causeofpain.h"
#include "ui_causeofpain.h"
#include <QTextCharFormat>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QDebug>
#include <QUrl>
#include <QTextCodec>

CauseOfPain::CauseOfPain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CauseOfPain)
{
    ui->setupUi(this);
}

CauseOfPain::~CauseOfPain()
{
    delete ui;
}

void CauseOfPain::on_signUp_clicked()
{
    // выбор текста
    QString firstAction = ui->prob->currentText();
    QString secondAction = ui->dec->currentText();
    QString thirdAction = ui->doc->currentText();
    // выбор даты
    QDate selectedDate = ui->date_push->selectedDate();

    // Перекрасить выбранную дату в красный цвет
    QTextCharFormat selectedDateFormat;
    selectedDateFormat.setForeground(Qt::red);
    ui->date_push->setDateTextFormat(selectedDate, selectedDateFormat);

    // Проверка заполненности полей
    if (firstAction.isEmpty() || secondAction.isEmpty() || thirdAction.isEmpty() || selectedDate.isNull()) {
        ui->False->setText("Что-то пошло не так!");
        ui->True->setText("");
    } else {
        // Запись данных в файл
        QFile file("Sign Up.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << "Problem: " << firstAction << endl;
            stream << "Decision: " << secondAction << endl;
            stream << "Doctor: " << thirdAction << endl;
            stream << "Date: " << selectedDate.toString(Qt::ISODate) << endl;
            stream << "-----------------------------------" << endl;

            file.close();
            ui->True->setText("Запись прошла успешно!");
            ui->False->setText("");
        }
        else {
            // Обработка ошибки открытия файла
            ui->False->setText("Что-то пошло не так!");
            ui->True->setText("");
        }
    }
}


void CauseOfPain::on_Check_clicked()
{
    // путь к файлу с информацией
    QString fileName = "Sign Up.txt";
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        // открытие файла в режиме "только чтение" и в текстовом режиме
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            while (!in.atEnd())
            {
                // вывод информации в консоль
                QString line = in.readLine();
                qDebug().noquote() << line;
            }
            file.close();

            // автоматическое открытие файла
            QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
        }
    }
}


void CauseOfPain::on_reset_clicked()
{
    // действие, чтобы после очистки всех полей из низ не пропадали значения
    QStringList itemsForProb;
    QStringList itemsForDec;
    QStringList itemsForDoc;
    itemsForProb << "" << "Болит зуб мудрости" << "Болит зуб" << "Записаться на осмотр";
    itemsForDec << "" << "Записаться на удаление зуба" << "Записаться на осмотр";
    itemsForDoc << "" << "Дмитриева А.Г" << "Федоров О.Н" << "Иванов А.И" << "Васильев А.А";

    // Очистка полей ввода информации
    ui->prob->clear();
    ui->prob->addItems(itemsForProb);
    ui->dec->clear();
    ui->dec->addItems(itemsForDec);
    ui->doc->clear();
    ui->doc->addItems(itemsForDoc);
    ui->date_push->setSelectedDate(QDate()); // Сброс выбранной даты
}

