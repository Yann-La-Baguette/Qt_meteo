#include "meteo.h"

Meteo::Meteo(){
}

void Meteo::set_url(QString url){
    qurl = QUrl(url);
}

QByteArray Meteo::get(QUrl url){

    QNetworkRequest requete(url);

    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;
}

void Meteo::recupererJSON(QString ville, QString token){
    QUrl url = qurl;
    QString path = url.url() + "/data/2.5/weather?q=" + ville + "&units=metric&lang=fr&appid=" + token;
    url = QUrl(path);

    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));
    objetJSON = documentJSON.object();
}


QString Meteo::get_etatMeteo(){

    //qDebug() << objetJSON.value("weather").toArray().at(0).toObject().value("main");

    if(objetJSON.value("weather").toArray().at(0).toObject().value("main").isString()){
        return objetJSON.value("weather").toArray().at(0).toObject().value("main").toString();
    }
    else{
        return 0;
    }
}

QString Meteo::get_descriptionMeteo(){

    //qDebug() << objetJSON.value("weather").toArray().at(0).toObject().value("description");

    if(objetJSON.value("weather").toArray().at(0).toObject().value("description").isString()){
        return objetJSON.value("weather").toArray().at(0).toObject().value("description").toString();
    }
    else{
        return 0;
    }
}

double Meteo::get_pression(){

    //qDebug() << objetJSON.value("main").toObject().value("pressure");

    if(objetJSON.value("main").toObject().value("pressure").isDouble()){
        return objetJSON.value("main").toObject().value("pressure").toDouble();
    }
    else{
        return 0;
    }
}

double Meteo::get_temp(){

    //qDebug() << objetJSON.value("main").toObject().value("temp");

    if(objetJSON.value("main").toObject().value("temp").isDouble()){
        return objetJSON.value("main").toObject().value("temp").toDouble();
    }
    else{
        return 0;
    }
}

double Meteo::get_humidite(){

    //qDebug() << objetJSON.value("main").toObject().value("humidity");

    if(objetJSON.value("main").toObject().value("humidity").isDouble()){
        return objetJSON.value("main").toObject().value("humidity").toDouble();
    }
    else{
        return 0;
    }
}
