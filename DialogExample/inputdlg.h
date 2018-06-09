#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>
#include<QDialog>

class InputDlg : public QWidget
{
    Q_OBJECT
public:
    explicit InputDlg(QWidget *parent = nullptr);

signals:

public slots:
private:
    QLabel *nameLabel1;
    QLabel *sexLabel1;
    QLabel *ageLabel1;
    QLabel *scoreLabel1;
    QLabel *nameLabel2;
    QLabel *sexLabel2;
    QLabel *ageLabel2;
    QLabel *scoreLabel2;
    QPushButton *nameBtn;
    QPushButton *sexBtn;
    QPushButton *ageBtn;
    QPushButton *scoreBtn;
    QGridLayout *mainLayout;
};

#endif // INPUTDLG_H
