#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int i,j;
double x[5]={1,2,3,4,5};
double fx[5]={1,1.4142,1.7321,2,2.2361};
int n=5;
double valuefx=0.0;
double point=2.5;

double lagrange(int i)
{
       double value=1;
       for(j=0;j<5;j++)
       {
            if(i!=j)
            {
                    value *=((point-x[j])/(x[i]-x[j]));
            }
       }
       return value;                           
}
int main()
{
    double pvalueX=0.0;
    for(i=0;i<n;i++)
    {
            pvalueX += fx[i] * lagrange(i);
    }
    printf("\nthe required value is %lf",pvalueX);            
    getch();
    return 0;
}
