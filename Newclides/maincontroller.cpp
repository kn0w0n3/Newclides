#include "maincontroller.h"

MainController::MainController(QWidget *parent) : QWidget(parent){

}

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

//Build newclide models
void MainController::buildModel(QString storagePath, QString mass_Num, QString atomic_number){
    //Get the current date and time
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    emit buildModelStatusMessage("Build model process started @ " + dateTimeString + "\n");

    //Get the provided storage path
    confirmedStoragePath = storagePath;

    //Mass Number: The total number of protons and neutrons in a nucleus.
    i_massNum = mass_Num.toInt();

    //Atomic Number: The number of protons
    i_Atomic_Number = atomic_number.toInt();

    //Subtract the number of prontons from the mass number to find the number of neutrons
    i_numOfNeutrons = i_massNum - i_Atomic_Number;

    //Display a message about the number of protons and neutrons
    emit buildModelStatusMessage( "The number of protons is: " + atomic_number);
    emit buildModelStatusMessage( "The number of neutrons is: " + QString::number(i_numOfNeutrons));

    //Get the nuclide symbol. This will be used for the file name
    identifiedNuclide = nuclideSymbolList.at(i_Atomic_Number - 1);
    emit buildModelStatusMessage("The nuclide symbol identified is: " + identifiedNuclide);

    //Find the number of hex halves that can be built ith the given number of protons
    p_NumHexHalvesCanBeBuilt = i_Atomic_Number / 3;
    p_Remainder = i_Atomic_Number % 3;
    emit buildModelStatusMessage("The number of hexagon halves that can be built with the provided number of protons is: " + QString::number(p_NumHexHalvesCanBeBuilt));
    emit buildModelStatusMessage("The leftover number of protons is: " + QString::number(p_Remainder));

    //Find the number of hex halves that can be built ith the given number of neutrons
    n_NumHexHalvesCanBeBuilt = i_numOfNeutrons / 3;
    n_Remainder = i_numOfNeutrons % 3;
    emit buildModelStatusMessage("The number of hexagon halves that can be built with the provided number of neutrons is: " + QString::number(n_NumHexHalvesCanBeBuilt));
    emit buildModelStatusMessage("The leftover number of neutrons is: " + QString::number(n_Remainder));

     //Hex case 1: No hexagon halves can be built
    if(p_NumHexHalvesCanBeBuilt == 0 && n_NumHexHalvesCanBeBuilt == 0){

    }
    //Hex Case 2: Hexagon halves can be built
    else{
         //2.1: An equal number of hexagon halves can be built
         if(n_NumHexHalvesCanBeBuilt == p_NumHexHalvesCanBeBuilt){
             m_NumOfHexToBuild = n_NumHexHalvesCanBeBuilt;
             emit buildModelStatusMessage("An equal amount of haxagons can be built for protons and neutrons");
         }

         //2.2: An unequal number of hexagon halves can be built
         else if(n_NumHexHalvesCanBeBuilt != p_NumHexHalvesCanBeBuilt){

             //2.2.1 More neutron halves than proton halves can be built
             if(n_NumHexHalvesCanBeBuilt > p_NumHexHalvesCanBeBuilt){

                 //Find the difference
                 int t_Difference = n_NumHexHalvesCanBeBuilt - p_NumHexHalvesCanBeBuilt;
                 m_NumOfHexToBuild = n_NumHexHalvesCanBeBuilt - t_Difference;

                 //Add the remaining neutrons to the remainder from the first calculation
                 n_Remainder += t_Difference * 3;

                 emit buildModelStatusMessage("Num of hex to build: " + QString::number(m_NumOfHexToBuild));
                 emit buildModelStatusMessage("Neutrons remaining: " + QString::number(n_Remainder));
                 emit buildModelStatusMessage("Protons remaining: " + QString::number(p_Remainder));
             }
             //2.2.2 More proton halves than neutron halves can be built
             else if(n_NumHexHalvesCanBeBuilt < p_NumHexHalvesCanBeBuilt){

                 //Find the difference
                 int t_Difference = p_NumHexHalvesCanBeBuilt - n_NumHexHalvesCanBeBuilt;
                 m_NumOfHexToBuild = p_NumHexHalvesCanBeBuilt - t_Difference;

                 //Add the remaining neutrons to the remainder from the first calculation
                 p_Remainder += t_Difference * 3;

                 emit buildModelStatusMessage("Num of hex to build: " + QString::number(m_NumOfHexToBuild));
                 emit buildModelStatusMessage("Neutrons remaining: " + QString::number(n_Remainder));
                 emit buildModelStatusMessage("Protons remaining: " + QString::number(p_Remainder));
             }
         }
         else{
             //Do nothing for now
         }

         //build each ring that can be built. This may need a separate function
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
    }


    //QDateTime f_DateTime = dateTime.currentDateTime();
    QString f_DateTimeString = dateTime.toString("yyyy-MM-dd h:mm:ss ap");
    emit buildModelStatusMessage("Build model process completed @: " + f_DateTimeString);
}

//Save the model build data to file
void MainController::saveModelBuildDataToFile(QString _Step, QString _Spin, QString X1, QString X2, QString X3, QString X4, QString X5, QString X6){

    if(!QDir("C:/Newclides/models/" + identifiedNuclide + "_" + QString::number(i_massNum)).exists()){
        QDir().mkdir("C:/Newclides/models/" + identifiedNuclide + "_" + QString::number(i_massNum));
    }

    QString basePath = "C:/Newclides/models/" + identifiedNuclide + "_" + QString::number(i_massNum);
    QDateTime dateTimeF = dateTimeF.currentDateTime();
    QString dateTimeStringF = dateTimeF.toString("yyyy-MM-dd_h_mm_ss_ap");
    QString filename = basePath + "\\" + identifiedNuclide + "_" + QString::number(i_massNum) + "_" + "Step_" + QString::number(ModelStepsCounter) + "_" + dateTimeStringF + ".txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << _Step << _Spin << X1 << X2 << X3 << X4 << X5 << X6;
    }
    file.close();
}

//Initial loader for model file data
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
    int nameArrayNumToGet = nuclideSymbolList.indexOf(tempModelNameGetter2);
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

//Function to traverse/change the model data after the initial file has been loaded
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

void MainController::clearLoadedModelFileList(){
    modelFilesList.clear();
}
