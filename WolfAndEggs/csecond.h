#ifndef CSECOND_H
#define CSECOND_H


#include <QObject>
#include <iostream>

class CSecond : public QObject
{
    Q_OBJECT

public:
    CSecond();

public slots:
    void process();

signals:
   void finished();

private:
   int value;
};

#endif // CSECOND_H
