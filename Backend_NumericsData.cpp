#include "Backend_NumericsData.h"
#include<math.h>

int BackendNumericsData::cm2HValue=21;
int BackendNumericsData::mvValue=10;
int BackendNumericsData::o2Value=57;

BackendNumericsData::BackendNumericsData()
{

}

int BackendNumericsData::getcm2H()
{
    cm2HValue++;
    if(cm2HValue > 52)
        cm2HValue =8;

    return cm2HValue;
}

int BackendNumericsData::getMV()
{
    mvValue+=1;
    if(mvValue > 15 )
        mvValue=0;

    return mvValue;
}

int BackendNumericsData::getO2()
{
    o2Value+=3;

    if(o2Value > 56)
        o2Value=2;

    return o2Value;

}
