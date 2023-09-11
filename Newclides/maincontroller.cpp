#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

//Select directory for storage of databases - future implementation
void MainController::selectDirectory(){
    QString dir = QFileDialog::getExistingDirectory(Q_NULLPTR, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    s_SelectedDirectory = dir.trimmed();
    emit dirPathToQml(s_SelectedDirectory);
    s_SelectedDirectory.clear();
}

void MainController::buildModel(QString storagePath, QString mass_Num, QString atomic_Mass){
    //Get the current date and time
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");

    emit buildModelStatusMessage("Build model process started @ " + dateTimeString + "\n");
    confirmedStoragePath = storagePath;
    i_massNum = mass_Num.toInt();
    i_AtomicMass = atomic_Mass.toInt();
    i_numOfNeutrons = i_massNum - i_AtomicMass;

    emit buildModelStatusMessage( "The selected path is: " + confirmedStoragePath);
    emit buildModelStatusMessage( "The mass number is: " + mass_Num);
    emit buildModelStatusMessage( "The atomic mass is: " + atomic_Mass);
    emit buildModelStatusMessage( "The number of neutrons is: " + QString::number(i_numOfNeutrons));

    //Find the nuclide by atomic mass number search;
    i_Count = i_AtomicMass;
    while(nuclideFound == false && i_Count != 117){
        if(atomic_Mass == "1"){
            identifiedNuclide = "H";
            nuclideFound = true;
        }
        else if(atomic_Mass == "2"){
            identifiedNuclide = "He";
            nuclideFound = true;
        }
        else if(atomic_Mass == "3"){
            identifiedNuclide = "Li";
            nuclideFound = true;
        }
        else if(atomic_Mass == "4"){
            identifiedNuclide = "Be";
            nuclideFound = true;
        }
        else if(atomic_Mass == "5"){
            identifiedNuclide = "B";
            nuclideFound = true;
        }
        else if(atomic_Mass == "6"){
            identifiedNuclide = "C";
            nuclideFound = true;
        }
        else if(atomic_Mass == "7"){
            identifiedNuclide = "N";
            nuclideFound = true;
        }
        else if(atomic_Mass == "8"){
            identifiedNuclide = "O";
            nuclideFound = true;
        }
        else if(atomic_Mass == "9"){
            identifiedNuclide = "F";
            nuclideFound = true;
        }
        else if(atomic_Mass == "10"){
            identifiedNuclide = "Ne";
            nuclideFound = true;
        }
        else if(atomic_Mass == "11"){
            identifiedNuclide = "Na";
            nuclideFound = true;
        }
        else if(atomic_Mass == "12"){
            identifiedNuclide = "Mg";
            nuclideFound = true;
        }
        else if(atomic_Mass == "13"){
            identifiedNuclide = "Al";
            nuclideFound = true;
        }
        else if(atomic_Mass == "14"){
            identifiedNuclide = "Si";
            nuclideFound = true;
        }
        else if(atomic_Mass == "15"){
            identifiedNuclide = "P";
            nuclideFound = true;
        }
        else if(atomic_Mass == "16"){
            identifiedNuclide = "S";
            nuclideFound = true;
        }
        else if(atomic_Mass == "17"){
            identifiedNuclide = "Cl";
            nuclideFound = true;
        }
        else if(atomic_Mass == "18"){
            identifiedNuclide = "Ar";
            nuclideFound = true;
        }
        else if(atomic_Mass == "19"){
            identifiedNuclide = "K";
            nuclideFound = true;
        }
        else if(atomic_Mass == "20"){
            identifiedNuclide = "Ca";
            nuclideFound = true;
        }
        else if(atomic_Mass == "21"){
            identifiedNuclide = "Sc";
            nuclideFound = true;
        }
        else if(atomic_Mass == "21"){
            identifiedNuclide = "Ti";
            nuclideFound = true;
        }
        else if(atomic_Mass == "23"){
            identifiedNuclide = "V";
            nuclideFound = true;
        }
        else if(atomic_Mass == "24"){
            identifiedNuclide = "Cr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "25"){
            identifiedNuclide = "MN";
            nuclideFound = true;
        }
        else if(atomic_Mass == "26"){
            identifiedNuclide = "Fe";
            nuclideFound = true;
        }
        else if(atomic_Mass == "27"){
            identifiedNuclide = "Co";
            nuclideFound = true;
        }
        else if(atomic_Mass == "28"){
            identifiedNuclide = "Ni";
            nuclideFound = true;
        }
        else if(atomic_Mass == "29"){
            identifiedNuclide = "Cu";
            nuclideFound = true;
        }
        else if(atomic_Mass == "30"){
            identifiedNuclide = "Zn";
            nuclideFound = true;
        }
        else if(atomic_Mass == "31"){
            identifiedNuclide = "Ga";
            nuclideFound = true;
        }
        else if(atomic_Mass == "32"){
            identifiedNuclide = "Ge";
            nuclideFound = true;
        }
        else if(atomic_Mass == "33"){
            identifiedNuclide = "As";
            nuclideFound = true;
        }
        else if(atomic_Mass == "34"){
            identifiedNuclide = "Se";
            nuclideFound = true;
        }
        else if(atomic_Mass == "35"){
            identifiedNuclide = "Br";
            nuclideFound = true;
        }
        else if(atomic_Mass == "36"){
            identifiedNuclide = "Kr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "37"){
            identifiedNuclide = "Rb";
            nuclideFound = true;
        }
        else if(atomic_Mass == "38"){
            identifiedNuclide = "Sr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "39"){
            identifiedNuclide = "Y";
            nuclideFound = true;
        }
        else if(atomic_Mass == "40"){
            identifiedNuclide = "Zr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "41"){
            identifiedNuclide = "Nb";
            nuclideFound = true;
        }
        else if(atomic_Mass == "42"){
            identifiedNuclide = "Mo";
            nuclideFound = true;
        }
        else if(atomic_Mass == "43"){
            identifiedNuclide = "Tc";
            nuclideFound = true;
        }
        else if(atomic_Mass == "44"){
            identifiedNuclide = "Ru";
            nuclideFound = true;
        }
        else if(atomic_Mass == "45"){
            identifiedNuclide = "Rh";
            nuclideFound = true;
        }
        else if(atomic_Mass == "46"){
            identifiedNuclide = "Pd";
            nuclideFound = true;
        }
        else if(atomic_Mass == "47"){
            identifiedNuclide = "Ag";
            nuclideFound = true;
        }
        else if(atomic_Mass == "48"){
            identifiedNuclide = "Cd";
            nuclideFound = true;
        }
        else if(atomic_Mass == "49"){
            identifiedNuclide = "In";
            nuclideFound = true;
        }
        else if(atomic_Mass == "50"){
            identifiedNuclide = "Sn";
            nuclideFound = true;
        }
        else if(atomic_Mass == "51"){
            identifiedNuclide = "Sb";
            nuclideFound = true;
        }
        else if(atomic_Mass == "52"){
            identifiedNuclide = "Te";
            nuclideFound = true;
        }
        else if(atomic_Mass == "53"){
            identifiedNuclide = "I";
            nuclideFound = true;
        }
        else if(atomic_Mass == "54"){
            identifiedNuclide = "Xe";
            nuclideFound = true;
        }
        else if(atomic_Mass == "55"){
            identifiedNuclide = "Cs";
            nuclideFound = true;
        }
        else if(atomic_Mass == "56"){
            identifiedNuclide = "Ba";
            nuclideFound = true;
        }
        else if(atomic_Mass == "57"){
            identifiedNuclide = "La";
            nuclideFound = true;
        }
        else if(atomic_Mass == "58"){
            identifiedNuclide = "Ce";
            nuclideFound = true;
        }
        else if(atomic_Mass == "59"){
            identifiedNuclide = "Pr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "60"){
            identifiedNuclide = "Nd";
            nuclideFound = true;
        }
        else if(atomic_Mass == "61"){
            identifiedNuclide = "Pm";
            nuclideFound = true;
        }
        else if(atomic_Mass == "62"){
            identifiedNuclide = "Sm";
            nuclideFound = true;
        }
        else if(atomic_Mass == "63"){
            identifiedNuclide = "Eu";
            nuclideFound = true;
        }
        else if(atomic_Mass == "64"){
            identifiedNuclide = "Gd";
            nuclideFound = true;
        }
        else if(atomic_Mass == "65"){
            identifiedNuclide = "Tb";
            nuclideFound = true;
        }
        else if(atomic_Mass == "66"){
            identifiedNuclide = "Dy";
            nuclideFound = true;
        }
        else if(atomic_Mass == "67"){
            identifiedNuclide = "Ho";
            nuclideFound = true;
        }
        else if(atomic_Mass == "68"){
            identifiedNuclide = "Er";
            nuclideFound = true;
        }
        else if(atomic_Mass == "69"){
            identifiedNuclide = "Tm";
            nuclideFound = true;
        }
        else if(atomic_Mass == "70"){
            identifiedNuclide = "Yb";
            nuclideFound = true;
        }
        else if(atomic_Mass == "71"){
            identifiedNuclide = "Lu";
            nuclideFound = true;
        }
        else if(atomic_Mass == "72"){
            identifiedNuclide = "Hf";
            nuclideFound = true;
        }
        else if(atomic_Mass == "73"){
            identifiedNuclide = "Ta";
            nuclideFound = true;
        }
        else if(atomic_Mass == "74"){
            identifiedNuclide = "W";
            nuclideFound = true;
        }
        else if(atomic_Mass == "75"){
            identifiedNuclide = "Re";
            nuclideFound = true;
        }
        else if(atomic_Mass == "76"){
            identifiedNuclide = "Os";
            nuclideFound = true;
        }
        else if(atomic_Mass == "77"){
            identifiedNuclide = "Ir";
            nuclideFound = true;
        }
        else if(atomic_Mass == "78"){
            identifiedNuclide = "Pt";
            nuclideFound = true;
        }
        else if(atomic_Mass == "79"){
            identifiedNuclide = "Au";
            nuclideFound = true;
        }
        else if(atomic_Mass == "80"){
            identifiedNuclide = "Hg";
            nuclideFound = true;
        }
        else if(atomic_Mass == "81"){
            identifiedNuclide = "Tl";
            nuclideFound = true;
        }
        else if(atomic_Mass == "82"){
            identifiedNuclide = "Pb";
            nuclideFound = true;
        }
        else if(atomic_Mass == "83"){
            identifiedNuclide = "Bi";
            nuclideFound = true;
        }
        else if(atomic_Mass == "84"){
            identifiedNuclide = "Po";
            nuclideFound = true;
        }
        else if(atomic_Mass == "85"){
            identifiedNuclide = "At";
            nuclideFound = true;
        }
        else if(atomic_Mass == "86"){
            identifiedNuclide = "Rn";
            nuclideFound = true;
        }
        else if(atomic_Mass == "87"){
            identifiedNuclide = "Fr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "88"){
            identifiedNuclide = "Ea";
            nuclideFound = true;
        }
        else if(atomic_Mass == "89"){
            identifiedNuclide = "Ac";
            nuclideFound = true;
        }
        else if(atomic_Mass == "90"){
            identifiedNuclide = "Th";
            nuclideFound = true;
        }
        else if(atomic_Mass == "91"){
            identifiedNuclide = "Pa";
            nuclideFound = true;
        }
        else if(atomic_Mass == "92"){
            identifiedNuclide = "U";
            nuclideFound = true;
        }
        else if(atomic_Mass == "93"){
            identifiedNuclide = "Np";
            nuclideFound = true;
        }
        else if(atomic_Mass == "94"){
            identifiedNuclide = "Pu";
            nuclideFound = true;
        }
        else if(atomic_Mass == "95"){
            identifiedNuclide = "Am";
            nuclideFound = true;
        }
        else if(atomic_Mass == "96"){
            identifiedNuclide = "Cm";
            nuclideFound = true;
        }
        else if(atomic_Mass == "97"){
            identifiedNuclide = "Bk";
            nuclideFound = true;
        }
        else if(atomic_Mass == "98"){
            identifiedNuclide = "Cf";
            nuclideFound = true;
        }
        else if(atomic_Mass == "99"){
            identifiedNuclide = "Es";
            nuclideFound = true;
        }
        else if(atomic_Mass == "100"){
            identifiedNuclide = "Fm";
            nuclideFound = true;
        }
        else if(atomic_Mass == "101"){
            identifiedNuclide = "Md";
            nuclideFound = true;
        }
        else if(atomic_Mass == "102"){
            identifiedNuclide = "No";
            nuclideFound = true;
        }
        else if(atomic_Mass == "103"){
            identifiedNuclide = "Lr";
            nuclideFound = true;
        }
        else if(atomic_Mass == "104"){
            identifiedNuclide = "Rf";
            nuclideFound = true;
        }
        else if(atomic_Mass == "105"){
            identifiedNuclide = "Db";
            nuclideFound = true;
        }
        else if(atomic_Mass == "106"){
            identifiedNuclide = "Sg";
            nuclideFound = true;
        }
        else if(atomic_Mass == "107"){
            identifiedNuclide = "Bh";
            nuclideFound = true;
        }
        else if(atomic_Mass == "108"){
            identifiedNuclide = "Hs";
            nuclideFound = true;
        }
        else if(atomic_Mass == "109"){
            identifiedNuclide = "Mt";
            nuclideFound = true;
        }
        else if(atomic_Mass == "110"){
            identifiedNuclide = "Ds";
            nuclideFound = true;
        }
        else if(atomic_Mass == "111"){
            identifiedNuclide = "Rg";
            nuclideFound = true;
        }
        else if(atomic_Mass == "112"){
            identifiedNuclide = "Cn";
            nuclideFound = true;
        }
        else if(atomic_Mass == "113"){
            identifiedNuclide = "Nh";
            nuclideFound = true;
        }
        else if(atomic_Mass == "114"){
            identifiedNuclide = "Fl";
            nuclideFound = true;
        }
        else if(atomic_Mass == "115"){
            identifiedNuclide = "Mc";
            nuclideFound = true;
        }
        else if(atomic_Mass == "116"){
            identifiedNuclide = "Lv";
            nuclideFound = true;
        }
        else if(atomic_Mass == "117"){
            identifiedNuclide = "TS";
            nuclideFound = true;
        }
        else{
            identifiedNuclide = "Nuclide symbol could not be identified...";
        }
        i_Count++;
    }
    emit buildModelStatusMessage("The nuclide symbol identified is: " + identifiedNuclide);
    emit identifiedNuclideToQml(identifiedNuclide);
    i_Count = 0;
    identifiedNuclide = "";
}
