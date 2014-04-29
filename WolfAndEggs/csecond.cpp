#include "csecond.h"

CSecond::CSecond()
{
}


void CSecond::process(){

    for(int i=0; i!=1000; ++i)
       std::cout << "2";

    emit finished();
}
