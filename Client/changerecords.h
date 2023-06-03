#ifndef CHANGERECORDS_H
#define CHANGERECORDS_H

#include <QDate>
#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class ChangeRecords;
}

class ChangeRecords : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeRecords(QWidget *parent = nullptr);
    ~ChangeRecords();
    int gendercombo,jobcombo, employeecombo1, employeecombo2, educationcombo, workorder, jobid, employeeid, educationid;


private slots:
    void obr_sendID1(int);
    void obr_sendID2(int);
    void obr_sendID3(int);
    void obr_sendID4(int);
    void on_comboBox_gender_currentIndexChanged(int);
    void on_comboBox_job_currentIndexChanged(int);
    void on_comboBox_employee1_currentIndexChanged(int);
    void on_comboBox_educationtype_currentIndexChanged(int);
    void on_comboBox_employee2_currentIndexChanged(int);

    void on_change_employee_clicked();

    void on_change_education_clicked();

    void on_change_job_clicked();

    void on_change_experience_clicked();

signals:
    void refresh_table();

private:
    Ui::ChangeRecords *ui;
};

#endif // CHANGERECORDS_H
