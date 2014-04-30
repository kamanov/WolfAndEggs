#include "updatedwidget.h"
#include "button.h"
#include "transformrect.h"
#include <QDebug>

UpdatedWidget::UpdatedWidget(QRect& rect, QWidget *parent)
    :  QWidget(parent)
    ,  m_initRect(rect)
{
}

void UpdatedWidget::update(double dx, double dy)
{
    setGeometry(transformRect(m_initRect, dx, dy));
    resizeBackground(dx, dy);
    QList<Button*> ls = this->findChildren<Button*>();
    foreach (Button* w, ls) {
        w->update(dx, dy);
    }
    updateGeometry();

}

void UpdatedWidget::resizeBackground(double dx, double dy)
{
    QPalette p = palette();
    if (!m_background.isNull()) {
        p.setBrush(backgroundRole(), QBrush(m_background.scaled(transformRect(m_initRect, dx, dy).size())));
        setPalette(p);
    }
}
