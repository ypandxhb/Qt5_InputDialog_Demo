#ifndef QCUSTOMDLG_H
#define QCUSTOMDLG_H

#include <QWidget>
#include<QDialog>
#include<QPushButton>
#include<QLabel>
class QCustomDlg : public QWidget
{
    Q_OBJECT
public:
    explicit QCustomDlg(QWidget *parent = nullptr);

signals:

public slots:

private:
    QPushButton *CustomBtn;
    QLabel *label;
};

#endif // QCUSTOMDLG_H
