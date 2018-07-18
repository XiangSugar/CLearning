# include<stdio.h>

# define IN 1
# define OUT 0

int main()
{
    /* code */
    int c, nl, nc, nw, state;
    nl = nc = nw = 0;
    state = OUT;
    //输入的字符如果有0，则退出循环，计数从 0 处截止
    while((c = getchar()) != EOF && c != '0'){
        ++nc;
        if(c == '\n'){
            ++nl;
        }
        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nc, nw);

    return 0;
}