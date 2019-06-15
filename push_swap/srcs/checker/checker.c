/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:48:44 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/15 17:08:38 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
    t_checker *arr;
    
    filling_struct(&arr, argc, argv);
    read_instructions();
    if (is_sorted(&arr))
        printf("OK\n");
    else
        printf("KO\n");
}

void filling_struct(t_checker *arr, int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    arr->stack_a = malloc(sizeof(int) * argc);
    arr->stack_b = malloc(sizeof(int) * argc);
    while (i < argc)
    {
        arr->stack_a[j] = ft_atoi_push_swap(argv[i]);
        i++;
        j++;
    }
    arr->num_a = argc - 1;
}

int is_sorted(t_checker *arr)
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