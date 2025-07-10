#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addpage.h>
#include <search.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addPage();
    void searchPage();
    void reload();
private:
    Ui::MainWindow *ui;
    AddPage *addpage;
    Search *searchpage;
    void allItens();
};
#endif // MAINWINDOW_H
