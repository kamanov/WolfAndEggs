#ifndef CFIRST_H
#define CFIRST_H


#include <QObject>
#include <iostream>

class CFirst : public QObject
{
    Q_OBJECT

public:
   CFirst();

public slots:
   void process();

signals:
   void finished();

private:
   int value;
};

#endif // CFIRST_H
