#include<stdio.h>
#include<math.h>
int main()
{
    double x,y;
    scanf("%lf",&x);
    if(x<-5)
    {
        y=x/4+pow(x,3);
        printf("y=%f",y);
    }
    if(x>=-5&&x<0)
    {
        y=abs((int)x);
        printf("y=%f",y);
    }
    if(x>0)
    {
        y=2*sin(x);
        printf("y=%f",y);
    }
    return 0;
}
