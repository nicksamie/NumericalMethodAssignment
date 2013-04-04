#include<stdio.h>
#include<conio.h>
#include<math.h>
int i,n,count=0;
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
float Function_value(int arr[],int m,float x)
{
        float fx_val=0;
        for(i=m;i>=0;i--)
        {
              fx_val+=arr[i]*pow(x,i);
        }
       return (fx_val);        
}
main()
{
      float xL,xU,xM,fxL,fxU,fxM,error=0.0;
      printf("\t\tBISECTION METHOD\n-------------------------------------------");
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
      printf("\nEnter the interval xL : ");
      scanf("%f",&xL);
      printf("\nEnter the interval xU : ");
      scanf("%f",&xU);
      fxL=Function_value(arr,n,xL);
      //printf("\nfxL : %f",fxL);
      fxU=Function_value(arr,n,xU);
      //printf("\nfxU : %f",fxM);
      if((fxL*fxU)>0)
      {
             printf("\nxL and xU doesnot bracket any root");
      }
      else
      {
          while(1)
          {
             printf("\n\nIteration %d\n-----------",++count);             
             xM=(xL+xU)/2;
             fxM=Function_value(arr,n,xM);
             printf("\nfxM : %f",fxM);
             if(fxM==0)
             {
                root=xM;
                break;
             }
             error=fabs((xU-xL)/xU);
             if(error<0.0000005)
             {
                  root=xM;  
                  break;
             }            
             else
             {
                 if((fxM*fxU)<0){
                       xL=xM;}
                 else {           
                       xU=xM; }
             }            
            }    //end of do-while 
      }         
      printf("\nThe exact root is : %f",root);
      getch();
}
      

