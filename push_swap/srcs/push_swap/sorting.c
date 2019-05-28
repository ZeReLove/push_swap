/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/28 18:26:36 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_algorithm(t_main *arr)
{
    while (!(is_sorted(arr)))
    {
        if (arr->num_a > 3)
            mediana_rotating_for_a(arr);
        if (arr->num_b > 3)
            mediana_rotating_for_b(arr);
        if (arr->num_a <= 3 || arr->num_b <= 3)
            sorting_three(arr);          
    }
}

void sorting_three(t_main *arr)
{
    if (arr->num_a <= 3)
    {
        while (!(is_sorted(arr)))
        {
            ft_sa(arr);
            while (!(is_sorted(arr)))
                ft_rra(arr);
        }
    }
    if (arr->num_b <= 3)
    {
        while (!(is_sorted(arr)))
        {
            ft_sb(arr);
            ft_rrb(arr);
        }
    }
}

int is_sorted(t_main *arr)
{
    int i;

    i = 0;
    if (arr->num_b == 0)
    {
        while (i < arr->num_a - 1)
        {
            if (arr->stack_a[i] < arr->stack_a[i + 1])
                i++;
            else
                return (0);
        }
    }
    if (i == arr->num_a - 1)
        return (1);
    else
        return (0);
}

void mediana_rotating_for_a(t_main *arr)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    arr->num_a = 0;
    mediana_finding(arr);
    if (!arr->block_count_a)
        arr->block_count_a = 0; 
    while(arr->block_count_a < arr->num_a)
    {
        if (arr->stack_a[i++] >= arr->mediana)
        {
            ft_ra(arr);
            arr->num_a++;
        }
        else
        {
            ft_pb(arr);
            arr->block_count_b++;
            arr->num_b++;
        }
        arr->block_count_a++;
    }
}

void mediana_rotating_for_b(t_main *arr)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    mediana_finding(arr);
    while(arr->block_count_b < arr->num_b)
    {
        if (arr->stack_b[i++] >= arr->mediana)
        {
            ft_rb(arr);
            arr->num_b++;            
        }
        else
        {
            ft_pa(arr);
            arr->block_count_a++;
            arr->num_a++;            
        }
    }
}



// Changed mediana finding in mediana_rotating_for_b
// Saved mediana finding in mediana_rotating_for_a
// Needed to test what variant is correct