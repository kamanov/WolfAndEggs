#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QRect>
#include <QPixmap>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QRect& rect, QPixmap& pix, QWidget * parent = 0);
    void update(double dx, double dy);

private:
    QPixmap m_pix;
    QRect m_initRect;


};

#endif // BUTTON_H
