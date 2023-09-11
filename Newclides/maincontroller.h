#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <QObject>
#include <QWidget>

//File Ops Libs
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QString>
#include <QDateTime>

#include <QDebug>

class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:
    void dirPathToQml(QString _dirPath);
    void buildModelStatusMessage(QString buildModelMessage);
    void identifiedNuclideToQml(QString identifiedNuclide_);

public slots:
    void selectDirectory();
    void buildModel(QString, QString, QString);

private:
    QString s_SelectedDirectory = "";
    QString confirmedStoragePath = "";
    QString identifiedNuclide = "";

    int i_massNum  = 0;
    int i_AtomicMass = 0;
    int i_numOfNeutrons = 0;
    int i_Count = 117;

    bool nuclideFound = false;

};

#endif // MAINCONTROLLER_H
