#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    uint32_t crc32(QString data, uint32_t crc = 0xFFFFFFFF);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void readFile(QString address);

};
#endif // MAINWINDOW_H
