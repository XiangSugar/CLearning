# include <stdio.h>
# define LEN1 20
# define LEN2 120
void char_expand(char s1[], char s2[]);

int main()
{
    int i;
    char s1[LEN1] = {'-','1','-','9','a','-','f',' ','o','p','q','t','-',' ','d','m','G','o','-','\0'};
    char s2[LEN2];
    printf("s1 = %s\n", s1);
    for(i=0; i<LEN2; ++i)
        s2[i] = '\0';

    char_expand(s1, s2);

    printf("Before: %s\n", s1);
    printf("After : %s\n", s2);
    
    return 0;
}

void char_expand(char s1[], char s2[])
{
    int i, j = 0;
    int k;  //Make s[j] in the expansion loop increase sequentially
    int t;  //Control the number of loops of the extended loop
    int interval_length = 0;
    printf("Fuction: char_expand()\n");

    for(i=0; i<LEN1; i++,j++)
    {
        if(s1[i] == '-')
        {
            if(i == 0 || i == LEN1-1)
                s2[j] = s1[i];
            else if(s1[i-1] == ' ' || s1[i+1] == ' ')
                s2[j] = s1[i];
            else
            {
                interval_length = s1[i+1] - s1[i-1] - 1;
                if(interval_length <= 0)
                    s2[j] = s1[i];
                else
                {
                    t = j;
                    //expansion loop
                    for(k=1; j<t+interval_length; j++)
                    {
                        s2[j] = (char)(s1[i-1] + k);
                        k++;
                    }
                    j--; //
                }
            }
        }
        else
            s2[j] = s1[i];
    }
    return;
}