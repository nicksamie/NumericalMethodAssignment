#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PRECISION 0.05
int i;
double acceptableValue=0.0000000001;
void display_equation(int a[],int size)
{
     printf("Equation format is: ");
     for(i=size;i>=0;i--)
     {
         printf("%d",a[i]);
         if(i==0){
         break;}
         printf("x^%d + ",i);
     }
}
float Function_value(int arr[],int size,float x)
{
        float fx_val=0;
        for(i=size;i>=0;i--)
        {
              fx_val+=arr[i]*pow(x,i);
        }
       return (fx_val);        
}
main()
{
    int n,count=0;
    float x0,x1,error=0.0;
    printf("\n\t\tFIXED POINT METHOD\n\n");
    printf("Enter the highest degree of the equation : ");
    scanf("%d",&n);
    int arr[n+1],gXar[n+1];    
    printf("Enter the coefficient of the equation from highest order:\n\n");
    for(i=n;i>=0;i--)      //Taking Input coefficients of Equation
    {
           printf("?: x^%d = ",i);
           scanf("%d",&arr[i]);
    }
    display_equation(arr,n);
    printf("\n");
    for(i=n;i>=0;i--)
    {
           printf("arr[%d]=%d\n",i,arr[i]);
    }
    for(i=n;i>=0;i--)       //New Array for new equation g(x)
    {
           gXar[i]=arr[i];
           if(i==1)
                gXar[1]=arr[1]+1;
    }
    printf("\tNew Function g(x) is:\n");
    display_equation(gXar,n);
    printf("\nEnter the initial guess x0 : ");
    scanf("%f",&x0);
    
    do//loop starts
    {
             printf("\n\tIteration %d",++count);
             printf("\n---------------------------");
             x1=Function_value(gXar,n,x0);
             printf("\nx1  = %f",x1);;
             error=fabs((x1-x0)/x1);
             printf("\nerror=%f\n",error);
             if(error>PRECISION)
             {
                           x0=x1;
             }
             else
             {
                           printf("\nThe root is = %f",x1);
                           break;
             }  
    }while(error>PRECISION); //end of do-while
    getch();
}
