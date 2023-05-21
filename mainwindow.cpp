#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>
#include<QFile>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString password=ui->lineEdit_2->text();
    readFile(ui->lineEdit->text());


}

void MainWindow::readFile(QString address)
{
    QFile file(address);

    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<"file not found";
        return;
    }

    auto data=file.readAll();

    QString binaryData;

    for(int i=0;i<data.size();i++){
        binaryData+=QString::number(data[i],2);
    }


    file.close();

}
