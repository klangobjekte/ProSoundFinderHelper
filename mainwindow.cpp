#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->deletePrefsPushButton,SIGNAL(clicked()),
            this,SLOT(on_deletePrefsPushButton_Clicked()));
    ui->label->setText("");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deletePrefsPushButton_Clicked(){

    //QSettings settings;
    QSettings settings("KlangObjekte.", "ProSoundFinder2");
    //settings.fileName();
    qDebug()<< "settings: " << settings.fileName();
    //"\HKEY_CURRENT_USER\Software\KlangObjekte\ProSoundFinder2"
    settings.clear();
    settings.deleteLater();
    ui->label->setText("Preferences Deleted!");

}
