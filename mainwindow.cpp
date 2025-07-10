#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QStringListModel>

void MainWindow::allItens(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mercado");
    db.setPort(3306);
    db.setHostName("localhost");
    db.setPassword("teste");
    db.setUserName("teste");
    bool ok = db.open();
    if(ok){
        QSqlQuery query;
        query.exec("SELECT item FROM produtos");
        QStringListModel *model;
        model = new QStringListModel(this);
        QStringList list;
        while(query.next()){
            QString item = query.value(0).toString();

            list.append(item);
        }
        model -> setStringList(list);
        ui -> lvProdutos -> setModel(model);
        query.exec("SELECT COUNT(item) FROM produtos");
        while(query.next()){
            QString total=query.value(0).toString();
            ui ->  lTotal -> setText("Total: "+total);
        }
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnAdd, SIGNAL(clicked()),this,SLOT(addPage()));
    connect(ui->btnPesq,SIGNAL(clicked()),this,SLOT(searchPage()));
    connect(ui->tbtnReload,SIGNAL(clicked()),this,SLOT(reload()));

    allItens();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addPage(){
    addpage = new AddPage(this);
    addpage->show();
}
void MainWindow::searchPage(){
    searchpage = new Search(this);
    searchpage -> show();
}
void MainWindow::reload(){
    allItens();
}
