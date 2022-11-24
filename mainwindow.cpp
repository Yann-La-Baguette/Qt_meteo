#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    //QJsonDocument documentJSON = QJsonDocument::fromJson(meteo.get_json_air(ville, token));
    //qDebug() << documentJSON;
    meteo.recupererJSON(ville, token);

    QString etatMeteo = meteo.get_etatMeteo();
    ui->meteoLineEdit->setText(etatMeteo);

    QString descMeteo = meteo.get_descriptionMeteo();
    ui->descLineEdit->setText(descMeteo);

    double temperature = meteo.get_temp();
    ui->tempSpinBox->setValue(temperature);

    double pression = meteo.get_pression();
    ui->pressionSpinBox->setValue(pression);

    double humidite = meteo.get_humidite();
    ui->humSpinBox->setValue(humidite);
}
