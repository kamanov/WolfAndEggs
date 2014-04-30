#include "managewidget.h"
#include <QPushButton>
#include <QStackedWidget>

manageWidget::manageWidget(QRect& rect, QWidget *parent)
    : UpdatedWidget(rect, parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    //setFixedSize(807, 529);
    m_background = QPixmap(":/backman.png");
    QPalette p = palette();
    p.setBrush(backgroundRole(), QBrush(m_background));
    setPalette(p);
    QPushButton* backBut=new  Button(QRect(15,500,87,27), QPixmap(), this);
    backBut->setText("НАЗАД");
    setAutoFillBackground(true);
    QObject::connect(backBut,SIGNAL(clicked()),this,SLOT(setBack()));
}

manageWidget::~manageWidget()
{
    
}


void manageWidget::setBack()
{
    emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(1);
}
