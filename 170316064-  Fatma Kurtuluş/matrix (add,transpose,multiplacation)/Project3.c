#include<stdio.h>
#include<conio.h>
#include<time.h>


/*void read_arr(int a[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
        printf("(%d,%d): ",i,j);
        scanf("%d",&a[i][j]);
            }
    }
}
void print_arr(int m[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
        {
        for(j=1;j<=col;j++)
        {
            printf(" %d ",m[i][j]);
         }
        printf("\n");
        }
}

*/
void mRand(int[10][10],int rows,int columns);
void tran_arr(int[10][10],int rows,int col);
void mul_arr(int[10][10],int[10][10],int ro,int,int);
void add_arr(int[10][10],int [10][10],int ort,int row,int col);

void tran_arr(int m1[10][10],int rows,int col)
{
    	int  i,j;
    	for(i=0; i<rows; i++)
    		for(j=0; j<col;j++)
    		{
       			printf("%d",m1[j][i]);
    		}
}
void mul_arr(int m1[10][10],int m2[10][10],int row,int col,int col1)
{
    int i,j,k;
    int mulM[10][10];
    for(i=0;i<row;++i)
    {
        mulM[i][j]=0;
    }

     for(i=0;i<=row;i++)
            for(j=0;j<=col;j++)
                for (k=0;k<=row;k++)
                {
                    mulM[i][j] += m1[i][k]* m2[k][j];
                }
    for(i=0;i<row;++i)
        for(j=0;j<col1;++j)
        {
            printf("\t%d",mulM[i][j]);
            if(j==col1-1)
            printf("\n\n");
        }
}

void mRand(int a[10][10],int rows,int columns)
{
    int i,j,random;
        for(i=0;i<rows;i++)
            {
            for(j=0;j<columns;j++)
            {
              random=rand()%36+1;

              a[i][j]=random;
              printf("%i ",a[i][j]);
            }
            printf("\n");
        }
}
void add_arr(int m1[10][10],int m2[10][10],int ort,int row,int col)
{
    int i,j,sum[10][10],sum1[10][10];
    for(i=1;i<=row;i++){
            for(j=1;j<=col;j++)
            {
                sum1[i][j] = ort* m2[i][j];
            }
    }
    for (i=0;i<row;i++){
        for(j=0;j<col;j++){
            sum[i][j]=m1[i][j]+sum1[i][j];
            printf("\t%d",sum[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int m1[10][10],m2[10][10],row,col,choice,row1,col1;
    int ort=1;
    char again='Y';
    char again1='y';

    printf("please select.\n");
    srand((unsigned)time(NULL));

    while(again=='Y'||again1=='y'){

    printf("1)Transpose\n2)Addition\n3)Multiplication\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {

    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row,&col);
    printf(" Element of first matrix\n");
    mRand(m1,row,col);
    printf(" Transpose\n");
    tran_arr(m1,row,col);
    break;
    }

    case 2:
    {

    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row,&col);

    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row1,&col1);
    while((row!=row1)&&(col!=col1)){
    printf("\nMatrices must be the same size\n");
    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row,&col);

    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row1,&col1);
    }
    printf(" First matrix\n");
    mRand(m1,row,col);

    printf(" Second matrix\n");
    mRand(m2,row1,col1);

    printf(" Result\n");
    add_arr(m1,m2,ort,row,col);
    //print_arr(m3,row,col);
    break;
    }
    case 3:
    {
    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row,&col);

    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row1,&col1);

    while(col!=row1){
    printf("\n\nError! column of first matrix not equal to row of second.\n\n");
    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row,&col);

    printf("Enter number value of rows and columns:");
    scanf("%d%d",&row1,&col1);
    }
    printf(" First matrix\n");
    mRand(m1,row,col);
    printf(" Second matrix\n");
    mRand(m2,row1,col1);

    printf(" Result\n");
    mul_arr(m1,m2,row,col,col1);
    break;
    }
    default:
    printf("\nInvalid Choice");
}
        printf("\n\nDo you want to calculate again? Y/N\n");
        scanf(" %c", &again);
}
}

