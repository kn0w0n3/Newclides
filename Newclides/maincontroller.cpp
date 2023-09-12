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

void MainController::selectModelDirectory(){
    QString dir = QFileDialog::getExistingDirectory(Q_NULLPTR, tr("Select Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    s_SelectedModelDir = dir.trimmed();
    emit modelDirPathToQml(s_SelectedModelDir);
    s_SelectedModelDir.clear();
}

void MainController::buildModel(QString storagePath, QString mass_Num, QString atomic_number){
    //Get the current date and time
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");

    emit buildModelStatusMessage("Build model process started @ " + dateTimeString + "\n");
    confirmedStoragePath = storagePath;

    //Mass Number: The total number of protons and neutrons in a nucleus.
    i_massNum = mass_Num.toInt();

    //Atomic Number: The number of protons
    i_Atomic_Number = atomic_number.toInt();

    //Subtract the number of prontons from the mass number to find the number of neutrons
    i_numOfNeutrons = i_massNum - i_Atomic_Number;

    emit buildModelStatusMessage( "The selected path is: " + confirmedStoragePath);
    emit buildModelStatusMessage( "The mass number is: " + mass_Num);
    emit buildModelStatusMessage( "The atomic number is: " + atomic_number);
    emit buildModelStatusMessage( "The number of protons is: " + atomic_number);
    emit buildModelStatusMessage( "The number of neutrons is: " + QString::number(i_numOfNeutrons));

    //Check if the number of protons is even or odd
    if(i_Atomic_Number % 2 == 0){
        oddNumberProtons = false;
        emit buildModelStatusMessage( "The number of protons is even");
    }
    else if(i_Atomic_Number % 2 != 0){
        oddNumberProtons = true;
         emit buildModelStatusMessage( "The number of protons is odd");
    }

    //Check if the number of neutrons is even or odd
    if(i_numOfNeutrons % 2 == 0){
         oddNumberNeutrons = false;
         emit buildModelStatusMessage( "The number of neutrons is even:");
    }
    else if(i_numOfNeutrons % 2 != 0){
         oddNumberNeutrons = true;
         emit buildModelStatusMessage( "The number of neutrons is odd:");
    }

    //Find the nuclide by atomic mass number search;
    i_Count = i_Atomic_Number;
    while(nuclideFound == false && i_Count != 117){
        if(atomic_number == "1"){
            identifiedNuclide = "H";
            nuclideFound = true;
        }
        else if(atomic_number == "2"){
            identifiedNuclide = "He";
            nuclideFound = true;
        }
        else if(atomic_number == "3"){
            identifiedNuclide = "Li";
            nuclideFound = true;
        }
        else if(atomic_number == "4"){
            identifiedNuclide = "Be";
            nuclideFound = true;
        }
        else if(atomic_number == "5"){
            identifiedNuclide = "B";
            nuclideFound = true;
        }
        else if(atomic_number == "6"){
            identifiedNuclide = "C";
            nuclideFound = true;
        }
        else if(atomic_number == "7"){
            identifiedNuclide = "N";
            nuclideFound = true;
        }
        else if(atomic_number == "8"){
            identifiedNuclide = "O";
            nuclideFound = true;
        }
        else if(atomic_number == "9"){
            identifiedNuclide = "F";
            nuclideFound = true;
        }
        else if(atomic_number == "10"){
            identifiedNuclide = "Ne";
            nuclideFound = true;
        }
        else if(atomic_number == "11"){
            identifiedNuclide = "Na";
            nuclideFound = true;
        }
        else if(atomic_number == "12"){
            identifiedNuclide = "Mg";
            nuclideFound = true;
        }
        else if(atomic_number == "13"){
            identifiedNuclide = "Al";
            nuclideFound = true;
        }
        else if(atomic_number == "14"){
            identifiedNuclide = "Si";
            nuclideFound = true;
        }
        else if(atomic_number == "15"){
            identifiedNuclide = "P";
            nuclideFound = true;
        }
        else if(atomic_number == "16"){
            identifiedNuclide = "S";
            nuclideFound = true;
        }
        else if(atomic_number == "17"){
            identifiedNuclide = "Cl";
            nuclideFound = true;
        }
        else if(atomic_number == "18"){
            identifiedNuclide = "Ar";
            nuclideFound = true;
        }
        else if(atomic_number == "19"){
            identifiedNuclide = "K";
            nuclideFound = true;
        }
        else if(atomic_number == "20"){
            identifiedNuclide = "Ca";
            nuclideFound = true;
        }
        else if(atomic_number == "21"){
            identifiedNuclide = "Sc";
            nuclideFound = true;
        }
        else if(atomic_number == "21"){
            identifiedNuclide = "Ti";
            nuclideFound = true;
        }
        else if(atomic_number == "23"){
            identifiedNuclide = "V";
            nuclideFound = true;
        }
        else if(atomic_number == "24"){
            identifiedNuclide = "Cr";
            nuclideFound = true;
        }
        else if(atomic_number == "25"){
            identifiedNuclide = "MN";
            nuclideFound = true;
        }
        else if(atomic_number == "26"){
            identifiedNuclide = "Fe";
            nuclideFound = true;
        }
        else if(atomic_number == "27"){
            identifiedNuclide = "Co";
            nuclideFound = true;
        }
        else if(atomic_number == "28"){
            identifiedNuclide = "Ni";
            nuclideFound = true;
        }
        else if(atomic_number == "29"){
            identifiedNuclide = "Cu";
            nuclideFound = true;
        }
        else if(atomic_number == "30"){
            identifiedNuclide = "Zn";
            nuclideFound = true;
        }
        else if(atomic_number == "31"){
            identifiedNuclide = "Ga";
            nuclideFound = true;
        }
        else if(atomic_number == "32"){
            identifiedNuclide = "Ge";
            nuclideFound = true;
        }
        else if(atomic_number == "33"){
            identifiedNuclide = "As";
            nuclideFound = true;
        }
        else if(atomic_number == "34"){
            identifiedNuclide = "Se";
            nuclideFound = true;
        }
        else if(atomic_number == "35"){
            identifiedNuclide = "Br";
            nuclideFound = true;
        }
        else if(atomic_number == "36"){
            identifiedNuclide = "Kr";
            nuclideFound = true;
        }
        else if(atomic_number == "37"){
            identifiedNuclide = "Rb";
            nuclideFound = true;
        }
        else if(atomic_number == "38"){
            identifiedNuclide = "Sr";
            nuclideFound = true;
        }
        else if(atomic_number == "39"){
            identifiedNuclide = "Y";
            nuclideFound = true;
        }
        else if(atomic_number == "40"){
            identifiedNuclide = "Zr";
            nuclideFound = true;
        }
        else if(atomic_number == "41"){
            identifiedNuclide = "Nb";
            nuclideFound = true;
        }
        else if(atomic_number == "42"){
            identifiedNuclide = "Mo";
            nuclideFound = true;
        }
        else if(atomic_number == "43"){
            identifiedNuclide = "Tc";
            nuclideFound = true;
        }
        else if(atomic_number == "44"){
            identifiedNuclide = "Ru";
            nuclideFound = true;
        }
        else if(atomic_number == "45"){
            identifiedNuclide = "Rh";
            nuclideFound = true;
        }
        else if(atomic_number == "46"){
            identifiedNuclide = "Pd";
            nuclideFound = true;
        }
        else if(atomic_number == "47"){
            identifiedNuclide = "Ag";
            nuclideFound = true;
        }
        else if(atomic_number == "48"){
            identifiedNuclide = "Cd";
            nuclideFound = true;
        }
        else if(atomic_number == "49"){
            identifiedNuclide = "In";
            nuclideFound = true;
        }
        else if(atomic_number == "50"){
            identifiedNuclide = "Sn";
            nuclideFound = true;
        }
        else if(atomic_number == "51"){
            identifiedNuclide = "Sb";
            nuclideFound = true;
        }
        else if(atomic_number == "52"){
            identifiedNuclide = "Te";
            nuclideFound = true;
        }
        else if(atomic_number == "53"){
            identifiedNuclide = "I";
            nuclideFound = true;
        }
        else if(atomic_number == "54"){
            identifiedNuclide = "Xe";
            nuclideFound = true;
        }
        else if(atomic_number == "55"){
            identifiedNuclide = "Cs";
            nuclideFound = true;
        }
        else if(atomic_number == "56"){
            identifiedNuclide = "Ba";
            nuclideFound = true;
        }
        else if(atomic_number == "57"){
            identifiedNuclide = "La";
            nuclideFound = true;
        }
        else if(atomic_number == "58"){
            identifiedNuclide = "Ce";
            nuclideFound = true;
        }
        else if(atomic_number == "59"){
            identifiedNuclide = "Pr";
            nuclideFound = true;
        }
        else if(atomic_number == "60"){
            identifiedNuclide = "Nd";
            nuclideFound = true;
        }
        else if(atomic_number == "61"){
            identifiedNuclide = "Pm";
            nuclideFound = true;
        }
        else if(atomic_number == "62"){
            identifiedNuclide = "Sm";
            nuclideFound = true;
        }
        else if(atomic_number == "63"){
            identifiedNuclide = "Eu";
            nuclideFound = true;
        }
        else if(atomic_number == "64"){
            identifiedNuclide = "Gd";
            nuclideFound = true;
        }
        else if(atomic_number == "65"){
            identifiedNuclide = "Tb";
            nuclideFound = true;
        }
        else if(atomic_number == "66"){
            identifiedNuclide = "Dy";
            nuclideFound = true;
        }
        else if(atomic_number == "67"){
            identifiedNuclide = "Ho";
            nuclideFound = true;
        }
        else if(atomic_number == "68"){
            identifiedNuclide = "Er";
            nuclideFound = true;
        }
        else if(atomic_number == "69"){
            identifiedNuclide = "Tm";
            nuclideFound = true;
        }
        else if(atomic_number == "70"){
            identifiedNuclide = "Yb";
            nuclideFound = true;
        }
        else if(atomic_number == "71"){
            identifiedNuclide = "Lu";
            nuclideFound = true;
        }
        else if(atomic_number == "72"){
            identifiedNuclide = "Hf";
            nuclideFound = true;
        }
        else if(atomic_number == "73"){
            identifiedNuclide = "Ta";
            nuclideFound = true;
        }
        else if(atomic_number == "74"){
            identifiedNuclide = "W";
            nuclideFound = true;
        }
        else if(atomic_number == "75"){
            identifiedNuclide = "Re";
            nuclideFound = true;
        }
        else if(atomic_number == "76"){
            identifiedNuclide = "Os";
            nuclideFound = true;
        }
        else if(atomic_number == "77"){
            identifiedNuclide = "Ir";
            nuclideFound = true;
        }
        else if(atomic_number == "78"){
            identifiedNuclide = "Pt";
            nuclideFound = true;
        }
        else if(atomic_number == "79"){
            identifiedNuclide = "Au";
            nuclideFound = true;
        }
        else if(atomic_number == "80"){
            identifiedNuclide = "Hg";
            nuclideFound = true;
        }
        else if(atomic_number == "81"){
            identifiedNuclide = "Tl";
            nuclideFound = true;
        }
        else if(atomic_number == "82"){
            identifiedNuclide = "Pb";
            nuclideFound = true;
        }
        else if(atomic_number == "83"){
            identifiedNuclide = "Bi";
            nuclideFound = true;
        }
        else if(atomic_number == "84"){
            identifiedNuclide = "Po";
            nuclideFound = true;
        }
        else if(atomic_number == "85"){
            identifiedNuclide = "At";
            nuclideFound = true;
        }
        else if(atomic_number == "86"){
            identifiedNuclide = "Rn";
            nuclideFound = true;
        }
        else if(atomic_number == "87"){
            identifiedNuclide = "Fr";
            nuclideFound = true;
        }
        else if(atomic_number == "88"){
            identifiedNuclide = "Ea";
            nuclideFound = true;
        }
        else if(atomic_number == "89"){
            identifiedNuclide = "Ac";
            nuclideFound = true;
        }
        else if(atomic_number == "90"){
            identifiedNuclide = "Th";
            nuclideFound = true;
        }
        else if(atomic_number == "91"){
            identifiedNuclide = "Pa";
            nuclideFound = true;
        }
        else if(atomic_number == "92"){
            identifiedNuclide = "U";
            nuclideFound = true;
        }
        else if(atomic_number == "93"){
            identifiedNuclide = "Np";
            nuclideFound = true;
        }
        else if(atomic_number == "94"){
            identifiedNuclide = "Pu";
            nuclideFound = true;
        }
        else if(atomic_number == "95"){
            identifiedNuclide = "Am";
            nuclideFound = true;
        }
        else if(atomic_number == "96"){
            identifiedNuclide = "Cm";
            nuclideFound = true;
        }
        else if(atomic_number == "97"){
            identifiedNuclide = "Bk";
            nuclideFound = true;
        }
        else if(atomic_number == "98"){
            identifiedNuclide = "Cf";
            nuclideFound = true;
        }
        else if(atomic_number == "99"){
            identifiedNuclide = "Es";
            nuclideFound = true;
        }
        else if(atomic_number == "100"){
            identifiedNuclide = "Fm";
            nuclideFound = true;
        }
        else if(atomic_number == "101"){
            identifiedNuclide = "Md";
            nuclideFound = true;
        }
        else if(atomic_number == "102"){
            identifiedNuclide = "No";
            nuclideFound = true;
        }
        else if(atomic_number == "103"){
            identifiedNuclide = "Lr";
            nuclideFound = true;
        }
        else if(atomic_number == "104"){
            identifiedNuclide = "Rf";
            nuclideFound = true;
        }
        else if(atomic_number == "105"){
            identifiedNuclide = "Db";
            nuclideFound = true;
        }
        else if(atomic_number == "106"){
            identifiedNuclide = "Sg";
            nuclideFound = true;
        }
        else if(atomic_number == "107"){
            identifiedNuclide = "Bh";
            nuclideFound = true;
        }
        else if(atomic_number == "108"){
            identifiedNuclide = "Hs";
            nuclideFound = true;
        }
        else if(atomic_number == "109"){
            identifiedNuclide = "Mt";
            nuclideFound = true;
        }
        else if(atomic_number == "110"){
            identifiedNuclide = "Ds";
            nuclideFound = true;
        }
        else if(atomic_number == "111"){
            identifiedNuclide = "Rg";
            nuclideFound = true;
        }
        else if(atomic_number == "112"){
            identifiedNuclide = "Cn";
            nuclideFound = true;
        }
        else if(atomic_number == "113"){
            identifiedNuclide = "Nh";
            nuclideFound = true;
        }
        else if(atomic_number == "114"){
            identifiedNuclide = "Fl";
            nuclideFound = true;
        }
        else if(atomic_number == "115"){
            identifiedNuclide = "Mc";
            nuclideFound = true;
        }
        else if(atomic_number == "116"){
            identifiedNuclide = "Lv";
            nuclideFound = true;
        }
        else if(atomic_number == "117"){
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
    //identifiedNuclide = "";

    //Calculate how the protons and neutrons can be evnly divided
    //An odd number divided by an odd number will always be odd.
    if(oddNumberProtons == true){
        p_NumOfHexCanBeBuilt = i_Atomic_Number / 3;
        p_Remainder = i_Atomic_Number % 3;
        //emit buildModelStatusMessage("Number of protons == Odd");
        emit buildModelStatusMessage("The number of hexagons that can be built with the provided number of protons is: " + QString::number(p_NumOfHexCanBeBuilt));
        emit buildModelStatusMessage("The leftover number of protons is: " + QString::number(p_Remainder));
    }
    else if(oddNumberProtons == false){
        p_NumOfHexCanBeBuilt = i_Atomic_Number / 3;
        p_Remainder = i_Atomic_Number % 3;
        //emit buildModelStatusMessage("Number of protons == Even");
        emit buildModelStatusMessage("The number of hexagons that can be built with the provided number of protons is: " + QString::number(p_NumOfHexCanBeBuilt));
        emit buildModelStatusMessage("The leftover number of protons is: " + QString::number(p_Remainder));
    }

    if(oddNumberNeutrons == true){
        n_NumOfHexCanBeBuilt = i_numOfNeutrons / 3;
        n_Remainder = i_numOfNeutrons % 3;
        //emit buildModelStatusMessage("Number of neutrons == Odd");
        emit buildModelStatusMessage("The number of hexagons that can be built with the provided number of neutrons is: " + QString::number(n_NumOfHexCanBeBuilt));
        emit buildModelStatusMessage("The leftover number of neutrons is: " + QString::number(n_Remainder));
    }
    else if(oddNumberNeutrons == false){
        n_NumOfHexCanBeBuilt = i_numOfNeutrons / 3;
        n_Remainder = i_numOfNeutrons % 3;
       // emit buildModelStatusMessage("Number of neutrons = Even");
        emit buildModelStatusMessage("The number of hexagons that can be built with the provided number of neutrons is: " + QString::number(n_NumOfHexCanBeBuilt));
        emit buildModelStatusMessage("The leftover number of neutrons is: " + QString::number(n_Remainder));
    }

    if(n_NumOfHexCanBeBuilt == p_NumOfHexCanBeBuilt){
        m_NumOfHexToBuild = n_NumOfHexCanBeBuilt;
        emit buildModelStatusMessage("An equal amount of haxagons can be built for protons and neutrons");
    }
    else if(n_NumOfHexCanBeBuilt != p_NumOfHexCanBeBuilt){
        if(n_NumOfHexCanBeBuilt > p_NumOfHexCanBeBuilt){
            int temp = n_NumOfHexCanBeBuilt - p_NumOfHexCanBeBuilt;
            m_NumOfHexToBuild = n_NumOfHexCanBeBuilt - p_NumOfHexCanBeBuilt;
            emit buildModelStatusMessage("The number of extra neutron hexagons that can be built is: " + QString::number(temp / 3));

        }
        else if(n_NumOfHexCanBeBuilt < p_NumOfHexCanBeBuilt){
            int temp = p_NumOfHexCanBeBuilt - n_NumOfHexCanBeBuilt;
            m_NumOfHexToBuild = p_NumOfHexCanBeBuilt - n_NumOfHexCanBeBuilt;
            emit buildModelStatusMessage("The number of extra proton hexagons that can be built is: " + QString::number(temp / 3));
        }
    }
    else{
        //Do nothing for now
    }

    //build each ring that can be built
    while(m_NumOfHexToBuild > 0){
        ModelStepsCounter++;
        m_Step = QString::number(ModelStepsCounter) + "\n";
        spinSwitch = !spinSwitch;
        if(spinSwitch == true){
            m_Spin = "up\n";
        }
        else if(spinSwitch == false){
            m_Spin = "down\n";
        }
        if(m_Spin == "up\n"){
            x1 = "P\n";
            x2 = "N\n";
            x3 = "P\n";
            x4 = "N\n";
            x5 = "P\n";
            x6 = "N\n";
            saveModelBuildDataToFile(m_Step, m_Spin, x1, x2, x3, x4, x5, x6);
        }
        else if(m_Spin == "down\n"){
            x1 = "N\n";
            x2 = "P\n";
            x3 = "N\n";
            x4 = "P\n";
            x5 = "N\n";
            x6 = "P\n";
            saveModelBuildDataToFile(m_Step, m_Spin, x1, x2, x3, x4, x5, x6);
        }
            m_NumOfHexToBuild--;
    }

    //QDateTime f_DateTime = dateTime.currentDateTime();
    QString f_DateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    emit buildModelStatusMessage("Build model process completed @: " + f_DateTimeString);
}

void MainController::saveModelBuildDataToFile(QString _Step, QString _Spin, QString X1, QString X2, QString X3, QString X4, QString X5, QString X6){

    if(!QDir("C:/Newclides/models/" + identifiedNuclide + "_" + QString::number(i_massNum)).exists()){
        QDir().mkdir("C:/Newclides/models/" + identifiedNuclide + "_" + QString::number(i_massNum));
    }
    /*
    if(!QDir(resultsPath + selectedDbName + "\\" + scanMethod + "\\").exists()){
        QDir().mkdir(resultsPath + selectedDbName + "\\" + scanMethod + "\\");
    }
    */
    QString basePath = "C:/Newclides/models/" + identifiedNuclide + "_" + QString::number(i_massNum);
    QDateTime dateTimeF = dateTimeF.currentDateTime();
    QString dateTimeStringF = dateTimeF.toString("yyyy-MM-dd_h_mm_ss_ap");
    QString filename = basePath + "\\" + identifiedNuclide + "_" + QString::number(i_massNum) + "_" + "Step_" + QString::number(ModelStepsCounter) + "_" + dateTimeStringF + ".txt";
    //emit dataFileName2QML(selectedDbName + "_"  + dateTimeStringF +  ".txt");
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << _Step << _Spin << X1 << X2 << X3 << X4 << X5 << X6;
    }
    file.close();
}

void MainController::loadModelData(QString dataLocation){
    QString t_FilePath = "";
    QString t_FileName = "";

    //Get the nuclide name from the path. The folder name should be the same as the nuclide for now.
    auto parts = dataLocation.split(u'/');
    QString tempModelNameGetter = parts.at(3);
    if(tempModelNameGetter.contains("_")){
        tempModelNameGetter.replace("_", "-");
    }
    emit loadModelNuclideId(tempModelNameGetter);
    qDebug() << "The nuclide found name is: " + tempModelNameGetter;

    QDirIterator it(dataLocation, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        t_FilePath = it.next();
        t_FileName = it.fileName();
        qDebug() << "The file name being added to the ist is: " + t_FilePath;
        modelFilesList.append(t_FilePath.trimmed());
    }

    selectedFile = modelFilesList.at(0);
    qDebug() << "The selected file is: " + selectedFile;
    QFile sFile(selectedFile);
    if(!sFile.open(QIODevice::ReadOnly)){
        //error
    }
    QTextStream in(&sFile);
    while (!in.atEnd()){
        //openFileForView = in.readAll().trimmed();
        //qDebug() << "The model file line data is: " + in.readLine().trimmed();
        QString tempLineRead = in.readLine().trimmed();
        //emit step number
        if(fileLineCounter == 0){
           emit modelStepNumber(tempLineRead);
        }
        //emit spin
        else if(fileLineCounter == 1){
           emit modelStepSpin(tempLineRead);
        }
        else if(fileLineCounter == 2){
           emit x1ToQml(tempLineRead);
        }
        else if(fileLineCounter == 3){
           emit x2ToQml(tempLineRead);
        }
        else if(fileLineCounter == 4){
            emit x3ToQml(tempLineRead);
        }
        else if(fileLineCounter == 5){
           emit x4ToQml(tempLineRead);
        }
        else if(fileLineCounter == 6){
           emit x5ToQml(tempLineRead);
        }
        else if(fileLineCounter == 7){
           emit x6ToQml(tempLineRead);
        }
        fileLineCounter++;
    }
    sFile.close();
}
