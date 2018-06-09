#include "dialog.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle(tr("各种标准对话框实例"));
    //文件标准对话框
    fileBtn=new QPushButton(tr("文件标准对话框"));
    fileLineEdit=new QLineEdit;

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);

    connect(fileBtn,&QPushButton::clicked,
            [=]()
    {
        QString s=QFileDialog::getOpenFileName(this,
                                               "open file dialog",
                                               "../",
                                               "All file(*.*);;C++ file (*.cpp);;C Files(*.c);;Head Files(*.h)");
        fileLineEdit->setText(s);
    });

    //color
    colorBtn=new QPushButton(tr("颜色标准对话框"));
    colorFrame=new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    connect(colorBtn,&QPushButton::clicked,
            [=]()
    {
        QColor c=QColorDialog::getColor(Qt::red);
        if(c.isValid())
        {
            colorFrame->setPalette(QPalette(c));
        }
    });

    //font
    fontBtn=new QPushButton(tr("字体标准对话框"));
    fontLineEdit=new QLineEdit;
    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);
    connect(fontBtn,&QPushButton::clicked,
            [=]()
    {
        bool ok;
        QFont f=QFontDialog::getFont(&ok);
        if(ok)
        {
            fontLineEdit->setFont(f);
        }
    });

    //input
    inputBtn=new QPushButton(tr("标准输入对话框"));
    mainLayout->addWidget(inputBtn,3,0);

    connect(inputBtn,&QPushButton::clicked,
            [=]()
    {
        inputDlg=new InputDlg();
        inputDlg->show();
    });

    //Msg
    MsgBtn=new QPushButton(tr("标准消息对话框"));
    mainLayout->addWidget(MsgBtn,4,0);
    connect(MsgBtn,&QPushButton::clicked,
             [=]()
    {
        msgdlg=new MsgBoxDlg();
        msgdlg->show();
    });

    CustomBtn=new QPushButton(tr("用户自定义消息对话框"));
    label=new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    mainLayout->addWidget(CustomBtn,5,0);
    mainLayout->addWidget(label,5,1);
    connect(CustomBtn,&QPushButton::clicked,
            [=]()
    {
        bool Ok;
        label->setText(tr("custom Message Box"));
        QMessageBox customMsgBox;
        customMsgBox.setWindowTitle(tr("用户自定义消息框"));
        QPushButton *yesBtn=customMsgBox.addButton(tr("Yes"),QMessageBox::ActionRole);
        QPushButton *noBtn=customMsgBox.addButton(tr("No"),QMessageBox::ActionRole);
        QPushButton *CancelBtn=customMsgBox.addButton(tr("Cancel"),QMessageBox::ActionRole);
        customMsgBox.setText("this is a custom Box");
        customMsgBox.setIconPixmap(QPixmap("qt.png"));
        customMsgBox.exec();
        if(customMsgBox.clickedButton()==yesBtn)
            label->setText(tr("Custom Message Box/Yes"));
        if(customMsgBox.clickedButton()==noBtn)
            label->setText(tr("Custom Message Box/No"));
        if(customMsgBox.clickedButton()==CancelBtn)
            label->setText(tr("Custom Message Box/Cancel"));

  /*      switch (customMsgBox.clickedButton()->text().toInt(&Ok) {
        case yesBtn->text().toInt(&Ok):
            label->setText(tr("Custom Message Box/Yes"));
            break;
        case noBtn->text().toInt(&Ok):
            label->setText(tr("Custom Message Box/No"));
            break;
        case:CancelBtn->text().toInt(&Ok):
            label->setText(tr("Custom Message Box/Cancel"));
            break;
        default:
            break;
        }*/
    });
}

Dialog::~Dialog()
{

}
