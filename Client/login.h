#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "QtSql"
#include "QMessageBox"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT
public:
    QSqlDatabase db;
    void connClose(){
        db.close();
    };
    bool connOpen()
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("DRIVER={SQL Server};SERVER=LAPTOP-RUJMI5VF\\SQLEXPRESS;DATABASE=Employee_cardfiles;");
        if(db.open()){
            return true;
        }
        else return false;
    };



public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    QMessageBox*mes;


private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
