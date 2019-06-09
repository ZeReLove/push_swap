#include <stdlib.h>
#include <stdio.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int *block_a;
    int *block_b;
    int num;
    int *array;
    int mediana;
    int block_count_a;
    int block_count_b;
}              t_main;

int is_sorted_for_block_a(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->block_count_a - 1)
    {
        if (arr->block_a[i] < arr->block_a[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->block_count_a - 1)
        return (1);
    else
        return (0);
}

int is_sorted_for_block_b(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->block_count_b - 1)
    {
        if (arr->block_b[i] < arr->block_b[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->block_count_b - 1)
        return (1);
    else
        return (0);
}

void ft_sa_for_block_a(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->block_a[0];
    j = arr->block_a[1];
    tmp = i;
    arr->block_a[0] = j;
    arr->block_a[1] = tmp;
}

void ft_sb_for_block_b(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->block_b[0];
    j = arr->block_b[1];
    tmp = i;
    arr->block_b[0] = j;
    arr->block_b[1] = tmp;
}

void ft_rra_for_block_a(t_main *arr)
{
    int i;
    int last_el;

    i = arr->block_count_a - 2;
    last_el = arr->block_a[arr->block_count_a - 1];
    while (i != -1)
    {
        arr->block_a[i + 1] = arr->block_a[i];
        i--;
    }
    arr->block_a[0] = last_el;
}

void ft_rrb_for_block_b(t_main *arr)
{
    int i;
    int last_el;

    i = 0;
    if (arr->block_count_b != 0) // ???
        i = arr->block_count_b - 2;
    last_el = arr->block_b[arr->block_count_b - 1];
    while (i != -1)
    {
        arr->block_b[i + 1] = arr->block_b[i];
        i--;
    }
    arr->block_b[0] = last_el;
}

void sort_for_block_count(t_main *arr)
{
    int i;
    int j;
    int k;
    int l;

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    if (arr->block_count_a <= 3 && arr->block_count_a > 1)
    {
        while (!(is_sorted_for_block_a(arr)))
        {
            if (arr->block_a[i] > arr->block_a[i + 1])
                ft_sa_for_block_a(arr);
            if (!(is_sorted_for_block_a(arr)))
                ft_rra_for_block_a(arr);
            else
                return ;
        }
        while (j++ < arr->block_count_a)
            arr->stack_a[k++] = arr->block_a[l++];
    }
    i = 0;
    j = 0;
    k = 0;
    l = arr->block_count_b - 1;
    if (arr->block_count_b <= 3 && arr->block_count_b > 1)
    {
        while (!(is_sorted_for_block_b(arr)))
        {
            if (arr->block_b[i] > arr->block_b[i + 1])
                ft_sb_for_block_b(arr);
            if (!(is_sorted_for_block_b(arr)))
                ft_rrb_for_block_b(arr);
            else
                return ;
        }
        while (j++ < arr->block_count_b)
            arr->stack_b[k++] = arr->block_b[l--];
    }
}

int main(void)
{
    int i;
    //int *array;
    //int array_len;
    t_main arr;

    // arr.mediana = 48;
    // arr.stack_b = malloc(sizeof(int) * 5);
    // arr.stack_a = malloc(sizeof(int) * 5);
    // arr.stack_a[0] = 452;
    // arr.stack_a[1] = 9;
    // arr.stack_a[2] = 48;
    // arr.stack_a[3] = 12;
    // arr.stack_a[4] = 234;
    // arr.stack_b[0] = 0;
    // arr.stack_b[1] = 0;
    // arr.stack_b[2] = 0;
    // arr.stack_b[3] = 0;
    // arr.stack_b[4] = 0;
    arr.block_a = malloc(sizeof(int) * 5);
    arr.block_b = malloc(sizeof(int) * 5);
    //array_len = 4;
    arr.block_count_a = 5;
    arr.block_count_b = 5;
    arr.block_a[0] = -2;
    arr.block_a[1] = 1;
    arr.block_a[2] = 3;
    arr.block_a[3] = 5;
    arr.block_a[4] = 9;
    //mediana_rotating_for_a(&arr);
    //ft_pb(&arr);
    //ft_sa(&arr);
    i = 0;
    sort_for_block_count(&arr);
    //printf("-------------------\n");
    while (i < arr.block_count_a)
        printf("%d\n", arr.block_a[i++]);
    printf("\n");
    // i = 0;
    // while (i < arr.num_b + 3)
    //         printf("%d\n", arr.stack_b[i++]);

    return (0);
}