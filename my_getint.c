# include <stdio.h>
# include <ctype.h>
# define BUFSIZE 100 //缓冲区的最大长度
# define SIZE 100

int getch(void);
void ungetch(int);
int getint(int *np);

int n, array[SIZE];

for (n = 0; n < SIZE && getint(&array[n]) != '\n'; n++)
    ;

int getint(int *np)
{
    int c, sign;
    //跳过空白字符
    while(isspace(c = getch()))
        ;

    //舍弃无意义的字符
    if(!isdigital(c = getch()) && c != '+' && c != '-' && c != EOF && c != '\n'){
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        c = getch();
    }
    for(*np = 0; isdigit(c); c = getch()){
        *np = 10 * *np + (c - '0');
    }
    *np = sign * *np;
    if(c != EOF || c != '\n') {
        ungetch(c);
    }
    
    return c;
}


int bufp = 0;
char buf[BUFSIZ];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar(); //先减再取   首先取缓冲区中的内容(正常情况下缓冲区只存储一个数或者字符)
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetchar: too many characters\n"); //正常情况下不可能超出范围
    }
    else
    {
        buf[bufp++] = c; //先存再加
    }
}