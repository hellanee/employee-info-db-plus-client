#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "addrecords.h"
#include "changerecords.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, SIGNAL (customContextMenuRequested(QPoint)), SLOT(CustomMenuReq(QPoint)));
    fl=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_to_database_triggered()
{
    login_form = new login();
    login_form->show();


}


void MainWindow::on_show_data_clicked()
{
    login conn;

    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=1;
    qry->prepare("SELECT Employees.EmployeeID, Employees.FirstName, Employees.LastName, Employees.Patronymic, Genders.GenderDesc, Employees.Birthdate, Jobs.JobDesc FROM Employees INNER JOIN Genders ON Employees.GenderID=Genders.GenderID INNER JOIN Jobs ON Employees.JobID=Jobs.JobID");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"ID");
    query_model->setHeaderData(1,Qt::Horizontal,"Имя");
    query_model->setHeaderData(2,Qt::Horizontal,"Фамилия");
    query_model->setHeaderData(3,Qt::Horizontal,"Отчество");
    query_model->setHeaderData(4,Qt::Horizontal,"Пол");
    query_model->setHeaderData(5,Qt::Horizontal,"Дата Рождения");
    query_model->setHeaderData(6,Qt::Horizontal,"Должность");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();

}


void MainWindow::on_actionAddData_triggered()
{
    addrec_form = new addrecords();
    addrec_form->show();
    connect(addrec_form, SIGNAL(refresh_table()), this, SLOT(obr_ref_tab1()));
}


void MainWindow::on_show_data_ed_clicked()
{
    login conn;

    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=1;
    qry->prepare("SELECT Education.EducationID, Employees.FirstName, Employees.LastName, Employees.Patronymic, EducationTypes.TypeDesc, Education.Institution, Education.Speciality FROM Education INNER JOIN EducationTypes ON Education.TypeID=EducationTypes.TypeID INNER JOIN Employees ON Employees.EmployeeID=Education.EmployeeID");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"ID");
    query_model->setHeaderData(1,Qt::Horizontal,"Имя");
    query_model->setHeaderData(2,Qt::Horizontal,"Фамилия");
    query_model->setHeaderData(3,Qt::Horizontal,"Отчество");
    query_model->setHeaderData(4,Qt::Horizontal,"Вид образования");
    query_model->setHeaderData(5,Qt::Horizontal,"Учереждение");
    query_model->setHeaderData(6,Qt::Horizontal,"Специальность");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_show_data_ex_clicked()
{
    login conn;

    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    fl=1;
    QSqlQuery * qry = new QSqlQuery();

    qry->prepare("SELECT Experience.WorkOrderID, Employees.FirstName, Employees.LastName, Employees.Patronymic, Experience.Job, Experience.StartDate, Experience.EndDate, Experience.Company FROM Experience INNER JOIN Employees ON Employees.EmployeeID=Experience.EmployeeID");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"ID");
    query_model->setHeaderData(1,Qt::Horizontal,"Имя");
    query_model->setHeaderData(2,Qt::Horizontal,"Фамилия");
    query_model->setHeaderData(3,Qt::Horizontal,"Отчество");
    query_model->setHeaderData(4,Qt::Horizontal,"Должность");
    query_model->setHeaderData(5,Qt::Horizontal,"Дата начала");
    query_model->setHeaderData(6,Qt::Horizontal,"Дата конца");
    query_model->setHeaderData(7,Qt::Horizontal,"Компания");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_show_data_job_clicked()
{
    login conn;

    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    fl=1;
    QSqlQuery * qry = new QSqlQuery();

    qry->prepare("SELECT Jobs.JobID, Jobs.JobDesc FROM Jobs");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"ID");
    query_model->setHeaderData(1,Qt::Horizontal,"Должность");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::CustomMenuReq(QPoint pos)
{
 if (fl == 1)
 {
 QModelIndex index = ui->tableView->indexAt(pos);
 globid = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();
 QMenu *menu = new QMenu(this);
 QAction* izm1 = new QAction("Изменить сотрудника", this);
 QAction* izm2 = new QAction("Изменить образование", this);
 QAction* izm3 = new QAction("Изменить опыт работы", this);
 QAction* izm4 = new QAction("Изменить должность", this);
 connect(izm1, SIGNAL(triggered()), this, SLOT(izm_zap1()));
 connect(izm2, SIGNAL(triggered()), this, SLOT(izm_zap2()));
 connect(izm3, SIGNAL(triggered()), this, SLOT(izm_zap3()));
 connect(izm4, SIGNAL(triggered()), this, SLOT(izm_zap4()));
 QAction* ud1 = new QAction("Удалить сотрудника", this);
 QAction* ud2 = new QAction("Удалить образование", this);
 QAction* ud3 = new QAction("Удалить опыт работы", this);
 QAction* ud4 = new QAction("Удалить должность", this);
 connect(ud1, SIGNAL(triggered()), this, SLOT(del_zap1()));
 connect(ud2, SIGNAL(triggered()), this, SLOT(del_zap2()));
 connect(ud3, SIGNAL(triggered()), this, SLOT(del_zap3()));
 connect(ud4, SIGNAL(triggered()), this, SLOT(del_zap4()));
 menu->addAction(izm1);
 menu->addAction(izm2);
 menu->addAction(izm3);
 menu->addAction(izm4);
 menu->addAction(ud1);
 menu->addAction(ud2);
 menu->addAction(ud3);
 menu->addAction(ud4);
 menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
 }
}




void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
     row = index.row();


}
void MainWindow::del_zap1()
{
 QSqlQuery *query = new QSqlQuery();
 QMessageBox *qry_mes = new QMessageBox();
 query->prepare("Exec DeleteProcedureEmployees ?");
 query->bindValue(0, globid);
 if (query->exec())
 {
    qry_mes->setText("Запрос выполнен" + QString::number(globid));
    on_show_data_clicked();
 }
 else
    qry_mes->setText("Запрос не выполнен");
 qry_mes->show();
}

void MainWindow::del_zap2()
{
 QSqlQuery *query = new QSqlQuery();
  QMessageBox *qry_mes = new QMessageBox();
 query->prepare("Exec DeleteProcedureEducation ?");
 query->bindValue(0, globid);
 if (query->exec())
 {
    qry_mes->setText("Запрос выполнен" + QString::number(globid));
    on_show_data_ed_clicked();
 }
 else
    qry_mes->setText("Запрос не выполнен");
 qry_mes->show();
}

void MainWindow::del_zap3()
{
 QSqlQuery *query = new QSqlQuery();
  QMessageBox *qry_mes = new QMessageBox();
 query->prepare("Exec DeleteProcedureExperience ?");
 query->bindValue(0, globid);
 if (query->exec())
 {
    qry_mes->setText("Запрос выполнен" + QString::number(globid));
    on_show_data_ex_clicked();
 }
 else
    qry_mes->setText("Запрос не выполнен");
 qry_mes->show();
}

void MainWindow::del_zap4()
{
 QSqlQuery *query = new QSqlQuery();
  QMessageBox *qry_mes = new QMessageBox();
 query->prepare("Exec DeleteProcedureJobs ?");
 query->bindValue(0, globid);
 if (query->exec())
 {
    qry_mes->setText("Запрос выполнен" + QString::number(globid));
    on_show_data_job_clicked();
 }
 else
    qry_mes->setText("Запрос не выполнен");
 qry_mes->show();
}

void MainWindow::izm_zap1()
{
 changerec_form = new ChangeRecords();
 connect(this, SIGNAL(sendID(int)), changerec_form, SLOT(obr_sendID1(int)));
 emit sendID(globid);
 changerec_form->show();
 disconnect(this, SIGNAL(sendID(int)), changerec_form, SLOT(obr_sendID1(int)));
}
void MainWindow::izm_zap2()
{
 changerec_form = new ChangeRecords();
 connect(this, SIGNAL(sendID2(int)), changerec_form, SLOT(obr_sendID2(int)));
 emit sendID2(globid);
 changerec_form->show();
 disconnect(this, SIGNAL(sendID2(int)), changerec_form, SLOT(obr_sendID2(int)));
}
void MainWindow::izm_zap3()
{
 changerec_form = new ChangeRecords();
 connect(this, SIGNAL(sendID3(int)), changerec_form, SLOT(obr_sendID3(int)));
 emit sendID3(globid);
 changerec_form->show();
 disconnect(this, SIGNAL(sendID3(int)), changerec_form, SLOT(obr_sendID3(int)));
}
void MainWindow::izm_zap4()
{
 changerec_form = new ChangeRecords();
 connect(this, SIGNAL(sendID4(int)), changerec_form, SLOT(obr_sendID4(int)));
 emit sendID4(globid);
 changerec_form->show();
 disconnect(this, SIGNAL(sendID4(int)), changerec_form, SLOT(obr_sendID4(int)));

}






void MainWindow::on_pushButton_clicked()
{
    login conn;
    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=0;
    qry->prepare("SELECT Employees.FirstName, Employees.LastName, YEAR(Experience.EndDate)-YEAR(Experience.StartDate), CASE WHEN (YEAR(Experience.EndDate)-YEAR(Experience.StartDate))>3 THEN 'Опыт на прошлом месте работы больше 3 лет' WHEN (YEAR(Experience.EndDate)-YEAR(Experience.StartDate))<=3 THEN 'Опыт на прошлом месте работы не более 3 лет'END TotalWork FROM Employees JOIN Experience ON Experience.EmployeeID = Employees.EmployeeID");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"Имя");
    query_model->setHeaderData(1,Qt::Horizontal,"Фамилия");
    query_model->setHeaderData(2,Qt::Horizontal,"Лет на прошлом месте работы");
    query_model->setHeaderData(3,Qt::Horizontal,"Опыт");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    login conn;
    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=0;
    qry->prepare("SELECT Employees.FirstName, Employees.LastName, Employees.Patronymic, (SELECT GenderDesc FROM Genders WHERE Genders.GenderID = Employees.GenderID) AS Gender FROM Employees;");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"Имя");
    query_model->setHeaderData(1,Qt::Horizontal,"Фамилия");
    query_model->setHeaderData(2,Qt::Horizontal,"Отчество");
    query_model->setHeaderData(3,Qt::Horizontal,"Пол");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    login conn;
    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=0;
    qry->prepare("SELECT FirstName, JobID FROM (SELECT FirstName, JobID FROM Employees WHERE EmployeeID = 2) AS Query;");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"Имя");
    query_model->setHeaderData(1,Qt::Horizontal,"Номер должности");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    login conn;
    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=0;
    qry->prepare("SELECT FirstName, LastName, Patronymic FROM Employees WHERE JobID =(SELECT JobID FROM Employees WHERE LastName LIKE 'Иванов' AND FirstName LIKE 'Иван' AND Patronymic LIKE 'Иванович');");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"Имя");
    query_model->setHeaderData(1,Qt::Horizontal,"Фамилия");
    query_model->setHeaderData(2,Qt::Horizontal,"Отчество");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    login conn;
    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=0;
    qry->prepare("SELECT Employees.FirstName, Experience.EndDate FROM Employees JOIN Experience ON Experience.EmployeeID = Employees.EmployeeID WHERE GenderID = 1 AND Experience.EndDate > ANY (SELECT Birthdate FROM Employees JOIN Experience ON Experience.EmployeeID = Employees.EmployeeID WHERE Employees.GenderID = 2);");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"Имя");
    query_model->setHeaderData(1,Qt::Horizontal,"Окончание работы");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    login conn;
    QSqlQueryModel *query_model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery();
    fl=0;
    qry->prepare("SELECT Employees.FirstName, Experience.EndDate FROM Employees JOIN Experience ON Experience.EmployeeID = Employees.EmployeeID WHERE GenderID = 1 AND Experience.EndDate > ALL (SELECT Birthdate FROM Employees JOIN Experience ON Experience.EmployeeID = Employees.EmployeeID WHERE Employees.GenderID = 2);");
    qry->exec();
    query_model->setQuery(*qry);

    query_model->setHeaderData(0,Qt::Horizontal,"Имя");
    query_model->setHeaderData(1,Qt::Horizontal,"Окончание работы");

    ui->tableView->setModel(query_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

