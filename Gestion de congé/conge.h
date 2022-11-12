#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include<QSqlQueryModel>

class Conge
{
public:
    Conge();
     Conge(int,QString,QString,int);
    int  getIDC();
     QString getdate_debut();
     QString getdate_fin();
     int  getID_em();


      void setIDC(int);
      void setdate_debut(QString);
      void setdate_fin(QString);
      void  setID_em(int);
      bool ajouter();
       QSqlQueryModel* afficher();
       bool supprimer(int);
 private:

    int IDC;
   QString  date_debut;
   QString  date_fin;
   int ID_em;
};

#endif // CONGE_H
