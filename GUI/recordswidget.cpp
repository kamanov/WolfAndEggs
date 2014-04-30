#include "recordswidget.h"
#include <QLabel>
#include <QMovie>
#include <QStackedWidget>

recordsWidget::recordsWidget(QRect& rect, QWidget *parent)
    : UpdatedWidget(rect, parent)
    ,tbl(new QTableWidget(10,2,this))
    ,newBut(new QPushButton(this))
{
    setWindowFlags(Qt::FramelessWindowHint);
    //set background
    QPalette p = palette();
    p.setBrush(backgroundRole(), Qt::cyan);
    setPalette(p);
    //setFixedSize(808, 533);
    setAutoFillBackground(true);
    tbl->setGeometry(50,50,270,433);

    QFont f("impact",30,30);
    QTableWidgetItem* wit=0;

    for(int i=0;i<10;i++){
        for(int j=0;j<2;j++){
            wit=new QTableWidgetItem;
            wit->setFlags(Qt::ItemIsEnabled);
            wit->setSizeHint(QSize(50,50));
            tbl->setItem(i,j,wit);
    }

}

    QStringList list;
    list<<"Имя"<<"Результат";
    tbl->setHorizontalHeaderLabels(list);

    tbl->setColumnWidth(1,90);
    tbl->setColumnWidth(0,150);
    for(int i=0;i<10;i++){
        tbl->setRowHeight(i,40);
    }

    QLabel* lbl=new QLabel(this);
    QMovie* mov=new QMovie(":/zaya.gif");
    lbl->setMovie(mov);
    mov->start();
    lbl->setGeometry(370,100,339,372);

    QPushButton* backBut=new  QPushButton(this);
    backBut->setGeometry(15,500,87,27);
    backBut->setText("НАЗАД");
    QObject::connect(backBut,SIGNAL(clicked()),this,SLOT(setBack()));


    newBut->setGeometry(650,500,117,27);
    newBut->setText("НОВАЯ ИГРА");
}

recordsWidget::~recordsWidget()
{
    
}

void recordsWidget::printRecords(std::multimap<int, QString> &recs)
{
    std::multimap<int,QString>::reverse_iterator it=recs.rbegin();
    int sz=recs.size();
    for (int i=0;i<sz;i++){
       tbl->item(i,0)->setText((*it).second);
       tbl->item(i,1)->setText(QString::number((*it).first));
        ++it;
    }

}

void recordsWidget::setBack()
{
     emit static_cast<QStackedWidget*>(parent())->setCurrentIndex(1);
}
