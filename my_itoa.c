# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define LEN 10

void my_reverse(char s[]);
void my_itoa(int date, char s[]);

int main(void)
{
    int data = 54321;
    char s[LEN] = {'0', '0', '0', '0', '\0'};
    //printf("s = %s\n", s);
    my_itoa(data,s);
    printf("result = %s\n", s);

    return 0;
}

void my_itoa(int data, char s[])
{
    //printf("进入转换函数。");
    int i = 0;
    int sign;
    if((sign = data) < 0){
        data = -data;
    }
    do{
        s[i++] = data % 10 + '0';
    }while((data/10) > 10);
    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    //printf("中间值： %s\n", s);
    my_reverse(s);
}

void my_reverse(char s[])
{
    //printf("进入反转函数。");
    int c, i, j;

    for(i=0, j=strlen(s)-1; i<j; i++, j--){
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

