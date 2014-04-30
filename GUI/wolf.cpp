#include "wolf.h"
#include <QPainter>
#include <QDebug>
#include "transformrect.h"

Wolf::Wolf(QGraphicsItem * parent)
    :QGraphicsObject(parent)
    ,curVal(0)
    ,avaible(true)
{
    qRegisterMetaType<Wolf::WolfPosition>("Wolf::WolfPosition");
    const QString pix_name[4]={"leftTop","leftBottom","rightTop","rightBottom"};
    for(int i = 0; i < 4; i++)
    {
        m_initPix[i] = QPixmap(":/"+pix_name[i]+".png");
        initWolfPix[i] = m_initPix[i].size();
    }

    initPos[0] = QPoint(-170,-20);
    initPos[1] = QPoint(-199,65);
    initPos[2] = QPoint(-53,24);
    initPos[3] = QPoint(-68,67);
    initShapes[0] = QRect(QPoint(0, 0), QSize(79,27));
    initShapes[1] = QRect(QPoint(1, 61), QSize(77,27));
    initShapes[2] = QRect(QPoint(181, 14), QSize(78,26));
    initShapes[3] = QRect(QPoint(185, 60), QSize(77,26));
    setPos(mapToParent(pos[curVal]));

    for (int i = 0; i < 4; i++) {
        pos[i] = initPos[i];
        shapes[i] = initShapes[i];
        pix[i] = m_initPix[i];
    }

}

QRectF Wolf::boundingRect() const
{
    return QRectF(QPoint(0,0), pix[curVal].size());
}

QPainterPath Wolf::shape() const
{
    QPainterPath path;
    path.addRect(shapes[curVal]);
    return path;
}

void Wolf::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->drawPixmap(0, 0, pix[curVal]);


}

void Wolf::update(double dx, double dy)
{
    for (int i = 0; i < 4; i++) {
        pix[i] = m_initPix[i].scaled(m_initPix[i].size().width() * dx, m_initPix[i].size().height() * dy);
        shapes[i] = transformRect(initShapes[i], dx, dy);
        pos[i] = QPoint(initPos[i].x() * dx, initPos[i].y() * dy);
    }


}

void Wolf::changePos(Wolf::WolfPosition p)
{
    if(avaible){
        curVal=(int)p;
        setPos(pos[curVal]);
    }
}

