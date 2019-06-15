#include <stdio.h>
#include <stdlib.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int *stack_a2;
    int *stack_b2;
    int num_a;
    int num_b;
    int num_a2;
    int num_b2;
    int num;
    int *array;
    int mediana;
    int *block_count_a;
    int *block_count_b;
}              t_main;

void swipe_block_count_b(t_main *arr, int l)
{
    int i;
    int tmp;

    i =  arr->block_count_b[l - 1];
    tmp = arr->block_count_b[l - 1];
    while (i != -1)
    {
        arr->block_count_b[i + 1] = arr->block_count_b[i];
        i--;
    }
    arr->block_count_b[0] = tmp;
    i = 0;
    while (i < l)
        i++;
    while (i < l + 1)
        arr->block_count_b[i++] = 0;
}

int main(void)
{
    int i;
    int l;
    t_main arr;

    i = 0;
    l = 7;
    arr.block_count_b = malloc(sizeof(int) * 7);
    arr.block_count_b[0] = 1;
    arr.block_count_b[1] = 2;
    arr.block_count_b[2] = 3;
    arr.block_count_b[3] = 4;
    arr.block_count_b[4] = 5;
    arr.block_count_b[5] = 6;
    arr.block_count_b[6] = 7;
    swipe_block_count_b(&arr, l);
    //printf("-------------------\n");
    while (i < 7)
        printf("%d\n", arr.block_count_b[i++]);
    printf("\n");
    // i = 0;
    // while (i < arr.num_b + 3)
    //         printf("%d\n", arr.stack_b[i++]);

    return (0);
}