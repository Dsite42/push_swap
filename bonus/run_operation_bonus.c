/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:47:54 by chris             #+#    #+#             */
/*   Updated: 2023/02/20 17:59:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*seed_to_next_operation(char *str)
{
	while (*str != '\n' && *str != '\0')
	{
		str++;
	}
	if (*str == '\n')
		str++;
	return (str);
}

void	run_operation_sx(t_psw_list **a_list, t_psw_list **b_list,
			char **operations_str)
{
	if (ft_strncmp("sa", *operations_str, 2) == 0)
		sa_bonus(*a_list, *b_list);
	else if (ft_strncmp("sb", *operations_str, 2) == 0)
		sb_bonus(*a_list, *b_list);
	else if (ft_strncmp("ss", *operations_str, 2) == 0)
		ss_bonus(*a_list, *b_list);
	else
		error(*a_list, *b_list);
}

void	run_operation_bonus(t_psw_list **a_list, t_psw_list **b_list,
			char **operations_str)
{
	update_lists(*a_list, *b_list);
	if (ft_strncmp("rra", *operations_str, 3) == 0)
		rra_bonus(a_list, b_list);
	else if (ft_strncmp("rrb", *operations_str, 3) == 0)
		rrb_bonus(a_list, b_list);
	else if (ft_strncmp("rrr", *operations_str, 3) == 0)
		rrr_bonus(a_list, b_list);
	else if (ft_strncmp("pa", *operations_str, 2) == 0)
		pa_bonus(a_list, b_list);
	else if (ft_strncmp("pb", *operations_str, 2) == 0)
		pb_bonus(a_list, b_list);
	else if (ft_strncmp("ra", *operations_str, 2) == 0)
		ra_bonus(a_list, b_list);
	else if (ft_strncmp("rb", *operations_str, 2) == 0)
		rb_bonus(a_list, b_list);
	else if (ft_strncmp("rr", *operations_str, 2) == 0)
		rr_bonus(a_list, b_list);
	else
		run_operation_sx(a_list, b_list, operations_str);
	*operations_str = seed_to_next_operation(*operations_str);
}
