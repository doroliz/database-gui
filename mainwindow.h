#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
//заголовочный файл
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //объект для взаимодействия с инфой в БД
    DataBase        *db;
    //для взаимодействия с таблицей
    QSqlTableModel  *model;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    //формирование модели
    //void setupModel(const QString &tableName, const QStringList &headers);
    void setupModel(const QString &tableName);
    //формирование внешнего вида таблицы
    void createUI();
};
#endif // MAINWINDOW_H
