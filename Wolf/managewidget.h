#ifndef MANAGEWIDGET_H
#define MANAGEWIDGET_H

#include <QWidget>
#include "button.h"
#include "updatedwidget.h"
class manageWidget : public UpdatedWidget
{
    Q_OBJECT
    
public:
    manageWidget(QRect& rect, QWidget *parent = 0);
    ~manageWidget();
public slots:
    void setBack();
};

#endif // MANAGEWIDGET_H
