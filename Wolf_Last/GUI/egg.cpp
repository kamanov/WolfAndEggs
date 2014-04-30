#include "egg.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>

const QPoint Egg::sPos[4]={QPoint(-313,-167),QPoint(-313,-4),QPoint(285,-105),QPoint(285,11)};
const qreal Egg::first[4]={-245,-266,236,234};
const qreal Egg::second[4]={-171,-201,173,165};
const qreal Egg::downPos[4]={-33,113,27,124};

Egg::Egg(EggPosition p, double dx, double dy, QGraphicsItem *parent)
    :QGraphicsObject(parent)
    ,m_dx(dx)
    ,m_dy(dy)
    ,m_pos(p)
{
    for (int i = 0; i < 4; i++) {
        m_sPos[i] = QPoint(sPos[i].x() * m_dx, sPos[i].y() * m_dy);
        m_first[i] = first[i] * m_dx;
        m_second[i] = second[i] * m_dx;
        m_downPos[i] = downPos[i] * dy;
    }

    setPos(m_sPos[(int)p]);
}

QRectF Egg::boundingRect() const
{
    return QRectF(0,0,30 * m_dx,40 * m_dy);
}

QPainterPath Egg::shape() const
{
    QPainterPath path;
    path.addRect(QRect(10 * m_dx,20 * m_dy,10 * m_dx,10 * m_dy));
    return path;
}

void Egg::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QRadialGradient grad(15,20,24);
    grad.setColorAt(0,Qt::white);
    grad.setColorAt(1,Qt::yellow);
    painter->setBrush(grad);
    painter->drawEllipse(QRectF(0,0,30 * m_dx,40 * m_dy));
}

Egg::~Egg()
{

}

qreal Egg::normalizeAngle(qreal angle)
{
    if(m_pos == leftDown || m_pos == leftUp){
    while (angle >= 360)
        angle -= 360;
    }
    else {
    while (angle <= -360)
        angle += 360;
    }
    return angle;
}

void Egg::move()
{
    int k = 1;
    qreal angle = normalizeAngle(rotation());
    if(m_pos == leftDown || m_pos == leftUp){
           if(pos().x() < m_first[(int)m_pos])
               moveBy(k * 0.7 * m_dx, 0);
           else if (pos().x() < m_second[(int)m_pos])
               moveBy(k * 0.7187 * m_dx,k * 0.8125 * m_dy);
               else
               moveBy(0.11 * m_dx,0.8125 * m_dy);


           if(angle < 180)
               setTransformOriginPoint(11 * m_dx,20 * m_dy);
           else{
            setTransformOriginPoint(19 * m_dx,20 * m_dy);
                 if (angle == 180)
                     moveBy(-15 * m_dx, 0);
               }
            moveBy(k * 0.09 * m_dx,0);
      setRotation(rotation() + 4);
   } else {

    if(pos().x() > m_first[(int)m_pos])
    moveBy(-0.7 * k * m_dx, 0);
    else if (pos().x() > m_second[(int)m_pos])
    moveBy(-0.7187 * k * m_dx,0.8125 * k * m_dy);
    else
    moveBy(-0.11 * m_dx,0.8125 * m_dy);

        if(angle > -180)
            setTransformOriginPoint(20 * m_dx,20 * m_dy);
        else{
            setTransformOriginPoint(10 * m_dx,20 * m_dy);
                if (angle == -180)
                moveBy(15 * m_dx, 0);
            }
        moveBy(-0.17 * m_dx,0 * m_dy);
   setRotation(rotation() - 4);
   }
   if(pos().y() >= m_downPos[(int)m_pos])
           emit runAnimation(this);

}

