# include<stdio.h>

int bitcount(unsigned x);

int main()
{
    /* code */
    int c;
    int Bitcount;
    c = getchar();
    printf("The value of c = %d\n", c);
    Bitcount = bitcount(c);

    printf("bitcount of c: Bitcount = %d\n", Bitcount);
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    // The expression x&=(x-1) can delete a binary bit with the rightmost value of 1 in x
    for(b = 0; x != 0; x &= (x-1)){
        b++;
        // printf("x = %d\n", x);
    }
    return b;
}
