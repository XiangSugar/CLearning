# include <stdio.h>
# include <string.h>

# define MAXLINES 5000

char * lineptr[MAXLINES];

int readlines(char * lineptr[], int lines);
void writelines(char * lineptr[], int lines);

void qsort(char * lineptr[], int left, int right);

main()
{
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("errror: input is too big to sort\n");
        return 1;
    }

}

# define MAXLEN 1000
int getline(char * , int);
char * alloca(int);


/*-------readlines函数，读取输入行-------*/
int readlines(char * lineptr[], int MAXLINES)
{
    int len, nlines;
    char * p, line[MAXLEN];
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0){
        if(nlines >= MAXLINES || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int getline(char * , int)
{
    int i;
    int c;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

char * alloc(int)
{
    if (n <= (allocbuf + ALLOCSIZE - allocp)){
        allocp += n;
        return (allocp - n);
    }
    else
        return 0;
}

void qsort(char * v[], int left, int right)
{
    //last是用来控制下标的一个变量
    int i, last;
    void swap(char * v[], int i, int j);

    if (left >= right) //该条件用于结束递归
        return;
    //将临界元素放到最左边，方便后面的比较
    swap(v, left, (left+right)/2);
    last = left;

    //该循环用于划分子集（把小于临界元素的放在左边，大于他的不动）
    for(i = left + 1; i <= right; i++){
        if(strcmp(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    //恢复划分子集的元素（的正确位置，使其刚好能够成为大于它的数和小于它的数的分割点）
    swap(v, left, last);
    qsort(v, left, last - 1); //对小于临界元素的子集
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char * temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n, lineptr[i]");
}