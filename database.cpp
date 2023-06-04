#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

//подключение к бд
void DataBase::connectToDataBase()
{
    //проверка на существование бд
    //восстановление/открытие
    if(!QFile("C:/example/" DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

//восстановление бд
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

//открытие бд
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    //открытие бд по пути из database.h
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb, *.accdb)};DSN='';DBQ=" DATABASE_NAME);
    if(db.open()){
        qDebug() << "oK";
        return true;
    } else {
        qDebug() << "error";
        return false;
    }
}

//закрытие бд
void DataBase::closeDataBase()
{
    db.close();
}

//создание таблицы
bool DataBase::createTable()
{
    //с помощью запроса
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            TABLE_CODE      " INTEGER PRIMARY KEY, "
                            TABLE_CLOTHES   " VARCHAR(255),"
                            TABLE_PRICE     " MONEY"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

//вставка записей в таблицу
bool DataBase::inserIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE " ( " TABLE_CODE ", "
                                             TABLE_CLOTHES ", "
                                             TABLE_PRICE " ) "
                  "VALUES (:Code, :Clothes, :Price )");
    query.bindValue(":Code",        data[0].toInt());
    query.bindValue(":Clothes",        data[1].toString());
    query.bindValue(":Price",      data[2].toInt());
    //методом exec() выполняется запросом
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
