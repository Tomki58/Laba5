#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <log.h>
#include <deque.cpp>
#include <launch.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void showText(Log);
    void showText(Launch);
    void operator ^ (Deque <Log, Launch> *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_reverse_clicked();

    void on_sort_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_Open_clicked();

    void on_Save_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
