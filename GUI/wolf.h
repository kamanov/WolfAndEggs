#ifndef WOLF_H
#define WOLF_H
#include <QtWidgets/QGraphicsObject>


class Wolf : public QGraphicsObject
{
    Q_OBJECT

public:
    enum WolfPosition {leftUp,leftDown,rightUp,rightDown};
    Wolf(QGraphicsItem * parent = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*,QWidget*);
    bool getAvaible(){return avaible;}
    void setAvaible(bool b){avaible=b;}
    void update(double dx, double dy);
public slots:
    void changePos(Wolf::WolfPosition p);

private:
    bool avaible;
    QPixmap pix[4];
    QRect shapes[4];
    QPoint pos[4];
    QPixmap m_initPix[4];
    QSize initWolfPix[4];
    QRect initShapes[4];
    QPoint initPos[4];
    int curVal;
};
//sqRegisterMetaType("Wolf::WolfPosition");
Q_DECLARE_METATYPE(Wolf::WolfPosition)

#endif // WOLF_H
