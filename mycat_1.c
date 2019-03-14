/*
    function: cat
    version: 1.0
*/

#include <stdio.h>

void main(int argc, char *argv)
{
    FILE *fp;
    void filecopy(FILE *, FILE *);

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
                printf("cat: can not open file: %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
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