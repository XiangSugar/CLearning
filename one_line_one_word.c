# include<stdio.h>
# define FIRST 1
# define MEANINGLESS 0

int main()
{
    /* code */
    int c, state;
    state = MEANINGLESS;
    while((c = getchar()) != EOF && c != '0'){
        if(c == ' ' || c == '\t'){
            if(state == FIRST){
                printf("\n");
                state = MEANINGLESS;
            }
        }
        else{
            putchar(c);
            state = FIRST;
        }
    }
    return 0;
}