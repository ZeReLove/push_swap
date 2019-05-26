/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/26 19:39:29 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_algorithm(t_main *arr)
{
    while (!(is_sorted(arr)))
    {
        while (arr->num_a > 3)
            mediana_rotating_for_a(arr);
        while (arr->num_b > 3)
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
        while (i < arr->num_a)
        {
            if (arr->stack_a[i] < arr->stack_a[i + 1])
                i++;
            else
                return (0);
        }
    }
    if (!(arr->stack_a[i]))
        return (1);
    else
        return (0);
}

void mediana_rotating_for_a(t_main *arr)
{
    int i;
    int sum;
    int mediana;

    i = 0;
    sum = 0;
    mediana = 0;
    while (arr->stack_a[i++] > arr->num_a)
            sum += arr->stack_a[i];
    mediana = sum / arr->num_a;
    i = 0;
    if (arr->stack_a[i] >= mediana)
        ft_ra(arr);
    else
        ft_pa(arr);
}

void mediana_rotating_for_b(t_main *arr)
{
    int i;
    int sum;
    int mediana;

    i = 0;
    sum = 0;
    mediana = 0;
    while (arr->stack_b[i++] > arr->num_b)
            sum += arr->stack_b[i];
    mediana = sum / arr->num_b;
    i = 0;
    if (arr->stack_b[i] >= mediana)
        ft_rb(arr);
    else
        ft_pb(arr);
}