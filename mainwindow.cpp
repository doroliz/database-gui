#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //создание объекта БД для работы с данными
    db = new DataBase();
    //подключение к БД
    db->connectToDataBase();
    //заполнение таблицы рандомным содержимым
    /*
    for(int i = 0; i < 4; i++){
        QVariantList data;
        int random = qrand(); //случайные целые числа
        data.append(QDate::currentDate()); //текущая дата
        data.append(QTime::currentTime()); //текущее время

        data.append(random);

        data.append("Получено сообщение от " + QString::number(random));
        //вставка данных в бд
        db->inserIntoTable(data);
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

//модель представления таблицы
//void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
void MainWindow::setupModel(const QString &tableName)
{
    //установка имени таблицы
    model = new QSqlTableModel(this);
    model->setTable(tableName);

//    //названия колонок с сортировкой данных
//    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
//        model->setHeaderData(i,Qt::Horizontal,headers[j]);
//    }
    //сортировка по возрастанию по полю Code
    model->setSort(0,Qt::AscendingOrder);
}

void MainWindow::createUI()
{
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0, true); //скрыть колонку с кодом записей
    //выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //размер колонок
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    model->select();
}
//Открыть таблицу
void MainWindow::on_pushButton_clicked()
{
     qDebug() << "Button1 is clicked";
     ui->tableView->show();
    QString table = ui->lineEdit_3->text();
     //название колонок таблицы
//     this->setupModel(table,
//                      QStringList() << QString("Code")
//                                    << QString("Clothes")
//                                    << QString("Price")
//                );
    this->setupModel(table);

     //внешний вид таблицы с данными
     this->createUI();
}
//Закрыть таблицу
void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "Button3 is clicked";
    ui->tableView->hide();
}
//Создать таблицу
void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "Button4 is clicked";
    QString table = ui->lineEdit_3->text();
    QSqlQuery query;
    query.exec("CREATE TABLE "+table);
}
//Внести запись
void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "Button2 is clicked";
    QString clothes = ui->lineEdit->text();
    QString price = ui->lineEdit_2->text();
    QString table = ui->lineEdit_3->text();
    //с помощью запроса
    QSqlQuery query;
    query.exec("INSERT INTO " +table+ " ("
                            TABLE_CLOTHES   " ,"
                            TABLE_PRICE     " )"
                "VALUES (' " +clothes+ "', " +price+ ");"
                    );
    //"+ui->lineEdit->text()+"
    //"+ui->lineEdit_2->text().toInt()+"
    this->on_pushButton_clicked(); //обновление таблицы
}
//Создать запрос
void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << "Button5 is clicked";
    QString text = ui->lineEdit_4->text();
    QSqlQuery query;
    query.exec(text);
}
//Удалить таблицу
void MainWindow::on_pushButton_6_clicked()
{
    qDebug() << "Button6 is clicked";
    QString table = ui->lineEdit_3->text();
    QSqlQuery query;
    query.exec("DROP TABLE "+table);
}
//очистка полей для ввода записи
void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}
