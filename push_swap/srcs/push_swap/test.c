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

void ft_pb(t_main *arr)
{
    int i;
    int j;
    int tmp;
    //int *temp;

    i = 0;
    j = 0;
    //temp = arr->stack_a;
    //arr->stack_a = malloc(sizeof(int) * arr->num_a - 1);
    // while (i < arr->num_a - 1)
    // {
    //     arr->stack_a[i] = temp[j];
    //     i++;
    //     j++;
    // }
    // free(temp);
    // copying_arrays_to_stacks2(arr);
    // free(arr->stack_a);
    // free(arr->stack_b);
    // copying_arrays_to_stacks(arr);
    // free(arr->stack_a2);
    // free(arr->stack_b2);
    //i = 0;
    
    arr->num_b++;
    tmp = arr->stack_a[0];
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i++;
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

void mediana_rotating_for_a(t_main *arr)
{
    int i;
    int j;
    int n;
    int k;

    i = 0;
    k = 0;
    if (!(arr->block_count_a))
        arr->block_count_a = arr->num_a;
    n = arr->block_count_a;
    //mediana_finding(arr);
    arr->block_count_a = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_a[i] >= arr->mediana)
        {
            ft_ra(arr);
            k = 0;
            arr->block_count_a++;
            j++;
        }
        else
        {
            ft_pb(arr);
            k = 0;
            arr->block_count_b++;
            //arr->num_a--;
            //arr->num_b++;
            j++;
        }
    }
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

// DOESN'T WORT AT ALL (SORTINTG RANDOMLY)

int main(void)
{
    int i;
    //int *array;
    //int array_len;
    t_main arr;

    arr.mediana = 48;
    arr.stack_b = malloc(sizeof(int) * 5);
    arr.stack_a = malloc(sizeof(int) * 5);
    arr.stack_a[0] = 452;
    arr.stack_a[1] = 9;
    arr.stack_a[2] = 48;
    arr.stack_a[3] = 12;
    arr.stack_a[4] = 234;
    arr.stack_b[0] = 0;
    arr.stack_b[1] = 0;
    arr.stack_b[2] = 0;
    arr.stack_b[3] = 0;
    arr.stack_b[4] = 0;
    //array_len = 4;
    arr.num_a = 5;
    arr.num_b = 0;
    //mediana_rotating_for_a(&arr);
    //ft_pb(&arr);
    ft_sa(&arr);
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