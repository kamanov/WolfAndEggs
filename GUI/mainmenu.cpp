#include "mainmenu.h"
#include <QAbstractScrollArea>
#include <QPushButton>
#include <QStackedWidget>
#include "button.h"
mainMenu::mainMenu(QRect& rect, QWidget *parent)
    : UpdatedWidget(rect, parent)

{
    setWindowFlags(Qt::FramelessWindowHint);
    //set background
    m_background = QPixmap(":/backmenu.png");
    QPalette p = palette();
    p.setBrush(backgroundRole(), QBrush(m_background));
    setPalette(p);
    //setFixedSize(808, 533);
    setAutoFillBackground(true);


    QPushButton* contBut = new Button(QRect(276,136,258,47), QPixmap(), this);
    contBut->setText("ПРОДОЛЖИТЬ");
    QPushButton* managBut = new Button(QRect(276,210,258,47), QPixmap(), this);
    managBut->setText("НАСТРОЙКИ");
    QPushButton* recordsBut = new Button(QRect(276,284,258,47), QPixmap(), this);
    recordsBut->setText("РЕКОРДЫ");


    QObject::connect(contBut,SIGNAL(clicked()),this,SLOT(setCont()));
    QObject::connect(managBut,SIGNAL(clicked()),this,SLOT(setManage()));
    QObject::connect(recordsBut,SIGNAL(clicked()),this,SLOT(setRecs()));
}

mainMenu::~mainMenu()
{
    
}

void mainMenu::setAbout()
{
    emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(3);
}

void mainMenu::setManage()
{
    emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(2);
}

void mainMenu::setCont()
{
    emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(0);

}

void mainMenu::setRecs()
{
     emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(3);
}

