#include "inputdlg.h"
#include<QInputDialog>
InputDlg::InputDlg(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("标准输入对话框"));
    nameLabel1=new QLabel(tr("name:"));
    nameLabel2=new QLabel(tr("zhangsan"));
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    nameBtn=new QPushButton(tr("change Name"));

    sexLabel1=new QLabel(tr("Sex:"));
    sexLabel2=new QLabel(tr("man"));
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    sexBtn=new QPushButton(tr("change Sex"));

    ageLabel1=new QLabel(tr("Age:"));
    ageLabel2=new QLabel(tr("21"));
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ageBtn=new QPushButton(tr("change Age"));

    scoreLabel1=new QLabel(tr("Score:"));
    scoreLabel2=new QLabel(tr("80"));
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    scoreBtn=new QPushButton(tr("change score"));

    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);

    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);

    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);

    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);

    mainLayout->setSpacing(15);
    mainLayout->setMargin(10);
    connect(nameBtn,&QPushButton::clicked,
            [=]()
    {
        bool Ok;
        QString text=QInputDialog::getText(this,tr("change name"),tr("input name: "),QLineEdit::Normal,nameLabel2->text(),&Ok);
        if(Ok&&!text.isEmpty())
            nameLabel2->setText(text);
    });

    connect(sexBtn,&QPushButton::clicked,
            [=]()
    {
        QStringList SexItems;
        SexItems<<tr("man")<<tr("woman");
        bool Ok;
        QString SexItem=QInputDialog::getItem(this,tr("Change Sex"),tr("input Sex"),SexItems,0,false,&Ok);
        if(Ok&&!SexItem.isEmpty())
        {
            sexLabel2->setText(SexItem);
        }
    });
    connect(ageBtn,&QPushButton::clicked,
            [=]()
    {
        bool Ok;
        int age=QInputDialog::getInt(this,tr("Change Age"),tr("input age"),ageLabel2->text().toInt(&Ok),0,120,1,&Ok);
        if(Ok)
        {
            ageLabel2->setText(QString(tr("%1")).arg(age));
        }
    });
    connect(scoreBtn,&QPushButton::clicked,
            [=]()
    {
        bool Ok;
        double score=QInputDialog::getDouble(this,tr("Change score"),tr("input score"),scoreLabel2->text().toDouble(&Ok),0,100,0.5,&Ok);
        if(Ok)
        {
            scoreLabel2->setText(QString(tr("%1")).arg(score));
        }

    });

}
//void InputDlg::changeName()

