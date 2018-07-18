# include <stdio.h>

int main()
{
    int c, i;
    int ndigit[10];
    int nwhite = 0;
    int nothers = 0;
    for(i=0; i<10; ++i){
        ndigit[i] = 0;
    }
    // 回车键结束程序
    while((c = getchar()) != '\n'){
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
        //    case '\n':
            case '\t':
            case ' ':
                nwhite++;
                break;
            default:
                nothers++;
                break;
        }
    }
    printf("\ndigits: 0  1  2  3  4  5  6  7  8  9\n");
    printf("number: ");
    for(i=0; i<10; ++i){
        printf("%d  ", ndigit[i]);
    }
    printf("\nnumber of white space: %d\nother space: %d\n\n", nwhite, nothers);

    return 0;
}