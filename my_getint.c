# include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *np)
{
    int c, sign;
    while(isspace(c = getch()))
        ;

    //舍弃无意义的字符
    if(!isdigital(c = getch()) && c != '+' && c != '-' && c != 'EOF'){
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
    if(c != 'EOF') {
        ungetch();
    }
    
    return c;
}