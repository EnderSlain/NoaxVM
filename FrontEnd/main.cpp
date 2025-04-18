#include "noaxvmui.h"
#include "ImageOverlay.h"
#include <QApplication>
#include <QtCore/qfile.h>
#include <QImage>
#include <QPushButton>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/styles/NoaxVM_Style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        a.setStyleSheet(styleSheet);
        file.close();
    } else {
        qDebug() << "Failed to load QSS file from disk!";
    }

    QImage AddVM = QImage(":/images/add-categories-icon.ico");
    QImage NewVM = QImage(":/images/plus-icon.ico");
    QImage NoaxVMSettings = QImage(":/images/setting-icon.ico");
    QImage VMSettings = QImage(":/images/setting-icon.ico");


    QColor OverlayBlue(72,242,255);
    QColor OverlayGreen(0,255,0);
    QColor OverlayGold(255,159,10);
    QColor OverlayGray(91,98,111);

    QImage AddVMOverlay = ImageOverlay::applyOverlay(AddVM,OverlayBlue);
    QImage NewVMOverlay = ImageOverlay::applyOverlay(NewVM, OverlayGreen);
    QImage NoaxVMSettingsOverlay = ImageOverlay::applyOverlay(NoaxVMSettings, OverlayGold);
    QImage SelectedVMSettingsOverlay = ImageOverlay::applyOverlay(VMSettings, OverlayBlue);

    NoaxVMUI w;
    w.setWindowTitle("Noax Vm");

    QPushButton* AddVMButton = new QPushButton(&w);
    QPixmap AddVMMap = QPixmap::fromImage(AddVMOverlay);
    AddVMButton->setIcon(QIcon(AddVMMap));
    AddVMButton->resize(24,26);
    AddVMButton->setIconSize(QSize(24,26));

    QPushButton* NewVMButton = new QPushButton(&w);
    QPixmap NewVMMap = QPixmap::fromImage(NewVMOverlay);
    NewVMButton->setIcon(QIcon(NewVMMap));
    NewVMButton->resize(24,26);
    NewVMButton->setIconSize(QSize(24,26));

    QPushButton* NoaxVMSettingsButton = new QPushButton(&w);
    QPixmap MainSettingsMap = QPixmap::fromImage(NoaxVMSettingsOverlay);
    NoaxVMSettingsButton->setIcon(QIcon(MainSettingsMap));
    NoaxVMSettingsButton->resize(24,26);
    NoaxVMSettingsButton->setIconSize(QSize(24,26));

    w.show();
    return a.exec();
}
