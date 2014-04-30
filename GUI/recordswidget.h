#ifndef RECORDSWIDGET_H
#define RECORDSWIDGET_H
#include <QTableWidget>
#include <QWidget>
#include <QPushButton>
#include "updatedwidget.h"
#include "button.h"

class recordsWidget : public UpdatedWidget
{
    Q_OBJECT
    
public:
    virtual void update(double dx, double dy);
    recordsWidget(QRect& rect, QWidget *parent = 0);
    ~recordsWidget();
    void printRecords(std::multimap<int,QString>& recs);
    QPushButton* newBut;

private:
    QTableWidget* tbl;
    QRect m_tableRect;
public slots:
    void setBack();
};

#endif // RECORDSWIDGET_H
