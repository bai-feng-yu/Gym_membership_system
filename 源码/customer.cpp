#include "customer.h"

customer::customer() {}

float customer::sale(int level)        //判断折扣
{
    float sale;              //接受折扣

    //判断折扣大小
    if (level>=10&&level<=30)
    {
        sale=0.9;
    }
    else if(level>=31&&level<=70)
    {
        sale=0.85;
    }
    else if(level>=71&&level<=100)
    {
        sale=0.8;
    }
    else if(level>100)
    {
        sale=0.7;
    }
    else
    {
        sale=1;
    }

    return sale;
}
