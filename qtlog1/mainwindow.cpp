#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include "hightliter.h"

QString fileName = "log.txt";
Logger *logger;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Logger *logger2 = new Logger(this, fileName, ui->plainTextEdit);
    logger = logger2;
    logger->write("Hello Qt");
    Highlighter * h = new Highlighter(ui->textEdit->document());//传一个QTextDocument

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     logger->writeInfo("Info test");
}

void MainWindow::on_pushButton_2_clicked()
{
    logger->writeWarn("warning test");
}



void MainWindow::on_pushButton_3_clicked()
{
    logger->writeError("error test");
}

void MainWindow::on_pushButton_4_clicked()
{
    QString displayString;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();

    while (!line.isNull())
    {
        line = in.readLine();
        displayString.append(line);
        displayString.append("\n");
    }
    ui->textEdit->clear();
    ui->textEdit->setText(displayString);
}
