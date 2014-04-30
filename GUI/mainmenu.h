#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

#include "updatedwidget.h"

class mainMenu : public UpdatedWidget
{
    Q_OBJECT
    
public:
    mainMenu(QRect& rect, QWidget *parent = 0);
    ~mainMenu();

public slots:
    void setAbout();
    void setManage();
    void setCont();
    void setRecs();

};

#endif // MAINMENU_H
