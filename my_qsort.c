#include <stdio.h>

void qsort(int v[], int left, int right);

int main(void)
{
    int v[] = {4, 6, 3, 2, 1, 0, 7, 5};
    for (int j = 0; j < 8; j++)
    {
        printf("%d    ", v[j]);
    }
    printf("\n");

    qsort(v, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d    ", v[i]);
    }
    printf("\n");

    return 0;
}
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    //    printf("%s\n", v);
    for (int j = 0; j < 8; j++)
    {
        printf("%d    ", v[j]);
    }
    printf("\n");
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    char temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*-------------------------------------------------------------
4    6    3    2    1    0    7    5    原始序列
0    1    2    4    6    3    7    5    void qsort(int  v[], int left, int right)
0    1    2    4    6    3    7    5    qsort(v, left, last - 1);
0    1    2    3    6    4    7    5    qsort(v, last + 1, right);
0    1    2    3    4    6    7    5    qsort(v, last + 1, right);
0    1    2    3    4    5    6    7    qsort(v, last + 1, right);
0    1    2    3    4    5    6    7    qsort(v, left, last - 1);
0    1    2    3    4    5    6    7    第归调用结束后的结果打印（main函数中的）
-------------------------------------------------------------*/