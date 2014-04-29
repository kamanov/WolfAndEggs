#include "cfirst.h"

CFirst::CFirst()
{
}

void CFirst ::process(){

    for(int i=0; i!=1000; ++i)
       std::cout << "1";

    //emit sendReport(obj);  // where obj have information
    emit finished();
}


