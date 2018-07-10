# include<stdio.h>
# define MAXLINE 1000

int get_line(char line[], int maxline);
void copy_line(char to[], char from[]);

int main()
{
    int len;  // the length of currnt line
    int max;  // the length of longest line
    char line[MAXLINE];  //curent line
    char longest[MAXLINE];  // longest line

    max = 0;
    while((len = get_line(line, MAXLINE)) > 0){
        if(max < len){
            max = len;
            copy_line(longest, line);
        }
    }
    if(max > 0){
        printf("%s\n", longest);
    }

    return 0;
}

int get_line(char line[], int maxline)
{
    int i;
    int c;

    for(i=0; i<maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void copy_line(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}
