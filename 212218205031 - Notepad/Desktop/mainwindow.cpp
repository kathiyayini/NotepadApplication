#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFontInfo>
#include <QFont>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionNew_triggered()
{
    file_path=" ";
    ui->textEdit->setText(" ");
}

void MainWindow::on_actionOpen_triggered()
{
    QString f=QFileDialog::getOpenFileName(this,"Open the File");
       QFile file(f);
       file_path=f;
       if(!file.open(QFile::ReadOnly|QFile::Text))
       {
           QMessageBox::warning(this,"..","File not open");
           return;
       }
       QTextStream in(&file);
       QString text=in.readAll();
       ui->textEdit->setText(text);
       file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
       if(!file.open(QFile::WriteOnly|QFile::Text))
       {
           QMessageBox::warning(this,"..","File not open");
           return;
       }
       QTextStream out(&file);
       QString text=ui->textEdit->toPlainText();
       out<<text;
       file.flush();
       file.close();
}

void MainWindow::on_actionSaveAs_triggered()
{
    QString f=QFileDialog::getSaveFileName(this,"Save the File");
       QFile file(f);
       file_path=f;
       if(!file.open(QFile::WriteOnly|QFile::Text))
       {
           QMessageBox::warning(this,"..","File not open");
           return;
       }
       QTextStream out(&file);
       QString text=ui->textEdit->toPlainText();
       out<<text;
       file.flush();
       file.close();
}

void MainWindow::on_actionSelect_Font_triggered()
{
    bool fs;
       QFont font=QFontDialog::getFont(&fs,this);
       if(fs)
       {
           ui->textEdit->setFont(font);
       }
}


void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::information(this,"About QT","Qt is a widget toolkit for creating graphical user interfaces as well as cross-platform applications that run on various software and hardware platforms such as Linux, Windows, macOS, Android or embedded systems with little or no change in the underlying codebase while still being a native application with native capabilities and speed.");
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter p;
       p.setPrinterName("HP Laser Jet");
       QPrintDialog pd(&p,this);
       ui->textEdit->print(&p);
}



void MainWindow::on_actionFont_Color_triggered()
{
    QColor fc=QColorDialog::getColor(Qt::white,this,"Choose a color");
       if(fc.isValid())
       {
           ui->textEdit->setTextColor(fc);
       }
}


void MainWindow::on_actionUnderline_triggered()
{
    ui->textEdit->setFontUnderline(true);
}

void MainWindow::on_actionItalics_triggered()
{
    ui->textEdit->setFontItalic(true);
}

void MainWindow::on_actionBold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}

void MainWindow::on_actionFont_Background_triggered()
{
    QColor fbg=QColorDialog::getColor(Qt::white,this,"Choose a background color");
       if(fbg.isValid())
       {
           ui->textEdit->setTextBackgroundColor(fbg);
       }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
