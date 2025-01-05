#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digits_numbers(); // Метод должен быть объявлен здесь

    void on_pushButton_13_clicked();

    void operations();

    void on_pushButton_AC_clicked();

    void on_pushButton_16_clicked();

    void math_operations();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
