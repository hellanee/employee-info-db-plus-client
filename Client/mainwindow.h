#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "ui_login.h"
#include "addrecords.h"
#include "ui_addrecords.h"
#include "changerecords.h"
#include "ui_changerecords.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtSql>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    login*login_form;
    addrecords*addrec_form;
    ChangeRecords*changerec_form;
    QMessageBox*err_mes;

    int globid;
    int fl;
    int row;

private slots:
    void on_actionConnect_to_database_triggered();

    void on_show_data_clicked();

    void on_actionAddData_triggered();

    void on_show_data_ed_clicked();

    void on_show_data_ex_clicked();

    void CustomMenuReq(QPoint);

    void on_tableView_clicked(const QModelIndex &index);

    void izm_zap1();

    void izm_zap2();

    void izm_zap3();

    void izm_zap4();

    void del_zap1();

    void del_zap2();

    void del_zap3();

    void del_zap4();

    void on_show_data_job_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

signals:
    void sendID(int);
    void sendID2(int);
    void sendID3(int);
    void sendID4(int);


private:
    Ui::MainWindow *ui;
    QSqlQueryModel*query_model;


};
#endif // MAINWINDOW_H
