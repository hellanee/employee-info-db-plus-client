#ifndef ADDRECORDS_H
#define ADDRECORDS_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class addrecords;
}

class addrecords : public QWidget
{
    Q_OBJECT

public:
    explicit addrecords(QWidget *parent = nullptr);
    ~addrecords();
    int gendercombo, jobcombo, employeecombo1, employeecombo2, educationcombo;

private slots:
    void on_add_employee_clicked();

    void on_comboBox_gender_currentIndexChanged(int index);

    void on_comboBox_job_currentIndexChanged(int index);

    void on_add_education_clicked();

    void on_add_job_clicked();

    void on_add_experience_clicked();

    void on_comboBox_employee1_currentIndexChanged(int index);

    void on_comboBox_educationtype_currentIndexChanged(int index);

    void on_comboBox_employee2_currentIndexChanged(int index);

signals:
    void refresh_table();

private:
    Ui::addrecords *ui;
};

#endif // ADDRECORDS_H
