#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QDebug"
#include "QProcess"
#include "QFileInfo"
#include "QDir"

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



#ifdef WIN32
    QSettings settings("KlangObjekte", "ProSoundFinder2");
#else
    QSettings settings("KlangObjekte.", "ProSoundFinder2");

#endif
    //settings.fileName();
    qDebug()<< "settings: " << settings.fileName();
    //"\HKEY_CURRENT_USER\Software\KlangObjekte\ProSoundFinder2"
    QProcess process;
    QStringList argumentStringList;
    argumentStringList.append("777");
    argumentStringList.append(settings.fileName());
    QFileInfo info(settings.fileName());
    //if(info.exists())
    //{
    bool success = process.startDetached("chmod",argumentStringList);
    process.close();
    qDebug() << "chmod" << settings.fileName()  << success;
    //QString newsettingsPath = QApplication::applicationDirPath().append(QDir::separator()).append("set");
    //if(QDir(newsettingsPath).exists()){
    //  QSettings  *settings = new QSettings(newsettingsPath.append(QDir::separator()).append("set.ini"),QSettings::NativeFormat);
    //}

    qDebug() << "settings.isWritable()" << settings.isWritable();
    settings.clear();
    settings.deleteLater();
    ui->label->setText("Preferences Deleted!");

    //}
    //else{
    //    qDebug() << "no Preferences Found";
    //ui->label->setText("no Preferences Found!");
    //}




}
