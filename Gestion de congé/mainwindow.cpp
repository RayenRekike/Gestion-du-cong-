#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"conge.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QSqlError>
#include<QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id ->setValidator( new QIntValidator(100, 9999999, this));
    ui->tab_conge->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ int IDC=ui->le_id->text().toInt();
  QString date_debut=ui->le_dtd->text();
         QString date_fin=ui->le_dtfn->text();
           int ID_em=ui->le_idem->text().toInt();
   Conge C(IDC,date_debut,date_fin,ID_em);
}

void MainWindow::on_pb_supp_clicked()
{
    Conge C1;
    C1.setIDC(ui->id_sup->text().toInt());
    bool test=C1.supprimer(C1.getIDC());
    QMessageBox msgBox;
    if(test)
    {
        ui->tab_conge->setModel(C.afficher());
        msgBox.setText("supprision avec succes.");
    }
    else
    {
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
}
}
