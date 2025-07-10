#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QDialog>

namespace Ui {
class AddPage;
}

class AddPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddPage(QWidget *parent = nullptr);
    ~AddPage();
private slots:
    void add();
private:
    Ui::AddPage *ui;
};

#endif // ADDPAGE_H
