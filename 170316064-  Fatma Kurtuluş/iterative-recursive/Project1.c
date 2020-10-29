#include <stdio.h>
#include <stdlib.h>
int recursive(int,int);
int iterative(int);
int main()
{
 int a=0,b=0,k;
 printf("Enter your values for sum(a,b) :");
 scanf("%d%d",&a,&b);
 printf("Recursive: %d",recursive(a,b));
 k=b;
 if(a<b){
    for(int i=1;i<=a;i++){
        b=iterative(b);
    }
    printf("\nIterative: %d",b);
 }
 if(b<a){
    k=a;
    for(int i=1;i<=b;i++)
        a=iterative(a);
    printf("\nIterative: %d",a);
 }
 return 0;
}               //5     3
int recursive(int a,int b){
    int i,sum=0;
   if(b<a){
    for(int j=1;j<=b;j++)
    {
     sum=0;
     for(i=1; i<=a; i++)
        {
          sum=sum+i;
        }
        a=sum;
        }
        return a;
    }
if(a<b){
    for(int j=1;j<=a;j++){
        sum=0;
        for(int i=0;i<=b;i++){
            sum+=i;
        }
        b=sum;
    }
    return b;
}
}
int iterative(int a){
    if(a==1)
       return 1;
    return a+iterative(a-1);

}
