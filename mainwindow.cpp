#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::choixVille(){

    QString ville;
    switch(ui->choixVilleCombo->currentIndex()){
        case 0:
            ville = "clermont-ferrand";
            break;

        case 1:
            ville = "lyon";
            break;

        case 2:
            ville = "paris";
            break;

        case 3:
            ville = "agde";
            break;

        case 4:
            ville = "miami";
            break;
    }


    QString token = ui->tokenLineEdit->text();
    meteo.set_url("https://api.openweathermap.org");
    meteo.recupererJSON(ville, token);


    QString etatMeteo = meteo.get_etatMeteo();
    ui->meteoLineEdit->setText(etatMeteo);


    QString descMeteo = meteo.get_descriptionMeteo();
    ui->descLineEdit->setText(descMeteo);


    double temperature = meteo.get_temp();
    ui->tempSpinBox->setValue(temperature);
    if(temperature<20){
        ui->tempSpinBox->setStyleSheet("background-color: blue ; color: white");
    }
    else if(temperature>20 && temperature<27){
        ui->tempSpinBox->setStyleSheet("background-color: green ; color: black");
    }
    else{
        ui->tempSpinBox->setStyleSheet("background-color: red ; color: black");
    }


    double pression = meteo.get_pression();
    ui->pressionSpinBox->setValue(pression);
    if(pression<1000){
        ui->pressionSpinBox->setStyleSheet("background-color: blue ; color: white");
    }
    else if(pression>1000 && pression<1026){
        ui->pressionSpinBox->setStyleSheet("background-color: green ; color: black");
    }
    else{
        ui->pressionSpinBox->setStyleSheet("background-color: red ; color: black");
    }


    double humidite = meteo.get_humidite();
    ui->humSpinBox->setValue(humidite);
    if(humidite<40){
        ui->humSpinBox->setStyleSheet("background-color: blue ; color: white");
    }
    else if(pression>40 && pression<60){
        ui->humSpinBox->setStyleSheet("background-color: green ; color: black");
    }
    else{
        ui->humSpinBox->setStyleSheet("background-color: red ; color: black");
    }
}
