/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:13:08 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:47:57 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	run_rotate(t_psw_list **a_list, t_psw_list **b_list,
	int amount_rotate, void (*f)(t_psw_list **, t_psw_list **))
{
	while (amount_rotate > 0)
	{
		update_lists(*a_list, *b_list);
		f(a_list, b_list);
		amount_rotate--;
	}
}
