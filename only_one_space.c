# include <stdio.h>

int main()
{
    int flag = 0;
    int c = getchar();
    while(c != EOF){
        if(c == ' '){
            if(0 == flag){
                putchar(c);
                flag = 1;
            }
        }
        else{
            putchar(c);
            flag = 0;
        }
        c = getchar();
    }
    return 0;
}