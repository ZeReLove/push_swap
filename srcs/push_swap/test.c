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
    int block_count_a;
    int block_count_b;
}              t_main;

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

// void ft_pb(t_main *arr)
// {
//     int i;
//     int tmp;

//     i = 0;
//     //arr->stack_b = malloc(sizeof(int) * 3);
//     tmp = arr->stack_a[0];
//     while (i + 1 < arr->num_b)
//     {
//         arr->stack_b[i + 1] = arr->stack_b[i];
//         i++;
//     }
//     arr->stack_b[0] = tmp;
//     i = 0;
//     arr->num_a--;
//     while (i < arr->num_a)
//     {
//         arr->stack_a[i] = arr->stack_a[i + 1];
//         i++;
//     }
//     arr->stack_a[i] = '\0';
// }

// void mediana_rotating_for_a(t_main *arr)
// {
//     int i;
//     int n;
//     int sum;

//     i = 0;
//     sum = 0;
//     n = arr->num_a;
//     //arr->num_a = 0;
//     if (!arr->block_count_a)
//         arr->block_count_a = 0; 
//     while(arr->block_count_a < n)
//     {
//         if (arr->stack_a[i] >= arr->mediana)
//         {
//             ft_ra(arr);
//             arr->num_a++;
//             arr->num_b--;
//         }
//         else
//         {
//             ft_pb(arr);
//             arr->block_count_b++;
//             arr->num_b++;
//             arr->num_a--;
//         }
//         arr->block_count_a++;
//         i++;
//     }
// }

//functions rra ans sa work correctly


// void ft_pb(t_main *arr)
// {
//     int i;
//     int tmp;

//     i = 0;
//     arr->num_a2 = arr->num_a - 1;
//     arr->num_b2 = arr->num_b + 1;
//     arr->stack_a2 = malloc(sizeof(int) * arr->num_a2);
//     arr->stack_b2 = malloc(sizeof(int) * arr->num_b2);
//     copying_arrays(arr);
//     free(arr->stack_a);
//     free(arr->stack_b);
//     tmp = arr->stack_a[0];
//     while (i + 1 < arr->num_b)
//     {
//         arr->stack_b[i + 1] = arr->stack_b[i];
//         i++;
//     }
//     arr->stack_b[0] = tmp;
//     i = 0;
//     while (i + 1 < arr->num_a)
//     {
//         arr->stack_a[i] = arr->stack_a[i + 1];
//         i++;
//     }
// }

// void ft_pb(t_main *arr)
// {
//     int i;
//     int tmp;

//     i = 0;
//     arr->num_a2 = arr->num_a - 1;
//     arr->num_b2 = arr->num_b + 1;
//     arr->stack_a2 = malloc(sizeof(int) * arr->num_a2);
//     arr->stack_b2 = malloc(sizeof(int) * arr->num_b2);
//     copying_arrays_to_stacks2(arr);
//     free(arr->stack_a);
//     free(arr->stack_b);
//     arr->stack_a = malloc(sizeof(int) * arr->num_a2);
//     arr->stack_b = malloc(sizeof(int) * arr->num_b2);
//     copying_arrays_to_stacks(arr);
//     free(arr->stack_a2);
//     free(arr->stack_b2);
//     tmp = arr->stack_a[0];
//     while (i + 1 < arr->num_b)
//     {
//         arr->stack_b[i + 1] = arr->stack_b[i];
//         i++;
//     }
//     arr->stack_b[0] = tmp;
//     i = 0;
//     while (i + 1 < arr->num_a)
//     {
//         arr->stack_a[i] = arr->stack_a[i + 1];
//         i++;
//     }
// }

// void ft_pb(t_main *arr)
// {
//     int i;
//     int j;
//     int tmp;
//     //int *temp;

//     i = 0;
//     j = 0;
//     //temp = arr->stack_a;
//     //arr->stack_a = malloc(sizeof(int) * arr->num_a - 1);
//     // while (i < arr->num_a - 1)
//     // {
//     //     arr->stack_a[i] = temp[j];
//     //     i++;
//     //     j++;
//     // }
//     // free(temp);
//     // copying_arrays_to_stacks2(arr);
//     // free(arr->stack_a);
//     // free(arr->stack_b);
//     // copying_arrays_to_stacks(arr);
//     // free(arr->stack_a2);
//     // free(arr->stack_b2);
//     //i = 0;
    
//     arr->num_b++;
//     tmp = arr->stack_a[0];
//     while (i + 1 < arr->num_b)
//     {
//         arr->stack_b[i + 1] = arr->stack_b[i];
//         i++;
//     }
//     arr->stack_b[0] = tmp;
//     i = 0;
//     while (i + 1 < arr->num_a)
//     {
//         arr->stack_a[i] = arr->stack_a[i + 1];
//         i++;
//     }
//     arr->num_a--;
// }


// void mediana_rotating_for_a(t_main *arr)
// {
//     int i;
//     int j;
//     int n;
//     int k;

//     i = 0;
//     k = 0;
//     n = arr->num_a;
//     if (!arr->block_count_a)
//         arr->block_count_a = 0;
//     j = i;
//     while (j < n)
//     {
//         if (arr->stack_a[i] >= arr->mediana)
//         {
//             ft_ra(arr);
//             printf("RA\n");
//             printf ("stack_a\n");
//             while(k < arr->num_a)
//                 printf("%d\n", arr->stack_a[k++]);
//             printf("\n");
//             k = 0;
//             printf("RA\n");
//             printf ("stack_b\n");
//             while(k < arr->num_b)
//                 printf("%d\n", arr->stack_b[k++]);
//             printf("\n");
//             arr->block_count_a++;
//             j++;
//         }
//         else
//         {
//             ft_pb(arr);
//             printf("PB\n");
//             printf ("stack_a\n");
//             while (k < arr->num_a)
//                 printf("%d\n", arr->stack_a[k++]);
//             printf("\n");
//             k = 0;
//             printf("PB\n");
//             printf ("stack_b\n");
//             while(k < arr->num_b)
//                 printf("%d\n", arr->stack_b[k++]);
//             printf("\n");
//             arr->block_count_b++;
//             //arr->num_a--;
//             //arr->num_b++;
//             j++;
//         }
//     }
// }

// void ft_pb(t_main *arr)
// {
//     int i;
//     int tmp;

//     i = arr->num_b - 1;
//     arr->num_b++;
//     tmp = arr->stack_a[0];
//     while (i != -1)
//     {
//         arr->stack_b[i + 1] = arr->stack_b[i];
//         i--;
//     }
//     arr->stack_b[0] = tmp;
//     i = 0;
//     while (i + 1 < arr->num_a)
//     {
//         arr->stack_a[i] = arr->stack_a[i + 1];
//         i++;
//     }
//     arr->num_a--;
// }

// void mediana_rotating_for_a(t_main *arr)
// {
//     int i;
//     int j;
//     int n;
//     int k;

//     i = 0;
//     k = 0;
//     if (!(arr->block_count_a))
//         arr->block_count_a = arr->num_a;
//     n = arr->block_count_a;
//     arr->block_count_a = 0;
//     j = i;
//     while (j < n)
//     {
//         if (arr->stack_a[i] >= arr->mediana)
//         {
//             ft_ra(arr);
//             k = 0;
//             arr->block_count_a++;
//             j++;
//         }
//         else
//         {
//             ft_pb(arr);
//             k = 0;
//             arr->block_count_b++;
//             //arr->num_a--;
//             //arr->num_b++;
//             j++;
//         }
//     }
// }

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

void ft_rrb(t_main *arr)
{
    int i;
    int last_el;

    i = 0;
    if (arr->num_b != 0) // ???
        i = arr->num_b - 2;
    last_el = arr->stack_b[arr->num_b - 1];
    while (i != -1)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i--;
    }
    arr->stack_b[0] = last_el;
}

int is_sorted_for_a(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->num_a - 1)
    {
        if (arr->stack_a[i] < arr->stack_a[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->num_a - 1)
        return (1);
    else
        return (0);
}

int is_sorted_for_b(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->num_b - 1)
    {
        if (arr->stack_b[i] < arr->stack_b[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->num_b - 1)
        return (1);
    else
        return (0);
}

void sorting_three(t_main *arr)
{
    int i;

    i = 0;
    if (arr->num_a <= 3)
    {
        while (!(is_sorted_for_a(arr)))
        {
            if (arr->stack_a[i] > arr->stack_a[i + 1])
                ft_sa(arr);
            if (!(is_sorted_for_a(arr)))
                ft_rra(arr);
            else
                return ;
        }
    }
    i = 0;
    if (arr->num_b <= 3)
    {
        while (!(is_sorted_for_b(arr)))
        {
            if (arr->stack_b[i] > arr->stack_b[i + 1])
            ft_sb(arr);
            if (!(is_sorted_for_b(arr)))
                ft_rrb(arr);
            else
                return ;
        }
    }
}


// void ft_sa(t_main *arr)
// {
//     int i;
//     int j;
//     int tmp;
    
//     i = arr->stack_a[0];
//     j = arr->stack_a[1];
//     tmp = i;
//     arr->stack_a[0] = j;
//     arr->stack_a[1] = tmp;
// }

// DOESN'T WORT AT ALL (SORTINTG RANDOMLY)

int main(void)
{
    int i;
    //int *array;
    //int array_len;
    t_main arr;

    arr.mediana = 9;
    arr.stack_b = malloc(sizeof(int) * 5);
    arr.stack_a = malloc(sizeof(int) * 5);
    arr.stack_a[0] = 48;
    arr.stack_a[1] = 65;
    arr.stack_a[2] = 3;
    // arr.stack_a[3] = 109;
    // arr.stack_a[4] = -120;
    // arr.stack_a[5] = 7;
    // arr.stack_a[6] = 9;
    // arr.stack_b[0] = 0;
    // arr.stack_b[1] = 0;
    // arr.stack_b[2] = 0;
    // arr.stack_b[3] = 0;
    // arr.stack_b[4] = 0;
    // arr.stack_b[5] = 0;
    // arr.stack_b[6] = 0;
    //array_len = 4;
    arr.num_a = 3;
    arr.num_b = 0;
    //mediana_rotating_for_a(&arr);
    sorting_three(&arr);
    //ft_pb(&arr);
    //ft_sa(&arr);
    i = 0;
    printf("-------------------\n");
    while (i < arr.num_a)
        printf("%d\n", arr.stack_a[i++]);
    printf("\n");
    i = 0;
    while (i < arr.num_b)
            printf("%d\n", arr.stack_b[i++]);

    return (0);
}