# include <stdio.h>
# include <string.h>

# define MAXLINE 100
int getline(char * line, int max);

/*------------------------------------------------
find -x -n pattern  
将打印所有与 pattern 不匹配的行，并在每行之前打印行号
------------------------------------------------*/

main(int argc, char *argv[])
{
    char c, line[MAXLINE];
    long lineno = 0;
    int number = 0, except = 0, found = 0;

    while(--argc > 0 && (*++argv)[0] == '-'){
        while(c = *++argv[0]){
            switch(c){
                case 'n':
                    except = 1;
                    break;
                case 'x':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
            }
        }
    }

    if(argc != 1){
        printf("Usage: find -x -n pattern\n");
    }
    else{
        while(getline(line, MAXLINE) > 0){
            lineno++;
            if((strstr(line, *argv) != NULL) != except){
                if (number){
                    printf("%ld ", lineno);
                }
                printf("%s\n", line);
                found++;
            }
        }
    }

    return found;
}


/*---------------------------------------------
(*++argv)[0]: []的优先级高于 * 和 ++， 表示模式的第一个字符
*++argv[0]  : 表示当前模式的下一个字符
strstr(line, *argv) : 其中的 *argv 表示的是命令行中的 pattern
---------------------------------------------*/