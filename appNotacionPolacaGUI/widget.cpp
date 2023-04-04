#include "widget.h"
#include "ui_widget.h"
#include "notacionpolaca.h"

#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//5*(2+3)-4
//a/(b+c)*d
//a^b*((C-D)+e)/f*G+h
//1^2*((3-4)+5)/6*7+8

void Widget::on_pushButton_clicked()
{
    notacionpolaca *expresion = new notacionpolaca();
    string ePosfija = "";
    if(!ui->lineEdit->text().isEmpty())
    {
        if(ui->radioButton->isChecked()){


            ePosfija = expresion->ConvertiraNotacionPostfija(ui->lineEdit->text().toStdString());

            ui->label_2->setText(QString::fromStdString(ePosfija));
            ui->label_3->setText("");
        }
        if(ui->radioButton_2->isChecked())
        {

            ePosfija = expresion->ConvertiraNotacionPostfija(ui->lineEdit->text().toStdString());

            ui->label_2->setText("");

            double resultado = 0;
            resultado = expresion->solucionarExpresionPostfija(ePosfija);

            ui->label_3->setText(QString::number(resultado));
            //cout<<    expresion->solucionarExpresionPostfija(ePosfija)<<endl;
        }
        if(ui->radioButton_3->isChecked())
        {
            ePosfija = expresion->ConvertiraNotacionPostfija(ui->lineEdit->text().toStdString());

            ui->label_2->setText(QString::fromStdString(ePosfija));
            double resultado = 0;
            resultado = expresion->solucionarExpresionPostfija(ui->label_2->text().toStdString());

            ui->label_3->setText(QString::number(resultado));
        }
    }
    else
    {
        ui->label_2->setText("Primero coloque una expresion infija");
        ui->label_2->adjustSize();
        ui->label_3->setText("Primero coloque una expresion infija");
        ui->label_3->adjustSize();
    }
}

