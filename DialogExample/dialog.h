#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QGridLayout>
#include<QPushButton>
#include<QFileDialog>
#include<QFrame>
#include<QColorDialog>
#include<QFontDialog>
#include"inputdlg.h"
#include"msgboxdlg.h"
#include"qcustomdlg.h"
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;

    QPushButton *colorBtn;
    QFrame *colorFrame;

    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    QPushButton *inputBtn;
    InputDlg *inputDlg;

    QPushButton *MsgBtn;
    MsgBoxDlg *msgdlg;

    QPushButton *CustomBtn;
    QLabel *label;
private slots:
    //void showFile();
};

#endif // DIALOG_H
