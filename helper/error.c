/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:35:11 by chris             #+#    #+#             */
/*   Updated: 2023/02/15 16:26:23 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(t_psw_list *a_list, t_psw_list *b_list)
{
	if (a_list != NULL)
		psw_lstclear(&a_list);
	if (b_list != NULL)
		psw_lstclear(&b_list);
	write(1, "Error\n", 6);
	exit(0);
}
