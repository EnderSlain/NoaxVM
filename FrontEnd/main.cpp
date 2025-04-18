#include "noaxvmui.h"
#include "ImageOverlay.h"
#include <QApplication>
#include <QtCore/qfile.h>
#include <QImage>
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QGroupBox>
#include <QScrollArea>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* central = new QWidget();
    QHBoxLayout* mainLayout = new QHBoxLayout(central);

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

    // top buttons
    QPushButton* fileButton = new QPushButton("File");
    QPushButton* machinesButton = new QPushButton("Machines");
    QPushButton* helpButton = new QPushButton("Help");

    fileButton->setObjectName("fileButton");
    machinesButton->setObjectName("machinesButton");
    helpButton->setObjectName("helpButton");

    fileButton->setFlat(true);
    machinesButton->setFlat(true);
    helpButton->setFlat(true);

    fileButton->setCheckable(true);
    machinesButton->setCheckable(true);
    helpButton->setCheckable(true);

    machinesButton->setChecked(true);

    QObject::connect(fileButton, &QPushButton::clicked, [&]() {
        fileButton->setChecked(true);
        machinesButton->setChecked(false);
        helpButton->setChecked(false);
    });

    QObject::connect(machinesButton, &QPushButton::clicked, [&]() {
        fileButton->setChecked(false);
        machinesButton->setChecked(true);
        helpButton->setChecked(false);
    });

    QObject::connect(helpButton, &QPushButton::clicked, [&]() {
        fileButton->setChecked(false);
        machinesButton->setChecked(false);
        helpButton->setChecked(true);
    });


    QHBoxLayout* topButtonLayout = new QHBoxLayout();
    topButtonLayout->addWidget(fileButton);
    topButtonLayout->addWidget(machinesButton);
    topButtonLayout->addWidget(helpButton);
    topButtonLayout->addStretch();


    //temp data for the left panel

    // Left panel - machine list
    QListWidget* machineList = new QListWidget();
    machineList->setFixedWidth(300);
    machineList->addItem("\n Windows 11 Pro\nCurrently Active");
    machineList->addItem("\n Windows 11 Home\nOffline - Last used: DD/MM/YYYY");
    machineList->addItem("\n Windows 10 Home\nOffline - Last used: DD/MM/YYYY");
    machineList->addItem("\n Windows 10 Pro\nOffline - Last used: DD/MM/YYYY");
    machineList->addItem("\n Ubuntu\nOffline - Last used: DD/MM/YYYY");
    machineList->addItem("\n Linux\nOffline - Last used: DD/MM/YYYY");

    NoaxVMUI w;
    w.setWindowTitle("Noax Vm");
    w.resize(1200,700);
    w.setCentralWidget(central);
    
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
    
    // Right panel - details
    QVBoxLayout* rightPanel = new QVBoxLayout();

    // Toolbar
    QHBoxLayout* toolbar = new QHBoxLayout();
    toolbar->addWidget(NewVMButton);
    toolbar->addWidget(AddVMButton);
    toolbar->addWidget(NoaxVMSettingsButton);
    toolbar->addStretch();

    rightPanel->addLayout(toolbar);
    rightPanel->addStretch();

    QHBoxLayout* headerLayout = new QHBoxLayout();
    headerLayout->addLayout(topButtonLayout);
    headerLayout->addLayout(toolbar);
    headerLayout->addStretch();
    
    QVBoxLayout* leftPanelLayout = new QVBoxLayout();
    leftPanelLayout->addLayout(headerLayout);
    leftPanelLayout->addWidget(machineList);
    leftPanelLayout->addStretch();
    
    mainLayout->addLayout(leftPanelLayout);
    mainLayout->addLayout(rightPanel);

    w.show();
    return a.exec();
}
