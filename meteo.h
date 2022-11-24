#ifndef METEO_H
#define METEO_H

#include <QNetworkReply>            ///@include QNetworkReply
#include <QNetworkAccessManager>    ///@include QNetworkAccessManager
#include <QNetworkRequest>          ///@include QNetworkRequest
#include <QUrl>                     ///@include QUrl
#include <QtGui>                    ///@include QtGui
#include <QMessageBox>              ///@include QMessageBox

class Meteo
{
public:
    Meteo();
    void set_url(QString url);
    void recupererJSON(QString ville, QString meteo);

    QString get_etatMeteo();
    QString get_descriptionMeteo();
    double get_temp();
    double get_humidite();
    double get_pression();

private:
    QUrl qurl;
    QByteArray get(QUrl url);
    QNetworkAccessManager m;
    QJsonObject objetJSON;

};

#endif // METEO_H
