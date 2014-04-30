#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include "updatedwidget.h"

class aboutWidget : public UpdatedWidget
{
    Q_OBJECT
    
public:
    aboutWidget(QRect& rect, QWidget *parent = 0);
    ~aboutWidget();

public slots:
    void setBack();
};

#endif // ABOUTWIDGET_H
