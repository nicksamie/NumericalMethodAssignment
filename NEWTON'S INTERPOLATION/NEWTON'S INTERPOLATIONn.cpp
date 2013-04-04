#include<stdio.h>
#include<conio.h>
//#include<math.h>
//double nwfunction(int,int);
int i,j;
    double x[5]={0,10,15,20,30};
    double fx[5]={0,227.04,362.78,517.35,901.67};
    int n=4;
    int pointx=16;
double nwfunction(int k,int i)
{
    double ret;
    if(k==i)
    {
            ret= fx[k];
    }
    else if(k==i-1)
    {
             ret=(fx[i]-fx[k])/(x[i]-x[k]);
    }
    else
    {
         ret=(nwfunction(k+1,i) - nwfunction(k,i-1))/(x[i]-x[k]);
    }
    printf("\nreturned value %lf",ret);
    return ret;
}

int main()
{  
    int k=0;
    double estimate=0;
    for(i=1;i<=n;i++)
    {
                     double fxoi=nwfunction(k,i);
                     //printf("\na%d = %lf",i,fxoi);
                     double newproduct=1.0;
                     for(j=0;j<=i-1;j++)
                     {
                             newproduct*=(pointx-x[j]);
                     }
                     estimate += fxoi * newproduct;
    } 
    printf("\nthe value of fx : %lf",estimate);         
    getch();
    return 0;
}
    
    
    
