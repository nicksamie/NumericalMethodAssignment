#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int i;
double acceptableValue=0.0000000001;
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
/*TO CALULATE THE FUNTION VALUE*/
float Function_value(int arr[],int size,float x)
{
        float fx_val=0;
        for(i=size;i>=0;i--)
        {
              fx_val+=arr[i]*pow(x,i);
        }
       return (fx_val);        
}
int main(void)
{
    int n,count=0;
    float x0,x1;
    float x2,fx0,fx1,error=0.0,root;
    printf("\n\t\tSECANT METHOD\n\n");
    printf("Enter the highest degree of the equation : ");
    scanf("%d",&n);
    int arr[n+1];    
    printf("Enter the coefficient of the equation from highest order:\n");
    for(i=n;i>=0;i--)             //Taking Input coefficients of Equation
    {
           printf("?:x^%d= ",i);
           scanf("%d",&arr[i]);
    }
    display_equation(arr,n);
    printf("\n\nEnter the 1st initial guess x0 : ");
    scanf("%f",&x0);
    printf("Enter the 2nd initial guess x1 : ");
    scanf("%f",&x1);
    fx0=Function_value(arr,n,x0);
    
    do
    {
         printf("\n\tIteration %d",++count);
         printf("\n-----------------------------");
         
         printf("\nfx0=%f",fx0);
         fx1=Function_value(arr,n,x1);
         printf("\nfx1=%f",fx1);
         x2=x1-(fx1*(x1-x0))/(fx1-fx0);
         printf("\nx2=%f",x2);
         error=fabs((x2-x1)/x2);
         printf("\nerror=%f\n",error);
         if(error>acceptableValue)
         {
             x0=x1;
             x1=x2;
             fx0=fx1;                    
         }
         else 
         {
             root=x2;
             break;
         }
    }while(error>acceptableValue); //end of while
    printf("\n\n-----------------------------");
    printf("\nThe Final Root is : %f",root);
    getch();
}
