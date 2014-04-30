#include "aboutwidget.h"
#include <QPushButton>
#include <QStackedWidget>
#include "button.h"

aboutWidget::aboutWidget(QRect& rect, QWidget *parent)
    : UpdatedWidget(rect, parent)
{
  /*  setWindowFlags(Qt::FramelessWindowHint);
    //setFixedSize(807, 529);

    m_background = QPixmap(":/backabout.png");
    QPalette p = palette();
    p.setBrush(backgroundRole(), QBrush(m_background));
    setPalette(p);
    QPushButton* backBut = new  Button(QRect(15,500,81,21), QPixmap(), this);
    backBut->setText("НАЗАД");
    setAutoFillBackground(true);
    QObject::connect(backBut,SIGNAL(clicked()),this,SLOT(setBack())); */
}

aboutWidget::~aboutWidget()
{
    
}

void aboutWidget::setBack()
{
    emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(1);
}
