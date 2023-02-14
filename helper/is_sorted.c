/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:25:56 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/14 19:39:34 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_psw_list *lst)
{
	int	highest;

	highest = INT_MIN;
	while (lst != NULL)
	{
		if (lst->content > highest)
			highest = lst->content;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}
