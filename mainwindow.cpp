#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    torrentfile = QFileDialog::getOpenFileName(
                this,
                tr("Select the Torrent file"),
                "",
                "Torrent Files (*.torrent);;All Files (*.*)"
                );
    ui->lineEdit->setText(torrentfile);

}

void MainWindow::on_pushButton_2_clicked()
{
//    QString convertcommand = QString("transmission-show -m %1").arg(torrentfile);
    QProcess sh;
    sh.start("sh");
    sh.write("transmission-show -m ");
    sh.closeWriteChannel();
    sh.waitForFinished();
    QByteArray magnetoutput = sh.readAll();
    sh.close();
    ui->textEdit->append(magnetoutput);
}

