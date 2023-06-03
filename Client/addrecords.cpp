#include "addrecords.h"
#include "ui_addrecords.h"
#include "basecombomodel.h"
#include "login.h"
#include "mainwindow.h"

#include <QString>

addrecords::addrecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addrecords)
{
    ui->setupUi(this);

    QSqlQuery *query = new QSqlQuery();
    query->exec("SELECT GenderID, GenderDesc FROM Genders");
    while (query->next())
    {
        ui->comboBox_gender->addItem(query->value(0).toString());
    }
    ui->comboBox_gender->setModel(new BaseComboModel("GenderDesc","Genders","GenderID",this));

    QSqlQuery *query2 = new QSqlQuery();
    query2->exec("SELECT JobID, JobDesc FROM Jobs");
    while (query2->next())
    {
        ui->comboBox_job->addItem(query2->value(0).toString());
    }
    ui->comboBox_job->setModel(new BaseComboModel("JobDesc","Jobs","JobID",this));

    QSqlQuery *query3 = new QSqlQuery();
    query3->exec("SELECT EmployeeID, FullName = CONCAT(FirstName, ' ', LastName, ' ', Patronymic) FROM Employees");
    while (query3->next())
    {
        ui->comboBox_employee1->addItem(query3->value(0).toString());
    }
    ui->comboBox_employee1->setModel(new BaseComboModel("FullName = CONCAT(FirstName, ' ', LastName, ' ', Patronymic)","Employees","EmployeeID",this));

    QSqlQuery *query5 = new QSqlQuery();
    query5->exec("SELECT EmployeeID, FullName = CONCAT(FirstName, ' ', LastName, ' ', Patronymic) FROM Employees");
    while (query5->next())
    {
        ui->comboBox_employee2->addItem(query5->value(0).toString());
    }
    ui->comboBox_employee2->setModel(new BaseComboModel("FullName = CONCAT(FirstName, ' ', LastName, ' ', Patronymic)","Employees","EmployeeID",this));

    QSqlQuery *query4 = new QSqlQuery();
    query4->exec("SELECT TypeID, TypeDesc FROM EducationTypes");
    while (query4->next())
    {
        ui->comboBox_educationtype->addItem(query4->value(0).toString());
    }
    ui->comboBox_educationtype->setModel(new BaseComboModel("TypeDesc","EducationTypes","TypeID",this));


    gendercombo = 1;
    jobcombo = 1;
    employeecombo1 = 1;
    employeecombo2 = 1;
    educationcombo = 1;
}

addrecords::~addrecords()
{
    delete ui;
}

void addrecords::on_add_employee_clicked()
{

    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec CreateEmployee :name,:lname,:pname,:idgender,:date,:idjob");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":name",ui->name_input->text());
    qry->bindValue(":lname",ui->fname_input->text());
    qry->bindValue(":pname",ui->pname_input->text());
    qry->bindValue(":idgender",ui->comboBox_gender->itemData(ui->comboBox_gender->currentIndex(),Qt::UserRole));
    qry->bindValue(":date",ui->birthdate_input->date().toString("yyyy-MM-dd"));
    qry->bindValue(":idjob",ui->comboBox_job->itemData(ui->comboBox_job->currentIndex(),Qt::UserRole));

    qry_mes->setWindowTitle("Информация");
    if(!qry->exec())
    {
        qry_mes->setText("Запрос составлен неправильно");
    }
    else
    {
        qry_mes->setText("Информация добавлена");
    }
    qry_mes->show();

    emit refresh_table();
}


void addrecords::on_comboBox_gender_currentIndexChanged(int index)
{
    gendercombo = index;
}


void addrecords::on_comboBox_job_currentIndexChanged(int index)
{
    jobcombo = index;
}


void addrecords::on_add_education_clicked()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec CreateEducation :employeeId, :typeId, :institution, :speciality");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":employeeId",ui->comboBox_employee1->itemData(ui->comboBox_employee1->currentIndex(),Qt::UserRole));
    qry->bindValue(":typeId",ui->comboBox_educationtype->itemData(ui->comboBox_educationtype->currentIndex(),Qt::UserRole));
    qry->bindValue(":institution",ui->institution_input->text());
    qry->bindValue(":speciality",ui->speciality_input->text());

    qry_mes->setWindowTitle("Информация");
    if(!qry->exec())
    {
        qry_mes->setText("Запрос составлен неправильно");
    }
    else
    {
        qry_mes->setText("Информация добавлена");
    }
    qry_mes->show();
    emit refresh_table();
}


void addrecords::on_add_job_clicked()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec CreateJob :job");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":job",ui->job_input1->text());

    qry_mes->setWindowTitle("Информация");
    if(!qry->exec())
    {
        qry_mes->setText("Запрос составлен неправильно");
    }
    else
    {
        qry_mes->setText("Информация добавлена");
    }
    qry_mes->show();
    emit refresh_table();

}


void addrecords::on_add_experience_clicked()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec CreateExperience :employeeId, :job, :start, :end, :company");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":employeeId",ui->comboBox_employee2->itemData(ui->comboBox_employee2->currentIndex(),Qt::UserRole));
    qry->bindValue(":job",ui->job_input2->text());
    qry->bindValue(":start",ui->start_input->date().toString("yyyy-MM-dd"));
    qry->bindValue(":end",ui->end_input->date().toString("yyyy-MM-dd"));
    qry->bindValue(":company",ui->company_input->text());

    qry_mes->setWindowTitle("Информация");
    if(!qry->exec())
    {
        qry_mes->setText("Запрос составлен неправильно");
    }
    else
    {
        qry_mes->setText("Информация добавлена");
    }
    qry_mes->show();
    emit refresh_table();
}


void addrecords::on_comboBox_employee1_currentIndexChanged(int index)
{
    employeecombo1 = index;
}


void addrecords::on_comboBox_educationtype_currentIndexChanged(int index)
{
    educationcombo = index;
}


void addrecords::on_comboBox_employee2_currentIndexChanged(int index)
{
    employeecombo2 = index;
}

