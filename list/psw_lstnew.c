/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/21 17:40:51 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_tmpnew creates a new node. The member variable ’content’
// is // initialized with the value of the parameter ’content’.
// The variable ’next’ is initialized to NULL.
// Return: The new node as t_list.

#include "../push_swap.h"

t_psw_list	*psw_lstnew(int content)
{
	t_psw_list	*tmp;

	tmp = (t_psw_list *) malloc(sizeof(t_psw_list));
	if (tmp == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
		tmp->costs = 0;
		tmp->ra = 0;
		tmp->rra = 0;
		tmp->rb = 0;
		tmp->rrb = 0;
		tmp->rr = 0;
		tmp->rrr = 0;

	return (tmp);
}
