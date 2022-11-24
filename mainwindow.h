#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>              ///@include QMainWindow
#include <QNetworkReply>            ///@include QNetworkReply
#include <QNetworkAccessManager>    ///@include QNetworkAccessManager
#include <QNetworkRequest>          ///@include QNetworkRequest
#include <QUrl>                     ///@include QUrl
#include <QtGui>                    ///@include QtGui
#include <QMessageBox>              ///@include QMessageBox

#include "meteo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Meteo meteo;

private slots:
    void choixVille();
};
#endif // MAINWINDOW_H
