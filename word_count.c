/*
    自引用结构：
    统计输入中所有单词的出现频率
    二叉树
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100 //缓冲区的最大长度

int bufp = 0;
char buf[BUFSIZ];
struct tnode{
    char * word;
    int count;
    struct tnode * left;
    struct tnode * right;
}

struct tnode * addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);
int getword(char *word, int lim);

main()
{
    struct tnode * root;
    char word[MAXWORD];
    root = NULL;

    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]))
            root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}

/*
    talloc:  分配新节点的存储空间
    strduop: 将新单词复制到某个隐藏位置
*/
struct tnode * talloc(void);
char * strdup(char *);

struct tnode * addtree(struct tnode *p, char *w)
{
    int cond;

    if(p == NULL){
        p = talloc();
        /*检测是否分配成功*/
        if(p == NULL)
            return "节点空间分配失败！"
        p->word = strdup(w);
        /*出错检查*/
        if(p->word == NULL)
            return "字符复制失败！"
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w , p->word)) == 0)
        p->count++;
    else if(conf < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void treepint(struct tnode *)
{
    if(p != NULL){
        treepint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);  // +1 是因为加上 '\0' 的空间
    if(p != NULL)
        strcopy(p, s);
    return p; //如果上面分配失败，则 p 为 NULL
}

int getword(char * word, int lim)
{
    int c, getchar(void);
    void ungetch(int);
    char * w = word;

    while(isspace(c = getchar()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++){
        if(!isalnum(*w = getchar())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}