//some codes about string array、pointer and function

//------------------memory allocation------------------
# include <stdio.h>

# define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char * allocp = allocbuf;

char * alloc(int n)
{
    if(n <= (allocbuf + ALLOCSIZE - allocp)){
        allocp += n;
        return (allocp - n);
    }
    else
        return 0;
}

void allocfree(char * p)
{
    if(p < (allocbuf + ALLOCSIZE) && p >= allocbuf){
        allocp = p;
    }
}

// ----------------The length of string----------------
int strlen(char * s)
{
    char * p = s;
    while(*p != '\0'){
        p++;
    }
    return (p-s);
}

// ----------------How to copy a string----------------
void strcp_1(char * s, char * t)
{
    int i;
    i = 0;
    while((s[i] = t[i]) != '\0'){
        i++;
    }
}

void strcp_2(char * s, char * t)
{
    while((*s = *i) != '\0'){
        s++;
        t++;
    }
}

void strcp_3(char *s, cahr * t)
{
    while(*s++ = *t++)
        ;
}

// ------------------Compare strings---------------------
int strcmp(char * s, char * t)
{
    int i;
    for(i = 0; s[i] == t[i]; ++i){
        if(s[i] == '\0'){
            return 0;
        }
    }
    return s[i] - t[i];
}

int strcmp_2(cha * s, char * t)
{
    for(; *s == *t; s++, t++){
        if(*s == '\0'){
            return 0;
        }
    }
    return *s - *t;
}

// -------------------------------------------------------