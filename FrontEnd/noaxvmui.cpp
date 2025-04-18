#include "noaxvmui.h"
#include "./ui_noaxvmui.h"
#include <QImage>
#include <QPainter>
#include <QColor>


NoaxVMUI::NoaxVMUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NoaxVMUI)
{
    ui->setupUi(this);
}

NoaxVMUI::~NoaxVMUI()
{
    delete ui;
}