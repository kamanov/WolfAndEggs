#include "dialogrecs.h"
#include <QLabel>
#include <QBitmap>
#include <QDebug>
dialogRecs::dialogRecs(int n,double dx, double dy, QWidget *parent)
    : QWidget(parent)
    ,ledit(new QLineEdit(this))
    ,newGame(new QPushButton(this))
    ,save(new QPushButton(this))
    ,m_score(n)
{
    QPixmap pix(":/dialog.png");
    QPalette p = palette();
    p.setBrush(backgroundRole(),Qt::cyan);
    setPalette(p);
    setMask(pix.mask());
    QFont f("impact",9,7);
    setFont(f);
    QString str("Вы набрали ");
    str+=QString::number(m_score);
    str+=" яиц!";
    QLabel* sc=new QLabel(this);

    sc->setGeometry(37,14,150,20);
    sc->setText(str);
    QLabel* lbl=new QLabel(this);
    lbl->setGeometry(37,44,150,20);
    lbl->setText("Введите имя");
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(261,143);
    ledit->setGeometry(37,64,191,29);
    newGame->setGeometry(37,109,90,23);
    newGame->setText("Новая игра");
    save->setGeometry(139,109,90,23);
    save->setText("Сохранить");
    QObject::connect(save,SIGNAL(clicked()),this,SLOT(saveRec()));

}



dialogRecs::~dialogRecs()
{

}

void dialogRecs::saveRec()
{
    if(!ledit->text().isEmpty()){
        emit runRecProc(ledit->text());
    }
}
