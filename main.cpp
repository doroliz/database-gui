#include "mainwindow.h"
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QApplication>

int main(int argc, char *argv[])
{
    /*проверка подключения
     *     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb, *.accdb)};DSN='';DBQ=D:\\Qtprojects\\dbtest1.accdb");

    if(db.open())
      qDebug() << "oK";
    else
      qDebug() << "error";
      */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
