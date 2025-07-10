#include "addpage.h"
#include "ui_addpage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
AddPage::AddPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPage)
{
    ui->setupUi(this);
    connect(ui -> btnAdd,SIGNAL(clicked()),this,SLOT(add()));
}

AddPage::~AddPage()
{
    delete ui;
}
void AddPage::add(){
    QString item = ui-> leItem-> text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mercado");
    db.setPort(3306);
    db.setHostName("localhost");
    db.setPassword("teste");
    db.setUserName("teste");
    bool ok = db.open();

    if(ok){
        QSqlQuery query;
        query.prepare("INSERT INTO produtos(item) VALUES(:item)");
        query.bindValue(":item",item);
        query.exec();
        ui->lRes ->setText("Produto adicionado com sucesso");
    }
}
