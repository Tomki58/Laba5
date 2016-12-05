#ifndef EDIT_H
#define EDIT_H

#include <QDialog>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT
    
public:
    explicit Edit(QWidget *parent = 0);
    int getId();
    char* getDescription();
    char* getUserName();
    char* getFileName();
    ~Edit();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Edit *ui;
    char id[40], description[40], username[40], filename[40];
};

#endif // EDIT_H
