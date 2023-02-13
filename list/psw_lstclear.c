/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:37:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/13 11:31:17 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstclear deletes and frees the given node and every
// successor of that node, using the function ’del’ and free(3). Finally, the
// pointer to the list must be set to NULL.
// Return: None.

#include "../push_swap.h"

void	psw_lstclear(t_psw_list **lst)
{
	t_psw_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		psw_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
