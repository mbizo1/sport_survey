#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->checkBoxFood->setChecked(false);

    //adding items to combobox club
    ui->comboBoxClub->addItem("Select");
    ui->comboBoxClub->addItem("General");
    ui->comboBoxClub->addItem("VIP");
    ui->comboBoxClub->addItem("Executive");

    //adding items to combobox gender
    ui->comboBoxGender->addItem("Female");
    ui->comboBoxGender->addItem("Male");
    ui->comboBoxGender->addItem("Other");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_submit_clicked()
{
    //printing out user name to the text edit
    ui->textBrowser->setText("Thank you " + ui->lineEdit_Name->text() + " for your feedback! " + "<br>");

    ui->textBrowser->append("You belong to club, " + ui->comboBoxClub->currentText() + "<br>");

    if(ui->checkBoxFood->isChecked())
    {
        ui->textBrowser->append(ui->checkBoxFood->text()+ " is more important.");

    }else if(ui->checkBoxDrinks->isChecked())
    {
        ui->textBrowser->append(ui->checkBoxDrinks->text() + " is more important.");
    }else if(ui->checkBoxBoth->isChecked())
    {
        ui->textBrowser->append("Both food and drinks is more important.");
    }else
        QMessageBox::warning(this, "Warning", "Choose between food and drinks!");
}

