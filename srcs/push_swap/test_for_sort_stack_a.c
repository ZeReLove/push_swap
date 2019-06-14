#include <stdio.h>
#include <stdlib.h>

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
    int *block_count_a;
    int *block_count_b;
    int block_count_a1;
    int n;
}              t_main;

int is_sorted_for_block_a(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->block_count_a1 - 1)
    {
        if (arr->stack_a[i] < arr->stack_a[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->block_count_a1 - 1)
        return (1);
    else
        return (0);
}

void ft_ra(t_main *arr)
{
    int i;
    int first_el;

    i = 0;
    first_el = arr->stack_a[0];
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
    arr->stack_a[i] = first_el;
}

void ft_rra(t_main *arr)
{
    int i;
    int last_el;

    i = arr->num_a - 2;
    last_el = arr->stack_a[arr->num_a - 1];
    while (i != -1)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i--;
    }
    arr->stack_a[0] = last_el;
}

void ft_pa(t_main *arr)
{
    int i;
    int tmp;

    i = arr->num_a - 1;
    arr->num_a++;
    tmp = arr->stack_b[0];
     while (i != -1)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i--;
    }
    arr->stack_a[0] = tmp;
    i = 0;
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i] = arr->stack_b[i + 1];
        i++;
    }
    arr->num_b--;
}

void ft_pb(t_main *arr)
{
    int i;
    int tmp;

    i = arr->num_b - 1;
    arr->num_b++;
    tmp = arr->stack_a[0];
    while (i != -1)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i--;
    }
    arr->stack_b[0] = tmp;
    i = 0;
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
    arr->num_a--;
}

void ft_sa(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_a[0];
    j = arr->stack_a[1];
    tmp = i;
    arr->stack_a[0] = j;
    arr->stack_a[1] = tmp;
}

void ft_sb(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_b[0];
    j = arr->stack_b[1];
    tmp = i;
    arr->stack_b[0] = j;
    arr->stack_b[1] = tmp;
}

void sort_for_block_count(t_main *arr)
{
    int i;

    i = 0;
    if (arr->block_count_a1 == 3 && !(is_sorted_for_block_a(arr)))
    {
        if (arr->stack_a[i] < arr->stack_a[i + 1] && arr->stack_a[i] < arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_pb(arr);
            ft_sb(arr);
            ft_pa(arr);
            ft_sa(arr);
            ft_pa(arr);
        }
        if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] > arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_pb(arr);
            ft_ra(arr);
            ft_sb(arr);
            ft_sa(arr);
            ft_pa(arr);
            ft_pa(arr);
            ft_rra(arr);
        }
        if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] > arr->stack_a[i + 2] && arr->stack_a[i + 1] < arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_ra(arr);
            ft_pb(arr);
            ft_sb(arr);
            ft_pa(arr);
            ft_pa(arr);
            ft_rra(arr);
        }
        if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] < arr->stack_a[i + 2] && arr->stack_a[i + 1] < arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_pb(arr);
            ft_sb(arr);
            ft_pa(arr);
            ft_pa(arr);
        }
        if (arr->stack_a[i] < arr->stack_a[i + 1] && arr->stack_a[i] > arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_ra(arr);
            ft_pb(arr);
            ft_pa(arr);
            ft_pa(arr);
            ft_rra(arr);
        }

    }
    if (arr->block_count_a1 == 2 && !(is_sorted_for_block_a(arr)))
        ft_sa(arr);
}


int main(void)
{
    int i;
    t_main arr;

    arr.stack_a = malloc(sizeof(int) * 5);
    arr.stack_b = malloc(sizeof(int) * 5);
    arr.stack_a[0] = 452;
    arr.stack_a[1] = 48;
    arr.stack_a[2] = 9;
    arr.stack_b[0] = 0;
    arr.stack_b[1] = 0;
    arr.stack_b[2] = 0;
    arr.num_a = 3;
    arr.num_b = 3;
    arr.block_count_a1 = 3;
    sort_for_block_count(&arr);
    i = 0;
    while (i < arr.block_count_a1)
        printf("%d\n", arr.stack_a[i++]);
    printf("\n");
    return (0);
}