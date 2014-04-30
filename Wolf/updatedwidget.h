#ifndef UPDATEDWIDGET_H
#define UPDATEDWIDGET_H

#include <QWidget>
#include <QRect>

class UpdatedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpdatedWidget(QRect& rect, QWidget *parent = 0);
    virtual void update(double dx, double dy);

private:
    void resizeBackground(double dx, double dy);
    QRect m_initRect;
protected:
    QPixmap m_background;
    
};

#endif // UPDATEDWIDGET_H
