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
#include <QDirIterator>
#include <QStringList>

#include <QDebug>

class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:
    void dirPathToQml(QString _dirPath);
    void modelDirPathToQml(QString _modelDir);
    void buildModelStatusMessage(QString buildModelMessage);
    void identifiedNuclideToQml(QString identifiedNuclide_);
    void loadModelNuclideId(QString nuclideId);
    void modelStepNumber(QString _stepNumber);
    void modelStepSpin(QString _spin);
    void x1ToQml(QString x1Val);
    void x2ToQml(QString x2Val);
    void x3ToQml(QString x3Val);
    void x4ToQml(QString x4Val);
    void x5ToQml(QString x5Val);
    void x6ToQml(QString x6Val);

public slots:
    void selectDirectory();
    void selectModelDirectory();
    void buildModel(QString, QString, QString);
    void saveModelBuildDataToFile(QString, QString, QString, QString, QString, QString, QString, QString);
    void loadModelData(QString);
    void modelViewerStepControl(QString, QString);
    void clearLoadedModelFileList();

private:
    QString s_SelectedDirectory = "";
    QString confirmedStoragePath = "";
    QString identifiedNuclide = "";
    QString s_SelectedModelDir = "";

    int i_massNum  = 0;
    int i_Atomic_Number= 0;
    int i_numOfNeutrons = 0;

    int i_Count = 117;

    int p_NumOfHexCanBeBuilt = 0;
    int p_Remainder = 0;

    int n_NumOfHexCanBeBuilt = 0;
    int n_Remainder = 0;

    bool nuclideFound = false;
    bool oddNumberNeutrons = false;
    bool oddNumberProtons = false;
    bool spinSwitch = false;

    //build model variables
    int m_NumOfHexToBuild = 0;
    int remainderNeutrons = 0;
    int remainderProtons = 0;
    int ModelStepsCounter = 0;
    int fileLineCounter = 0;

    QString m_Step = "";
    QString m_Spin = "";


    QString x1 = "";
    QString x2 = "";
    QString x3 = "";
    QString x4 = "";
    QString x5 = "";
    QString x6 = "";

    QStringList modelFilesList;
    QStringList nuclideSymbolList;
    QStringList nuclideNameList;
    QString selectedFile = "";
};

#endif // MAINCONTROLLER_H
