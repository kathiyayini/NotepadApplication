#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QMessageBox"
#include "QFontDialog"
#include "QFont"
#include<QtPrintSupport/qprinter.h>
#include<QtPrintSupport/qprintdialog.h>
//#include<QPrinter>
//#include<QPrintDialog>
#include <QColorDialog>
#include <QColor>

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

void MainWindow::on_actionUndo_2_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_2_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionNew_triggered()
{
    file_path="";
    ui->textEdit->setText("");

}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(file_name);
    file_path=file_name;
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"6125","Error");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionBold_triggered()
{
      ui->textEdit->setStyleSheet("font-weight: bold ");
}

void MainWindow::on_actionSelect_font_triggered()
{
    bool fontSelected;
    QFont font=QFontDialog::getFont(&fontSelected,this);
    if(fontSelected)
    {
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_actionUnderline_triggered()
{
    ui->textEdit->setFontUnderline(true);
}

void MainWindow::on_actionItalics_triggered()
{
ui->textEdit->setStyleSheet("font: italic");
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"6125","Error");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the File");
    QFile file(file_name);
    file_path=file_name;
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"6125","Error");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionPrint_triggered()
{
    //QPrinter printer;
      //printer.setPrinterName("Printer Name");
      //QPrintDialog pDialog(&printer,this);
      //if(pDialog.exec()==QDialog::Rejected){
         QMessageBox::warning(this,"Warning","Cannot access private");
          //return;
      }
      //ui->textEdit->print(&printer);

//}
void MainWindow::on_actionFont_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
      if(color.isValid()) {
          ui->textEdit->setTextColor(color);
        }
}

void MainWindow::on_actionBackground_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
      if(color.isValid()) {
          ui->textEdit->setTextBackgroundColor(color);
        }
}
