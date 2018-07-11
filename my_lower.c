# include <stdio.h>

char my_lower(char c);

int main()
{
    int c;
    int lower_c;
    // 空格键退出程序
    printf("You can shutdown this program by using the 'space' bar.\n");
    while((c = getchar()) != ' '){
        /* code */
        lower_c = my_lower(c);
        //避免空格键的干扰
        if(lower_c == -1)
            ;
        else
            printf("%c <====> %c\n", c, lower_c);
    }
    return 0;
}

char my_lower(char c)
{
    if('A' <= c && c <= 'Z')
        return c + 'a' - 'A';
    else if('\n' == c)
        return -1;
    else
        return c;
}