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

uint32_t  MainWindow::crc32(QString data,uint32_t crc)
{
    const uint32_t polynomial = 0xEDB88320;


    for (int i = 0; i < data.size(); ++i) {
        crc ^= int32_t(data[i].toLatin1());
        for (int j = 0; j < 8; ++j) {
            if (crc & 1) {
                crc = (crc >> 1) ^ polynomial;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}


void MainWindow::readFile(QString address)
{
    QFile file(address);

    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<"file not found";
        return;
    }

    uint32_t crc=0xFFFFFFFF;

    while (!file.atEnd()) {

        QString str;

        int mByte=1024*1024;

        str=file.read(mByte);

        crc=crc32(str,crc);
    }


    file.close();

}


