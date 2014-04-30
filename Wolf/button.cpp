#include "button.h"
#include <QWidget>
#include <QBitmap>
#include "transformrect.h"
#include <QDebug>

Button::Button(QRect& rect, QPixmap& pix, QWidget * parent)
    :  QPushButton(parent)
    ,  m_initRect(rect)
    ,  m_pix(pix)
{
}

void Button::update(double dx, double dy)
{
    setGeometry(transformRect(m_initRect, dx, dy));
    if (!m_pix.isNull())
        setMask(m_pix.scaled(m_initRect.width() * dx,m_initRect.height() * dy).mask());
}
