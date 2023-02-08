/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/08 18:56:00 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstnew creates a new node. The member variable ’content’
// is // initialized with the value of the parameter ’content’.
// The variable ’next’ is initialized to NULL.
// Return: The new node as t_list.

#include "push_swap.h"

t_psw_list	*psw_lstnew(int content)
{
	t_psw_list	*tmp;

	tmp = (t_psw_list *) malloc(sizeof(t_psw_list));
	if (tmp == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
