#include "conge.h"
#include<QString>
#include <QSqlQuery>
#include <QtDebug>
Conge::Conge()
{
IDC=0,date_debut="",date_fin="",ID_em=0;
}
 Conge::Conge(int IDC,QString date_debut,QString date_fin,int ID_em)
{this->IDC=IDC; this->date_debut=date_debut; this->date_fin=date_fin;this->ID_em=ID_em;}

 int Conge::getIDC(){return IDC;}
 QString Conge ::getdate_debut(){return date_debut;}
 QString Conge ::getdate_fin(){return date_fin;}
 int Conge::getID_em(){return ID_em;}

 void Conge::setIDC(int IDC){this->IDC=IDC;}
 void Conge::setdate_debut(QString date_debut){this->date_debut=date_debut;}
void Conge::setdate_fin(QString date_fin){this->date_fin=date_fin;}
void Conge::setID_em(int ID_em){this->ID_em=ID_em;}

bool Conge::ajouter()
{

    QString id_string= QString::number(IDC);

    QSqlQuery query;
         query.prepare("INSERT INTO CONGES(IDC,date_debut,date_fin,ID_em) "
                       "VALUES (:id, :forename, :surname)");
         query.bindValue(1,id_string);
         query.bindValue(2, date_debut);
         query.bindValue(3, date_fin);
         query.bindValue(4, ID_em);

          return query.exec();
}
bool Conge::supprimer(int IDC)
{
    QSqlQuery query;
         query.prepare("Delete from CONGES where IDC=IDC");
         query.bindValue(1,IDC);
         query.bindValue(4, ID_em);
    return query.exec();
}
QSqlQueryModel* Conge::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM CONGES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant conge"));
    model->setHeaderData(1, Qt::Horizontal, QObject ::tr("Date de debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject ::tr("Date de fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject ::tr("Identifiant d'empolyer"));

  return model;
}









