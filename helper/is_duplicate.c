/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:02:53 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/14 18:03:58 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_duplicate(t_psw_list *a_list, int nbr_to_check)
{
	while (a_list != NULL)
	{
		if (a_list->content == nbr_to_check)
			return (1);
		a_list = a_list->next;
	}
	return (0);
}
