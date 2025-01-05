#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->result_show->setText("0");
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_4->setCheckable(true);
    ui->pushButton_20->setCheckable(true);
    ui->pushButton_12->setCheckable(true);
    ui->pushButton_8->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*) sender();  //позволяет получить кнопку которая была нажата

    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0"){
        new_label = ui->result_show->text() + button->text();
    }
    else {

    all_numbers = (ui->result_show->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_13_clicked()
{
    if(!(ui->result_show->text().contains('.'))){    //если нету точки то добавляем её
        ui->result_show->setText(ui->result_show->text() + ".");
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton*) sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-"){  //смена знака

        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
    else if(button->text() == "%"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton*) sender();  //будем отслеживать на какую кнопку нажата

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true); //узнаем, на какую кнопку было изначально нажато(запоминает знак)
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_4->setChecked(false);
    ui->pushButton_20->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_8->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_16_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_4->isChecked()){  // /

        labelNumber = num_first / num_second;

        new_label = QString::number(labelNumber, 'g', 15); //число в строку

        ui->result_show->setText(new_label);

        ui->pushButton_4->setChecked(false);

    }
    else if(ui->pushButton_20->isChecked()){ //-

        labelNumber = num_first - num_second;

        new_label = QString::number(labelNumber, 'g', 15); //число в строку

        ui->result_show->setText(new_label);

        ui->pushButton_20->setChecked(false);

    }
    else if(ui->pushButton_12->isChecked()){  //+

        labelNumber = num_first + num_second;

        new_label = QString::number(labelNumber, 'g', 15); //число в строку

        ui->result_show->setText(new_label);

        ui->pushButton_12->setChecked(false);

    }
    else if(ui->pushButton_8->isChecked()){ // *

        labelNumber = num_first * num_second;

        new_label = QString::number(labelNumber, 'g', 15); //число в строку

        ui->result_show->setText(new_label);

        ui->pushButton_16->setChecked(false);

    }
}


