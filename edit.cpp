#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    ui->lineEdit->setInputMask("999999");
    strcpy(this->id, "");
    strcpy(this->description, "");
    strcpy(this->username, "");
    strcpy(this->filename, "");
}

Edit::~Edit()
{
    delete ui;
}

int Edit::getId()
{
    if (strcmp(this->id, ""))
        return atoi(this->id);
    else
        return -1;
}

char* Edit::getDescription()
{
    char buf[40];
    strcpy(buf, this->description);
    return buf;
}

char* Edit::getUserName()
{
    char buf[40];
    strcpy(buf, this->username);
    return buf;
}

char* Edit::getFileName()
{
    char buf[40];
    strcpy(buf, this->filename);
    return buf;
}

void Edit::on_pushButton_clicked()
{
    strcpy(id, ""); strcpy(description, ""); strcpy(username, ""); strcpy(filename, "");
    strcpy(id, ui->lineEdit->text().toStdString().c_str());
    if (strcmp(ui->lineEdit_2->text().toStdString().c_str(),""))
        strcpy(description, ui->lineEdit_2->text().toStdString().c_str());
    if (strcmp(ui->lineEdit_3->text().toStdString().c_str(),""))
        strcpy(username, ui->lineEdit_3->text().toStdString().c_str());
    if (strcmp(ui->lineEdit_4->text().toStdString().c_str(),""))
        strcpy(filename, ui->lineEdit_4->text().toStdString().c_str());
}
