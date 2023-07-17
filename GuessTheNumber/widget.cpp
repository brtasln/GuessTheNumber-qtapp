#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //set up the seed
    std::srand(std::time(nullptr));
    //Generate (1-10)
    target_number = std::rand() % 10 + 1;
    qDebug() << "The number generated: " << QString::number(target_number);

    //Disable the start over button

    ui->startOverButton->setDisabled(true);

    //
    ui->MessageLabel->setText("");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guess_number = ui->numberSpinBox->value();
    qDebug() << "User guessed : " << QString::number(guess_number);
        //Check if the user guessed right number
    if(guess_number == target_number) {
        //show the congrat message
        ui->MessageLabel->setText(""
         "Congratulations, the number is " + QString::number(guess_number));

        //button housekeeping
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);


    }
    else {
        if(target_number < guess_number) {
            ui->MessageLabel->setText("Number is lower than that you guessed");
        }
        if(target_number > guess_number) {
            ui->MessageLabel->setText("Number is higher than that you guessed");
        }
    }
}


void Widget::on_startOverButton_clicked()
{
    //Enable the guess button
    ui->guessButton->setDisabled(false);

    //Disable the start over button
    ui->startOverButton->setDisabled(true);

    //Put the spinbox back to 1
    ui->numberSpinBox->setValue(1);

    //Regenerate the random number
    target_number = rand() % 10 + 1;

    //Clear the message label
    ui->MessageLabel->setText("");
}

