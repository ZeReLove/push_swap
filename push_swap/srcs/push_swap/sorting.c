/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/07 16:26:42 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_algorithm(t_main *arr)
{
    int k;
    int i;
    
    while (!(is_sorted_for_a(arr)))
    {
        while (arr->num_a > 3 && arr->block_count_a == 0)
            mediana_rotating_for_a(arr);
        if (arr->num_a <= 3 || arr->num_b <= 3)
            sorting_three(arr);
        if (arr->block_count_a <= 3 || arr->block_count_b <=3)
            sort_for_block_count(arr);
        while (arr->num_b > 3 && arr->block_count_b == 0)
            mediana_rotating_for_b(arr);
        if (arr->num_a <= 3 || arr->num_b <= 3)
            sorting_three(arr);
        if ((is_sorted_for_a(arr)) && arr->num_b != 0)
        {
            i = 0;
            while (i++ < arr->num - arr->num_a)
            {
                ft_rrb(arr);
                ft_pa(arr);
            }
            arr->num_b = 0;        
        }  
    }
    k = 0;
    while (k < arr->num_a)
        printf("%d\n",  arr->stack_a[k++]);
    k = 0;
    while (k < arr->num_b)
        printf("%d\n",  arr->stack_b[k++]);
}

// void main_algorithm(t_main *arr)
// {
//     int k;
//     int i;
    
//     printf("------------------------------------------\n");
//     while (!(is_sorted_for_a(arr)))
//     {
//         while (arr->num_a > 3)
//             mediana_rotating_for_a(arr);
//         printf ("mediana_rotating_for_a\n");
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         printf("sorting_three\n");
//         k = 0;
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         while (arr->num_b > 3)
//             mediana_rotating_for_b(arr);
//         printf ("mediana_rotating_for_b\n");
//         printf ("stack_a\n");
//         k = 0;
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         printf("sorting_three\n");
//         k = 0;
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if ((is_sorted_for_a(arr)) && arr->num_b != 0)
//         {
//             i = 0;
//             while (i++ < arr->num_b + 2)
//             {
//                 ft_rrb(arr);
//                 ft_pa(arr);
//             }
//             arr->num_b = 0;        
//         }
//         arr->num = arr->num_a + arr->num_b;         
//     }
//     k = 0;
//     while (k < arr->num_a)
//         printf("%d\n",  arr->stack_a[k++]);
//     k = 0;
//     while (k < arr->num_b)
//         printf("%d\n",  arr->stack_b[k++]);
// }




void sorting_three(t_main *arr)
{
    int i;

    i = 0;
    if (arr->num_a <= 3 && arr->num_a > 1)
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
    if (arr->num_b <= 3 && arr->num_b > 1)
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
            if (arr->block_a[i] < arr->block_a[i + 1])
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
    l = 0;
    if (arr->block_count_b <= 3 && arr->block_count_b > 1)
    {
        while (!(is_sorted_for_block_b(arr)))
        {
            if (arr->block_b[i] < arr->block_b[i + 1])
                ft_sb_for_block_b(arr);
            if (!(is_sorted_for_block_b(arr)))
                ft_rrb_for_block_b(arr);
            else
                return ;
        }
        while (j++ < arr->block_count_b)
            arr->stack_b[k++] = arr->block_b[l++];
    }
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

//functions rra ans sa work correctly

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
    mediana_finding_for_a(arr);
    arr->block_count_a = 0;
    arr->block_count_b = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_a[i] >= arr->mediana)
        {
            ft_ra(arr);
            k = 0;
            j++;
            //arr->block_count_a++;
        }
        else
        {
            
            ft_pb(arr);
            k = 0;
            arr->block_count_b++;
            arr->block_b[k++] = arr->stack_b[i];
            //arr->num_a--;
            //arr->num_b++;
            j++;
        }
    }
}


void mediana_rotating_for_b(t_main *arr)
{
    int i;
    int j;
    int n;
    int k;

    i = 0;
    k = 0;
    n = arr->block_count_b;
    mediana_finding_for_b(arr);
    arr->block_count_b = 0;
    arr->block_count_a = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_b[i] <= arr->mediana)
        {
            ft_rb(arr);
            k = 0;
            j++;
            //arr->block_count_b++;
        }
        else
        {
            
            ft_pa(arr);
            k = 0;
            arr->block_count_a++;
            arr->block_a[k++] = arr->stack_a[i];
            //arr->num_a--;
            //arr->num_b++;
            j++;
        }
    }
}

// DOESN'T WORK CORRECTLY

// void mediana_rotating_for_b(t_main *arr)
// {
//     int i;
//     int sum;

//     i = 0;
//     sum = 0;
//     mediana_finding(arr);
//     while(arr->block_count_b < arr->num_b)
//     {
//         if (arr->stack_b[i++] >= arr->mediana)
//         {
//             ft_rb(arr);
//             arr->num_b++;            
//         }
//         else
//         {
//             ft_pa(arr);
//             arr->block_count_a++;
//             arr->num_a++;            
//         }
//     }
// }

// DOESN'T WORK CORRECTLY




// Changed mediana finding in mediana_rotating_for_b
// Saved mediana finding in mediana_rotating_for_a
// Needed to test what variant is correct


// void main_algorithm(t_main *arr)
// {
//     int k;
//     int i;
    
//     if (!(is_sorted_for_a(arr)))
//     {
//         if (arr->num_a > 3)
//             mediana_rotating_for_a(arr);
//         k = 0;
//         printf ("mediana_rotating_for_a\n");
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if (arr->num_b > 3)
//             mediana_rotating_for_b(arr);
//         printf ("mediana_rotating_for_b\n");
//          printf ("stack_a\n");
//         k = 0;
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//          printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         printf("sorting_three\n");
//         k = 0;
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if ((is_sorted_for_a(arr)) && arr->num_b != 0)
//         {
//             i = 0;
//             while (i++ < arr->num_b)
//             {
//                 ft_rrb(arr);
//                 printf("Making rrb\n");
//                 printf ("stack_a\n");
//                 while (k < arr->num_a)
//                     printf("%d\n",  arr->stack_a[k++]);
//                 printf("-----\n");
//                 k = 0;
//                 printf ("stack_b\n");
//                 while (k < arr->num_b)
//                     printf("%d\n",  arr->stack_b[k++]);
//                 printf("-----------\n");
//                 arr->num_a++;
//                 ft_pa(arr);
//                 printf("Making pa\n");
//                 printf ("stack_a\n");
//                 while (k < arr->num_a)
//                     printf("%d\n",  arr->stack_a[k++]);
//                 printf("-----\n");
//                 k = 0;
//                 printf ("stack_b\n");
//                 while (k < arr->num_b)
//                     printf("%d\n",  arr->stack_b[k++]);
//                 printf("-----------\n");
//                 k = 0;
//                 printf("Making adding\n");
//                 printf ("stack_a\n");
//                 while (k < arr->num_a)
//                     printf("%d\n",  arr->stack_a[k++]);
//                 printf("-----\n");
//                 k = 0;
//                 printf ("stack_b\n");
//                 while (k < arr->num_b)
//                     printf("%d\n",  arr->stack_b[k++]);
//                 printf("-----------\n");
//                 arr->num_b++;
//             }
//             arr->num_b = 0;        
//         }
//         arr->num = arr->num_a + arr->num_b;         
//     }
//     k = 0;
//     while (k < arr->num_a)
//         printf("%d\n",  arr->stack_a[k++]);
//     k = 0;
//     while (k < arr->num_b)
//         printf("%d\n",  arr->stack_b[k++]);
// }

// void mediana_rotating_for_a(t_main *arr)
// {
//     int i;

//     i = 0;
//     mediana_finding(arr);
//     if (!arr->block_count_a)
//         arr->block_count_a = 0; 
//     while (i < arr->num_a)
//     {
//         if (arr->stack_a[i] >= arr->mediana)
//         {
//             ft_ra(arr);
//             arr->block_count_a++;
//         }
//         else
//         {
//             ft_pb(arr);
//             arr->block_count_b++;
//             arr->num_a--;
//             arr->num_b++;
//         }
//         i++;
//     }
// }