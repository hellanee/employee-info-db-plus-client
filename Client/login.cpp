#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->field_server->setText("LAPTOP-RUJMI5VF\\SQLEXPRESS");
    ui->field_db->setText("Employee_cardfiles");

    ui->field_password->setEchoMode(QLineEdit::Password);
    mes = new QMessageBox();
}

login::~login()
{
    delete ui;
}
void login::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};SERVER="+ui->field_server->text()+";DATABASE="+ui->field_db->text()+";"); //LAPTOP-RUJMI5VF\SQLEXPRESS, Employee_cardfiles
    db.setUserName(ui->field_user->text());
    db.setPassword(ui->field_password->text());
    connOpen();
    if(db.open())
    {
        mes->setText("Connected");
    }
    else
    {
        mes->setText("No connection");
    }
    mes->show();

}

