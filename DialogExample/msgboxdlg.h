#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>
#include<QDialog>
#include<QMessageBox>

class MsgBoxDlg : public QWidget
{
    Q_OBJECT
public:
    explicit MsgBoxDlg(QWidget *parent = nullptr);

signals:

private slots:
    void showQusetionMsg();
    void showInformationMsg();
    void showWarningtionMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();
private:
    QLabel *label;
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warningBtn;
    QPushButton *criticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;
    QGridLayout *mainLayout;
};

#endif // MSGBOXDLG_H
