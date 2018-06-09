#include "msgboxdlg.h"
MsgBoxDlg::MsgBoxDlg(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("标准消息对话框"));
    label=new QLabel;
    label->setText(tr("请选择一种消息框"));

    questionBtn=new QPushButton(tr("QuestionMsg"));
    informationBtn=new QPushButton(tr("InformationMsg"));
    warningBtn=new QPushButton(tr("warningMsg"));
    criticalBtn=new QPushButton(tr("CriticalMsg"));
    aboutBtn=new QPushButton(tr("aboutMsg"));
    aboutQtBtn=new QPushButton(tr("AboutQtMsg"));

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);
    connect(questionBtn,&QPushButton::clicked,this,&MsgBoxDlg::showQusetionMsg);
    connect(informationBtn,&QPushButton::clicked,this,&MsgBoxDlg::showInformationMsg);
    connect(warningBtn,&QPushButton::clicked,this,&MsgBoxDlg::showWarningtionMsg);
    connect(criticalBtn,&QPushButton::clicked,this,&MsgBoxDlg::showCriticalMsg);
    connect(aboutBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutMsg);
    connect(aboutQtBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutQtMsg);
}
void MsgBoxDlg::showQusetionMsg()
{
    label->setText(tr("Question Message Box"));
    switch (QMessageBox::question(this,tr("question Box"),tr("is cannel?"),QMessageBox::Ok|QMessageBox::Cancel|QMessageBox::Open,QMessageBox::Ok)) {
    case QMessageBox::Ok:
        label->setText(tr("question Ok"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("question Cancel"));
        break;
    case QMessageBox::Open:
        label->setText(tr("question Open"));
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information message Box"));
    QMessageBox::information(this,tr("informtion Message Box"),tr("this is Information"),QMessageBox::Ok|QMessageBox::Cancel|QMessageBox::Open);
}
void MsgBoxDlg::showWarningtionMsg()
{
    label->setText(tr("Waring Message Box"));
    switch (QMessageBox::warning(this,tr("Warning Message Box"),tr("this is Warning"),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save:
        label->setText(tr("Waring Button/Save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warning Message/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("warning Message/Cancel"));
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this,tr("Critical Message Box"),tr("this is a Critical Box"));
}
void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("about Message Box"));
    QMessageBox::about(this,tr("about Message Box"),tr("this is a about Box"));
}
void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("aboutQt Message Box"));
    QMessageBox::aboutQt(this,tr("aboutQt Message Box"));
}
