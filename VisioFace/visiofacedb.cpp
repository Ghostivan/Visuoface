#include "visiofacedb.h"
#include <QtSql>

// Init Database
/*
VisioFaceDB::VisioFaceDB( QString _name, QString _host, QString _username, QString _password)
{
    name = _name;
    host = _host;
    username = _username;
    password = _password;

    this->db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(_host);
    db.setDatabaseName(_name);
    db.setUserName(_username);
    db.setPassword(_password);


}*/

void VisioFaceDB::createDatabase(QString _name, QString _host, QString _username, QString _password)
{
    name = _name;
    host = _host;
    username = _username;
    password = _password;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(_host);
    db.setDatabaseName(_name);
    db.setUserName(_username);
    db.setPassword(_password);


}

void VisioFaceDB::setDatabase(QString _name, QString _host, QString _username, QString _password)
{
    this->name=_name;
    this->host=_host;
    this->username=_username;
    this->password=_password;
}


void VisioFaceDB::createUser(QString _mail, QString _nom, QString _prenom )
{
    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }
    else
    {
        QSqlQuery qry;
        qry.prepare( "INSERT INTO user (id, nom, prenom, mail) VALUES (null, '"+_nom+"', '"+_prenom+"', '"+_mail+"')" );
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        else
        {
          qDebug( "User inserer dans la bdd." );
        }

    }

}

