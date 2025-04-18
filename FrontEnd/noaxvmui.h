#ifndef NOAXVMUI_H
#define NOAXVMUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class NoaxVMUI;
}
QT_END_NAMESPACE

class NoaxVMUI : public QMainWindow
{
    Q_OBJECT

public:
    NoaxVMUI(QWidget *parent = nullptr);
    ~NoaxVMUI();

private:
    Ui::NoaxVMUI *ui;
};
#endif // NOAXVMUI_H
