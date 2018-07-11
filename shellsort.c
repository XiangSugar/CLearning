# include <stdio.h>
# define LEN 10

void shellsort(int v[], int n);

int main()
{
    int i;
    int m[LEN] = {4,2,7,9,1,3,8,0,5,6};

    printf("Before: ");
    for(i = 0; i < LEN; i++){
        printf("%d  ", m[i]);
    }
    printf("\n");

    shellsort(m, LEN);

    printf("After : ");
    for(i = 0; i < LEN; i++){
        printf("%d  ", m[i]);
    }
    printf("\n");

    return 0;
}

void shellsort(int v[], int n)
{
    int i, j;
    int gap;  //步长
    int temp; //中间变量
    for(gap = n/2; gap > 0; gap /= 2){
        for(i=gap; i < n; ++i){
            for(j=i-gap; j>= 0 && v[j] > v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}



//----------------ERROR---------------------

// void shellsort(int v[], int n)
// {
//     int i, j;
//     int gap;  //步长
//     int temp; //中间变量
//     for(gap = n/2; gap > 0; gap /= 2){
//         for(i=gap; i < n; ++i){
//             if(v[i-gap] > v[i]){
//                 temp = v[j];
//                 v[j] = v[j+gap];
//                 v[j+gap] = temp;
//             }
//         }
//     }
// }
//----------------ERROR------------------------