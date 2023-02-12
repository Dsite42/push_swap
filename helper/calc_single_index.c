/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_single_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:27:15 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 21:27:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calc_single_index(t_psw_list *a_list, int to_find)
{
	int	i;

	i = 1;
	while (a_list->content != to_find)
	{
		i++;
		a_list = a_list->next;
	}
	return (i);
}
