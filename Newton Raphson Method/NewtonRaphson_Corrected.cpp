#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define PRECISION 0.000000001
int i,count=0;
float root;
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
/*TO CALULATE THE FUNTION VALUE*/
float newtFunction_value(int arr[],int m,float x)
{
        float fx_val=0;
        for(i=m;i>=0;i--)
        {
              fx_val+=arr[i]*pow(x,i);
        }
       return (fx_val);        
}
int main(void)
{
    int n;
    float x0,x1,fx1,fderix,error;
    printf("\t\tNEWTON RAPHSON METHOD\n---------------------------------------------------------");
    printf("\nEnter the highest degree of the equation : ");
    scanf("%d",&n);
    int arr[n+1];
    printf("\nEnter the coefficient of the equation :\n");
    for(i=n;i>=0;i--)
    {
           printf("?:x^%d= ",i);
           scanf("%d",&arr[i]);
    }
    display_equation(arr,n);
    int* deri = derivative(arr,n);
    printf("\nThe Derivative with ");
    display_equation(deri,n-1);
    printf("\nEnter the initial guess x0 : ");
    scanf("%f",&x0);
    while(1)
    {
            printf("\n\n\tIteration %d",++count);
            printf("\n-------------------------");
            printf("\nCurrent x0 : %f",x0);
            fx1 = newtFunction_value(arr,n,x0);
            printf("\nfx1 value : %f",fx1);

            fderix = newtFunction_value(deri,n-1,x0);
            printf("\nf'x value: %f",fderix);
    
            x1=x0-(float)(fx1/fderix);
            printf("\nnew x1 : %f",x1);
    
            error=fabs((x1-x0)/x1);
            printf("\nerror is : %f",error);
            if(error<PRECISION)
            {
                       root=x0;
                       printf("\n\n---------Final root is %f---------------",root);
                       break;
            }
            else
            {
                       x0=x1;
            }        
    }//end of while
    getch();
    return 0;
}
