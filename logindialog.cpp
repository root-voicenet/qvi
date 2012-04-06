#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


QString LoginDialog::getLogin() const
{
    return ui->LoginEdit->text();
}

QString LoginDialog::getPassword() const
{
    return ui->PasswordEdit->text();
}
