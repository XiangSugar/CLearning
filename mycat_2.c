/*
    function: cat
    version: 2.0
*/

#include <stdio.h>

void main(int argc, char *argv)
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; //存储程序名，用于错误处理

    if (1 == argc)
    {
        filecopy(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if (NULL == (fp = fopen(*++argv, "r")))
            {
                fprintf(stderr, "%s: can not open %s\n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

/*
    function: filecopy
    copy ifp into ofp
*/
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}