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
    int i_Atomic_Number= 0;
    int i_numOfNeutrons = 0;
    //int i_numOfProtons = 0:
    int i_Count = 117;
    int modulusManiplualtor = 0;
    int numberManipulator = 0;

    int p_NumOfHexCanBeBuilt = 0;
    int p_Remainder = 0;

    int n_NumOfHexCanBeBuilt = 0;
    int n_Remainder = 0;


    bool nuclideFound = false;
    bool oddNumberNeutrons = false;
    bool oddNumberProtons = false;



};

#endif // MAINCONTROLLER_H
