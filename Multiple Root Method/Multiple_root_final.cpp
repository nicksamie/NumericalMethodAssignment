#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define PRECISION 0.00001
int *arr;
int i,n,count=0;
float temproot,temp,xR;
float x0,x1,fx1,fderix,error;
void display_equation(int a[],int size)
{
     printf("The equation format is: ");
     for(i=size;i>=0;i--)
     {
         printf("%d",a[i]);
         if(i==0){
         break;}
         printf("x^%d + ",i);
     }
}
int * derivative(int * arr, int n)
{    
    int *deriv = (int*)malloc(n+1);
    for(int i=n;i>0;i--)
    {
            deriv[i-1]=arr[i]*i;
    }
    return deriv;
}
float newtFunction_value(int arr[],int m,float x)
{
        float fx_val=0;
        for(i=m;i>=0;i--)
        {
              fx_val+=arr[i]*pow(x,i);
        }
       return (fx_val);        
}
    //NEWTON RAPHSON STARTS
float newtonRaphson(int arr[],int n,float x0)
{
    int* deri = derivative(arr,n);
    while(1)
    {
            fx1 = newtFunction_value(arr,n,x0);           
            fderix = newtFunction_value(deri,n-1,x0);
            x1=x0-(float)(fx1/fderix);
            error=fabs((x1-x0)/x1);
            if(error<PRECISION){
                       temproot=x0;
                       break;
            }
            else{
                       x0=x1;
            }            
    }//end of while
    return (temproot);
}// END NEWTON RAPHSON FUNTION

/*-----------SYNTHETIC DIVISION----------------------------------*/
void synthetic_division(int *x,int a,int size)
{
      int s[size],p[size];
      p[size]=0;   
       
      for(i=size;i>=0;i--)
      {
          s[i]= x[i]+p[i];
          p[i-1]=a*s[i];                             
      } 
      int j=size-1;
      for(i=size,j;j>=0;j--,i--)
      {
          arr[j]=s[i];
      }
}
//--------------------------------- MAIN STARTS-------------------
int main(void)
{
    printf("\t\tMULTIPLE ROOT CALCULATION METHOD\n---------------------------------------------------------");
    printf("\nEnter the highest degree of the equation : ");
    scanf("%d",&n);   
    arr = (int*) malloc(n+1);
    float root;
    printf("\nEnter the coefficient of the equation :\n");
    for(i=n;i>=0;i--)
    {
           printf("?:x^%d= ",i);
           scanf("%d",&arr[i]);
    }
    printf("\nEnter the initial guess x0 :");
    scanf("%f",&x0);
    
    while(n>1)
    {
           printf("\niteration %d\n-----------------",++count);
           xR=newtonRaphson(arr,n,x0);
           printf("\nThe root from Newton Raphson is = %f\n",xR);
           synthetic_division(arr,xR,n); //pass (array=arr, root=xR , size=n)   
           --n;     
    }
    root=-(arr[0]/arr[1]);
    printf("the last root = %f",root);
    getch();
    return 0;
}
    
    

