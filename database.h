#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

//данные таблицы чтобы не вводить повторно
#define DATABASE_HOSTNAME "QTCreator"
#define DATABASE_NAME     "D:\\Qtprojects\\dbtest1.accdb" //путь к БД

#define TABLE             "Shop"
#define TABLE_CODE        "Code"
#define TABLE_CLOTHES     "Clothes"
#define TABLE_PRICE       "Price"

class DataBase : public QObject
{
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    //подключение к бд
    void connectToDataBase();
    //вставка записей в таблицу
    bool inserIntoTable(const QVariantList &data);

private:
    //объект бд для связи с методами
    QSqlDatabase    db;

private:
    //открытие БД
    bool openDataBase();
    //обнова БД
    bool restoreDataBase();
    //закрытие БД
    void closeDataBase();
    //создание таблицы
    bool createTable();
};

#endif // DATABASE_H
