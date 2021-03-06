/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:05:31 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/07 14:47:50 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_symbols(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        while ((argv[i][j] >= '0' && argv[i][j] <= '9') || ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')))
            j++;
        if (!argv[i][j])
        {
            i++;
            j = 0;
        }
        else
            break ;
    }
    if (argc == i)
        return (1);
    else
        return (0);
}

int check_duplicates(t_main *arr)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while(i < arr->num_a)
    {
        if (arr->stack_a[i] == arr->stack_a[i + 1])
            return (0);
        else
            i++;
    }
    if (i == arr->num_a)
        return (1);
    else
        return (0);
}

int check_all(t_main *arr, int argc, char **argv)
{
    arr->num_a = argc - 1;
    if (check_symbols(argc, argv) && check_duplicates(arr))
        return (1);
    else
        return (0);
}

// Check functions works correctly