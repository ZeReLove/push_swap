/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/04 18:44:41 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_algorithm(t_main *arr)
{
    while (!(is_sorted_for_a(arr)))
    {
        int k;

        k = 0;
        if (arr->num_a > 3)
            mediana_rotating_for_a(arr);
        if (arr->num_b > 3)
            mediana_rotating_for_b(arr);
        if (arr->num_a <= 3 || arr->num_b <= 3)
            sorting_three(arr);
        if ((is_sorted_for_a(arr)) && arr->num_b != 0)
        {
            while (arr->num_b > 0)
            {
                arr->num_a++;
                ft_pa(arr);
            }
            arr->num_b = 0;        
        }
        arr->num = arr->num_a + arr->num_b;         
    }
    
}

void sorting_three(t_main *arr)
{
    if (arr->num_a <= 3)
    {
        while (!(is_sorted_for_a(arr)))
        {
            ft_sa(arr);
            if(!(is_sorted_for_a(arr)))
                ft_rra(arr);
            else
                return ;
        }
    }
    if (arr->num_b <= 3)
    {
        while (!(is_sorted_for_b(arr)))
        {
            ft_sb(arr);
            if (!(is_sorted_for_b(arr)))
                ft_rrb(arr);
            else
                return ;
        }
    }
}

//functions rra ans sa work correctly

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
    mediana_finding(arr);
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


void mediana_rotating_for_b(t_main *arr)
{
    int i;
    int j;
    int n;
    int k;

    i = 0;
    k = 0;
    n = arr->block_count_b;
    mediana_finding(arr);
    arr->block_count_b = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_b[i] >= arr->mediana)
        {
            ft_rb(arr);
            k = 0;
            arr->block_count_b++;
            j++;
        }
        else
        {
            ft_pa(arr);
            k = 0;
            arr->block_count_a++;
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


