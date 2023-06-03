#include "changerecords.h"
#include "ui_changerecords.h"
#include "basecombomodel.h"
#include "mainwindow.h"
#include <QMessageBox>

ChangeRecords::ChangeRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeRecords)
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



}

ChangeRecords::~ChangeRecords()
{
    delete ui;
}
void ChangeRecords::obr_sendID1(int aa)
{
    QSqlQuery *query = new QSqlQuery();
     query->prepare("SELECT FirstName, LastName, Patronymic, GenderID, Birthdate, JobID FROM Employees WHERE EmployeeID =?");
     query->bindValue(0, aa);


      if (query->exec())
      {
      query->next();
      ui->name_input->setText(query->value(0).toString());
      ui->fname_input->setText(query->value(1).toString());
      ui->pname_input->setText(query->value(2).toString());
      ui->comboBox_gender->setCurrentIndex(query->value(3).toInt() - 1);
      ui->birthdate_input->setDate(query->value(4).toDate());
      ui->comboBox_job->setCurrentIndex(query->value(5).toInt() - 1);

      employeeid = aa;

      }

}
void ChangeRecords::obr_sendID2(int aa)
{
    QSqlQuery *query = new QSqlQuery();
     query->prepare("SELECT EmployeeID, TypeID, Institution, Speciality FROM Education WHERE EducationID =?");
     query->bindValue(0, aa);

     if (query->exec())
     {
     query->next();
     ui->comboBox_employee2->setCurrentIndex(query->value(0).toInt());
     ui->comboBox_educationtype->setCurrentIndex(query->value(1).toInt() - 1);
     ui->institution_input->setText(query->value(2).toString());
     ui->speciality_input->setText(query->value(3).toString());

     educationid=aa;
     }

}
void ChangeRecords::obr_sendID3(int aa)
{
    QSqlQuery *query = new QSqlQuery();
     query->prepare("SELECT EmployeeID, Job, StartDate, EndDate, Company FROM Experience WHERE WorkOrderID =?");
     query->bindValue(0, aa);

     if (query->exec())
     {
     query->next();
     ui->comboBox_employee1->setCurrentIndex(query->value(0).toInt());
     ui->job_input2->setText(query->value(1).toString());
     ui->start_date->setDate(query->value(2).toDate());
     ui->end_date->setDate(query->value(3).toDate());
     ui->company_input->setText(query->value(4).toString());

     workorder = aa;

     }
}
void ChangeRecords::obr_sendID4(int aa)
{
    QSqlQuery *query = new QSqlQuery();
     query->prepare("SELECT JobDesc FROM Jobs WHERE JobID =?");
     query->bindValue(0, aa);

     if (query->exec())
     {
     query->next();
     ui->job_input1->setText(query->value(0).toString());

     jobid = aa;
     }
}

void ChangeRecords::on_comboBox_gender_currentIndexChanged(int index)
{
    gendercombo = index;
}


void ChangeRecords::on_comboBox_job_currentIndexChanged(int index)
{
    jobcombo = index;
}

void ChangeRecords::on_comboBox_employee1_currentIndexChanged(int index)
{
    employeecombo1 = index;
}


void ChangeRecords::on_comboBox_educationtype_currentIndexChanged(int index)
{
    educationcombo = index;
}


void ChangeRecords::on_comboBox_employee2_currentIndexChanged(int index)
{
    employeecombo2 = index;
}

void ChangeRecords::on_change_employee_clicked()
{

    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec ChangeEmployees :id, :name,:lname,:pname,:idgender,:date,:idjob");
    QMessageBox *qry_mes = new QMessageBox();

    qry->bindValue(":id",employeeid);
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
        qry_mes->setText("Информация изменена");
    }
    qry_mes->show();

    emit refresh_table();
}



void ChangeRecords::on_change_education_clicked()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec ChangeEducations :id, :employeeId, :typeId, :institution, :speciality");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":id",educationid);
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
        qry_mes->setText("Информация изменена");
    }
    qry_mes->show();
    emit refresh_table();
}


void ChangeRecords::on_change_job_clicked()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec ChangeJobs :id, :job");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":id",jobid);
    qry->bindValue(":job",ui->job_input1->text());

    qry_mes->setWindowTitle("Информация");
    if(!qry->exec())
    {
        qry_mes->setText("Запрос составлен неправильно");
    }
    else
    {
        qry_mes->setText("Информация изменена");
    }
    qry_mes->show();
    emit refresh_table();
}


void ChangeRecords::on_change_experience_clicked()
{
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("exec ChangeExperiences :id, :employeeId, :job, :start, :end, :company");
    QMessageBox *qry_mes = new QMessageBox();
    qry->bindValue(":id",workorder);
    qry->bindValue(":employeeId",ui->comboBox_employee2->itemData(ui->comboBox_employee2->currentIndex(),Qt::UserRole));
    qry->bindValue(":job",ui->job_input2->text());
    qry->bindValue(":start",ui->start_date->date().toString("yyyy-MM-dd"));
    qry->bindValue(":end",ui->end_date->date().toString("yyyy-MM-dd"));
    qry->bindValue(":company",ui->company_input->text());

    qry_mes->setWindowTitle("Информация");
    if(!qry->exec())
    {
        qry_mes->setText("Запрос составлен неправильно");
    }
    else
    {
        qry_mes->setText("Информация изменена");
    }
    qry_mes->show();
    emit refresh_table();
}

