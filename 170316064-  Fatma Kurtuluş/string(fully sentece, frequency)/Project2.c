#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define str_size 100
#define chr_no 255

void main()
{
    char str[str_size];
	int ch_fre[chr_no];
	int used[26]={0},total=0;
    int i = 0, max;
    int ascii;

       printf("Input the string : ");
       fgets(str, sizeof str, stdin);
    for(i=0;str[i]!='\0';i++){
        if('a'<=str[i]&&str[i]<='z'){
            total+=!used[str[i]-'a'];
            used[str[i]-'a']=1;
        }
        else if('A'<=str[i]&&str[i]<='Z'){
            total+=!used[str[i]-'A'];
            used[str[i]-'A']=1;
        }
    }
    for(i=0; i<chr_no; i++)
    {
        ch_fre[i] = 0;
    }
    i=0;
    while(str[i] != '\0')
    {
        ascii = str[i];
        ch_fre[ascii] += 1;
        i++;
    }
    max = 0;
    for(i=0; i<chr_no; i++)
    {
        if(i!=32)
        {
        if(ch_fre[i] > ch_fre[max])
            max = i;
        }
    }
    if(total==26)
        printf("\nFully sentence");
    else
        printf("\nNot fully sentence");
    printf("\nThe Highest frequency of character '%c' appears number of times : %d \n\n", max, ch_fre[max]);
}
