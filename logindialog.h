#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    
    QString getLogin() const;
    QString getPassword() const;
private:
    Ui::LoginDialog *ui;

};

#endif // LOGINDIALOG_H
