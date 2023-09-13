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


    identifiedNuclide = nuclideSymbolList.at(i_Atomic_Number - 1);

    emit buildModelStatusMessage("The nuclide symbol identified is: " + identifiedNuclide);
    //emit identifiedNuclideToQml(identifiedNuclide);

    //Calculate how the protons and neutrons can be evenly divided
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

    //Send the full name of the nuclide to QML
    auto parts2 = tempModelNameGetter.split(u'-');
    QString tempModelNameGetter2 = parts2.at(0).trimmed();
    qDebug() << "The part is: " + tempModelNameGetter2;
    int nameArrayNumToGet = nuclideSymbolList.indexOf("C");
    qDebug() << "The index of functions returns: " +  QString::number(nuclideSymbolList.indexOf(tempModelNameGetter2));
     QString tempnuclideName = nuclideNameList.at(nameArrayNumToGet);
    emit idNuclideNameToQml(tempnuclideName);

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
    fileLineCounter = 0;
}

void MainController::modelViewerStepControl(QString stepNum, QString direction){

    int tempInt = stepNum.toInt() - 1;
    if(direction == "R"){
        selectedFile = modelFilesList.at(tempInt + 1);
    }
    else if(direction == "L"){
        selectedFile = modelFilesList.at(tempInt - 1);
    }

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
        //qDebug() << "The line read data is: " + in.readLine().trimmed();
        //emit step number
        if(fileLineCounter == 0){
           emit modelStepNumber(tempLineRead);
        }
        //emit spin
        else if(fileLineCounter == 1){
           //qDebug() <<"Emitting new model data................";
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
    fileLineCounter = 0;
}

void MainController::clearLoadedModelFileList(){
    modelFilesList.clear();
}
