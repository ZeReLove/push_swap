/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:03:01 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/26 17:08:56 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_main arr;
    if (argc > 1)
    {
        if (check_all(&arr, argc, argv))
        {
            fill_struct(&arr, argc, argv);
            main_algorithm(&arr);
            free(arr.stack_a);
            free(arr.stack_b);
        }   
    }
    return (0);
}