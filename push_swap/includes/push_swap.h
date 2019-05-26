/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:44:05 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/26 17:12:26 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int num;
}              t_main;

int check_symbols(int argc, char **argv);
int check_duplicates(t_main *arr);
int check_all(t_main *arr, int argc, char **argv);
int ft_atoi_push_swap(char *str);
void fill_struct(t_main *arr, int argc, char **argv);
void ft_sa(t_main *arr);
void ft_sb(t_main *arr);
void ft_ss(t_main *arr);
void ft_pa(t_main *arr);
void ft_pb(t_main *arr);
void ft_ra(t_main *arr);
void ft_rb(t_main *arr);
void ft_rr(t_main *arr);
void ft_rra(t_main *arr);
void ft_rrb(t_main *arr);
void ft_rrr(t_main *arr);
void num_a_calculation(t_main *arr);
void num_b_calculation(t_main *arr);
int main(int argc, char **argv);
void main_algorithm(t_main *arr);
void sorting_three(t_main *arr);
int is_sorted(t_main *arr);
void mediana_rotating_for_a(t_main *arr);
void mediana_rotating_for_b(t_main *arr);

#endif