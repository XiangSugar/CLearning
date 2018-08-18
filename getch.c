# include <stdio.h>
# define BUFSIZE 100  //缓冲区的最大长度
int bufp = 0;
char buf[BUFSIZ];

int getch(void)
{
    return (bufp>0) ? buf[--bufp] : getchar(); //先减再取   首先取缓冲区中的内容(正常情况下缓冲区只存储一个数或者字符)
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE){
        printf("ungetchar: too many characters\n"); //正常情况下不可能超出范围
    }
    else{
        buf[bufp++] = c;    //先存再加
    }
}