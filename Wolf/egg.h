#ifndef Egg_H
#define Egg_H

#include <QGraphicsObject>

class Egg : public QGraphicsObject
{
    Q_OBJECT
public:
    enum EggPosition {leftUp,leftDown,rightUp,rightDown};
    explicit Egg(EggPosition p, double dx, double dy, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*,QWidget*);
    EggPosition getPos(){return m_pos;}
    ~Egg();
    
signals:
    void runAnimation(Egg*);
public slots:
    void move();
private:
    double m_dx;
    double m_dy;
    EggPosition m_pos;
    qreal normalizeAngle(qreal angle);
    bool b;
    static const QPoint sPos[4];
    static const qreal first[4];
    static const qreal second[4];
    static const qreal downPos[4];

    QPoint m_sPos[4];
    qreal m_first[4];
    qreal m_second[4];
    qreal m_downPos[4];

};

#endif // Egg_H
