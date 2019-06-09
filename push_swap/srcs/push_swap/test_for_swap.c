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
    int j;
    int *tmp;
    
    i = 0;
    j = l - 1;
    tmp = malloc(sizeof(int) * l + 1);
    while (j != -1)
        tmp[i++] = arr->block_count_b[j--];
    j = 0;
    i = 0;
    while (j < l)
        arr->block_count_b[i++] = tmp[j++];
}

int main(void)
{
    int i;
    int l;
    t_main arr;

    i = 0;
    l = 5;
    arr.block_count_b = malloc(sizeof(int) * 5);
    arr.block_count_b[0] = 1;
    arr.block_count_b[1] = 2;
    arr.block_count_b[2] = 3;
    arr.block_count_b[3] = 4;
    arr.block_count_b[4] = 5;
    swipe_block_count_b(&arr, l);
    //printf("-------------------\n");
    while (i < 5)
        printf("%d\n", arr.block_count_b[i++]);
    printf("\n");
    // i = 0;
    // while (i < arr.num_b + 3)
    //         printf("%d\n", arr.stack_b[i++]);

    return (0);
}