# include <stdio.h>
# include <stdlib.h>   //使用系统的 atof()
# include <ctype.h>

# define MAXOP 100  //操作数或者运算符的最大长度
# define NUMBER '0'  //标识找到一个数
# define BUFSIZE 100  //缓冲区的最大长度
# define MAXVAL 100  //栈的最大深度

int sp = 0;   //下一个空闲栈位置
double val[MAXVAL];   //栈值
char buf[BUFSIZE];   //用于 ungetch() 的缓冲区
int bufp = 0;        //buf中下一个空闲位置

//各函数的声明
int getop(char []);
int getch(void);
void push(double);  //把 f 压入到栈值中
double pop(void);   //弹出并返回栈顶的值
void ungetch(int);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0){
                    push(pop() / op2);
                }
                else{
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

//该函数由主函数的while循环来循环执行
int getop(char s[])                             //传入的 s[] 其实是空的 用于存放从输入中读取到的操作数或者操作符
{
    int i, c;

    //跳过字符串开头的所有的空白字符，后面的不管
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    //s[1] = '\0';
    if(!isdigit(c) && c != '.'){
        s[1] = '\0';
        return c;
    }
    //    return c;                               // 返回操作符

    i = 0;
    if (isdigit(c)){
        while (isdigit(s[++i] = c = getch()))  //判断下一位，如果为数字，继续收集，直到不是数值为止
            ;
    }
    if (c == '.'){
        //如果是小数点，则要继续收集该浮点数的小数部分，所以有如下代码
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';                               //加入字符串结束标志位
    if (c != EOF)                              //如果输入中后面还有内容，则将多读取的用于判断的位压回到缓冲区
        ungetch(c);
    
    return NUMBER;                             //返回操作数
}

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

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}