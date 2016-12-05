// Габидуллин А.Р. БИВ-154 Вариант №7
// Задание - перегрузить операторы, заменить методы на перегруженные операторы, где это возможно.
// Перегрузка : арифметических операторов, в виде оператора класса, так и в виде дружественной функции; постфиксный и префиксный инкременты/декременты;
// операторы << и >> для ввода или вывода элементов очереди; оператор индексации для получения значения; оператор (), заменяющий конструктор инициализации;
// оператор сравнения и побитовые операторы, в данном случае XOR (^), И(&) и ИЛИ(|);
// также реализовать перегрузку оператора присваивания (=);

#include "dialog.h"
#include "ui_dialog.h"
#include <cstring>
#include "info.h"
#include <QFiledialog>
#include <edit.h>
#include <ctime>

typedef Launch l_l;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->First->setChecked(true);
    ui->label->clear();
    ui->ID->setInputMask("9999999");
    ui->Description->setInputMask("AAAAAAAAAA");
    ui->User_Name->setInputMask("AXXXXXXXXXXXXX");
    ui->FileName->setInputMask("XXXXXXXX");
    ui->comboBox->addItem("Log");
    ui->comboBox->addItem("Launch");
}

Deque <Log, Launch> *D = new Deque <Log, l_l>;
Deque <Log, Launch> *D1 = new Deque <Log, l_l>;
time_t curTime;

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    if (!(ui->label->text().isEmpty()))
            ui->label->setText("");
    if (ui->ID->text().isEmpty() || ui->Description->text().isEmpty() || ui->User_Name->text().isEmpty())
    {
        ui->label->setStyleSheet("color : rgb(255, 0, 0)");
        ui->label->setText("Impossible to add element with this parametres");
    }
    else
    {
        if (ui->First->isChecked())
        {
            if (ui->comboBox->currentText() == "Log")
            {
                char *Description = new char[40]; char *User_Name = new char[40];
                strcpy(Description, qPrintable(ui->Description->text()));
                strcpy(User_Name, qPrintable(ui->User_Name->text()));
                Log *L = new Log;
                (*L)(ui->ID->text().toInt(), Description, User_Name);
                (*D) << L;
                ui->ID->clear(); ui->Description->clear(); ui->User_Name->clear();
            }
            else
                if (ui->comboBox->currentText() == "Launch")
                {
                    char *Description = new char[40]; char *User_Name = new char[40]; char *FileName = new char[40];
                    strcpy(Description, qPrintable(ui->Description->text()));
                    strcpy(User_Name, qPrintable(ui->User_Name->text()));
                    strcpy(FileName, qPrintable(ui->FileName->text()));
                    l_l *l = new l_l;
                    (*l)(ui->ID->text().toInt(), Description, User_Name, FileName);
                    (*D) << l;
                    ui->ID->clear(); ui->Description->clear(); ui->User_Name->clear(); ui->FileName->clear();
                }
        }
        if (ui->Last->isChecked())
        {
            if (ui->comboBox->currentText() == "Log")
            {
                char *Description = new char[40]; char *User_Name = new char[40];
                strcpy(Description, qPrintable(ui->Description->text()));
                strcpy(User_Name, qPrintable(ui->User_Name->text()));
                Log *L = new Log;
                (*L)(ui->ID->text().toInt(), Description, User_Name);
                D->addLast(L);
                ui->ID->clear(); ui->Description->clear(); ui->User_Name->clear();
            }
            else
                if (ui->comboBox->currentText() == "Launch")
                {
                    char *Description = new char[40]; char *User_Name = new char[40]; char *FileName = new char[40];
                    strcpy(Description, qPrintable(ui->Description->text()));
                    strcpy(User_Name, qPrintable(ui->User_Name->text()));
                    strcpy(FileName, qPrintable(ui->FileName->text()));
                    l_l *l = new l_l;
                    (*l)(ui->ID->text().toInt(), Description, User_Name, FileName);
                    D->addLast(l);
                    ui->ID->clear(); ui->Description->clear(); ui->User_Name->clear(); ui->FileName->clear();
                }
        }
    }
}

void Dialog::on_pushButton_2_clicked()
{
    if (ui->First->isChecked())
    {
        if (--(*D))
        {
            ui->label->setStyleSheet("color : rgb(255, 0, 0)");
            ui->label->setText("Deque is empty");
        }
    }
    if (ui->Last->isChecked())
    {
        if ((*D)--)
        {
            ui->label->setStyleSheet("color : rgb(255, 0, 0)");
            ui->label->setText("Deque is empty");
        }
    }
}



void Dialog::on_pushButton_3_clicked()
{
    Info *I = new Info;
    I->show();
}

void Dialog::on_reverse_clicked()
{
    if (D->reverse() == 0)
    {
        ui->label->setStyleSheet("color : rgb(255, 0, 0)");
        ui->label->setText("Impossible to reverse");
    }
}

void Dialog::on_sort_clicked()
{
    if (D->sort() == 0)
    {
        ui->label->setStyleSheet("color : rgb(255, 0, 0)");
        ui->label->setText("Impossible to sort");
    }
}

void Dialog::showText(Log l)
{
    ui->textBrowser->setText("Name : " + QString(l.get_User_Name()));
    ui->textBrowser->append("Description : " + QString(l.get_Description()));
    QString tmp = tr("%1").arg(l.get_Event_ID());
    ui->textBrowser->append("Event ID : " + tmp);
}

void Dialog::showText(l_l l)
{
    ui->textBrowser->setText("Name : " + QString(l.get_User_Name()));
    ui->textBrowser->append("Description : " + QString(l.get_Description()));
    QString tmp = tr("%1").arg(l.get_Event_ID());
    ui->textBrowser->append("Event ID : " + tmp);
    ui->textBrowser->append("Name of file : " + QString(l.get_Name_Of_File()));
}

void Dialog::on_pushButton_5_clicked()
{
    if (ui->First->isChecked())
    {
        if (D->isEmpty())
        {
            ui->textBrowser->setText("Deque is empty!");
        }
        else
        {
            l_l* D1 = dynamic_cast<l_l*>(D->First());
            if (D1 != NULL)
            {
                showText(*D1);
            }
            else
                showText(*(*D)[0]);
        }
    }
    else
    {
        if (D->isEmpty())
        {
            ui->textBrowser->setText("Deque is empty!");
        }
        else
        {
            l_l* D1 = dynamic_cast<l_l*>(D->Last());
            if (D1 != NULL)
            {
                showText(*D1);
            }
            else
                showText(*(*D)[D->getCount() - 1]);
        }
    }
}

void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (ui->comboBox->currentText() == "Log")
    {
        ui->FileName->setEnabled(false);
        ui->FileName->hide();
        ui->label_5->hide();
    }
    if (ui->comboBox->currentText() == "Launch")
    {
        ui->FileName->setEnabled(true);
        ui->FileName->show();
        ui->label_5->show();
    }
}



void Dialog::on_Open_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\Qt\qtcreator-2.4.1\LABA2-build-desktop-Qt_4_7_4__4_7_4_________", "Text File (*.txt)");
    FILE *f; QString tmp;
    f = fopen(filename.toStdString().c_str(), "r");
    char id[15];
    if (!f)
        ui->textBrowser->setText("Can't open file with this name");
    else
    {
        while(!feof(f))
        {
            fgets(id, 15, f);
            if (strlen(id) == 0)
                ui->textBrowser->setText("Empty File!");
            else
            {
                if (!strcmp(id, "Log\n"))
                {
                    Log *l = new Log();
                    l->loadFromFile(f);
//                    D->addFirst(l);
                    (*D) << l;
                }
                else
                {
                    l_l *l1 = new l_l;
                    l1->loadFromFile(f);
//                    D->addFirst(l1);
                    (*D) << l1;
                }
            }
        }
    }
    fclose(f);
}

void Dialog::on_Save_clicked()
{
    if (!D->isEmpty())
    {
        FILE *f;
        QString filename = QFileDialog::getSaveFileName(this, tr("Save file"), "C:\Qt", "Text File (*.txt)");
        f = fopen(filename.toStdString().c_str(), "w");
        (*D) >> f;
        fclose(f);
    }
    else
    {
        ui->label->setText("Nothing to save!");
        ui->label->setStyleSheet("color : rgb(255,0,0)");
    }
}

void Dialog::on_pushButton_6_clicked()
{
    if (ui->lineEdit->text().isEmpty() || atoi(ui->lineEdit->text().toStdString().c_str()) > D->getCount()-1)
    {
        ui->label->setText("Invalid number");
    }
    else
    {
        Edit *J = new Edit;
        J->show(); J->exec();
        l_l *l = new l_l;
        l = dynamic_cast<l_l*>((*D)[(ui->lineEdit->text().toInt())]);
        if (l == NULL)
        {
            Log *p = new Log;
            *p = *(*D)[(ui->lineEdit->text().toInt())];
            if (J->getId() != -1)
//                p->set_Event_ID(J->getId());
                (*p) = J->getId();
            if (strcmp(J->getDescription(), ""))
//                p->set_Description(J->getDescription());
                (*p) = J->getDescription();
            if (strcmp(J->getUserName(), ""))
                p->set_User_Name(J->getUserName());
            *(*D)[(ui->lineEdit->text().toInt())] = *p;
            delete p;
            delete l;
        }
        else
        {
            if (J->getId() != -1)
//                l->set_Event_ID(J->getId());
            if (strcmp(J->getDescription(), ""))
                l->set_Description(J->getDescription());
            if (strcmp(J->getUserName(), ""))
                l->set_User_Name(J->getUserName());
            if (strcmp(J->getFileName(), ""))
                l->set_Name_Of_File(J->getFileName());
            *(*D)[(ui->lineEdit->text().toInt())] = *l;
        }
    }
}

void Dialog::on_pushButton_7_clicked()
{

}

void Dialog::operator ^(Deque <Log, l_l> *deq)
{
    l_l *l = new l_l;
    for (int i = 0; i < deq->getCount() ; i++)
    {
        l = dynamic_cast<l_l*>((*deq)[i]);
        if (l == NULL)
        {
            ui->textBrowser->append("LOG : ");
            ui->textBrowser->append("ID " + tr("%1").arg((*deq)[i]->get_Event_ID()));
            ui->textBrowser->append("Description " + QString((*deq)[i]->get_Description()));
            ui->textBrowser->append("UserName " + QString((*deq)[i]->get_User_Name()));
        }
        else
        {
            ui->textBrowser->append("LAUNCH : ");
            ui->textBrowser->append("ID " + tr("%1").arg(l->get_Event_ID()));
            ui->textBrowser->append("Description " + QString(l->get_Description()));
            ui->textBrowser->append("UserName " + QString(l->get_User_Name()));
            ui->textBrowser->append("Filename " + QString(l->get_Name_Of_File()));
        }
    }
}

// В результате выполнения работы была выполнена перегрузка операторов +, +=, ++(постфиксный и префиксный варианты)
// <<, >>, -- (постфиксный и префиксный варианты), битовые операторы (&, |, ^)
