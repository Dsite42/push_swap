/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:21:34 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstadd_back adds the node ’new’ at the end of the list.
// Return: None.

#include "../push_swap.h"

void	psw_lstadd_back(t_psw_list **lst, t_psw_list *new)
{
	if (*lst == NULL && new != NULL)
		*lst = new;
	else
	{
		psw_lstlast(*lst)->next = new;
		new->next = NULL;
	}
}
