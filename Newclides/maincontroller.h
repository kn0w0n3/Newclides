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
    void idNuclideNameToQml(QString idNuclideName);
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

    int p_NumHexHalvesCanBeBuilt = 0;
    int p_Remainder = 0;

    int n_NumHexHalvesCanBeBuilt = 0;
    int n_Remainder = 0;

    //bool nuclideFound = false;
    bool oddNumberNeutrons = false;
    bool oddNumberProtons = false;
    bool spinSwitch = false;

    //build model variables
    int m_NumOfHexToBuild = 0;
    int remainderNeutronHalves = 0;
    int remainderProtonHalves = 0;
    int ModelStepsCounter = 0;
    int fileLineCounter = 0;



    QString selectedFile = "";
    QString m_Step = "";
    QString m_Spin = "";


    QString x1 = "";
    QString x2 = "";
    QString x3 = "";
    QString x4 = "";
    QString x5 = "";
    QString x6 = "";


    QStringList modelFilesList;
    QStringList nuclideSymbolList = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                                  "Na","Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K","Ca",
                                  "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                                  "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
                                  "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                                  "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                                  "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                                  "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
                                  "Ti", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                                  "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                                  "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                                  "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    QStringList nuclideNameList = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
                                     "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium","Calcium",
                                     "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "	Nickel", "	Copper", "Zinc",
                                     "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
                                     "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
                                     "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                                     "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
                                     "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
                                     "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Thorium", "Protactinium",
                                     "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium",
                                     "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium",
                                     "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

};

#endif // MAINCONTROLLER_H
