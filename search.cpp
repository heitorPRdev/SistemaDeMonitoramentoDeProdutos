#include "search.h"
#include "ui_search.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QStringListModel>
Search::Search(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Search)
{
    ui->setupUi(this);
    connect(ui ->btnPesquisar, SIGNAL(clicked()),this,SLOT(searching()));
}

Search::~Search()
{
    delete ui;
}
void Search::searching(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mercado");
    db.setPort(3306);
    db.setHostName("localhost");
    db.setPassword("teste");
    db.setUserName("teste");
    bool ok = db.open();
    if(ok){
        QSqlQuery query;

        QStringListModel *model;
        model = new QStringListModel(this);
        QStringList list;
        QString sql= "SELECT item FROM produtos WHERE item LIKE '%"+ui->leItem->text()+"%'";
        query.exec(sql);
        while(query.next()){
            QString itens = query.value(0).toString();
            list.append(itens);
        }
        model->setStringList(list);
        ui->lvItens->setModel(model);
        query.exec("SELECT COUNT(item) FROM produtos WHERE item LIKE '%"+ui->leItem->text()+"%'");
        while(query.next()){
            QString total=query.value(0).toString();
            ui ->  lTotal -> setText("Total: "+total);
        }
    }
}
