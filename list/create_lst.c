/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:18:57 by chris             #+#    #+#             */
/*   Updated: 2023/02/13 15:17:01 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (i != 0 || (i == 0 && str[i] != '-')
				|| (i == 0 && str[i] == '-' && str[i + 1] == '\0'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_integer_range(char *str)
{
	if ((ft_strlen(str) == 10 && ft_strncmp(str, "2147483647", 10) > 0)
		|| (ft_strlen(str) == 11
			&& ft_strncmp(str, "-2147483648", 11) > 0))
		return (0);
	return (1);
}

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

int	is_valid_input_argument(t_psw_list *a_list, char *argv)
{
	if (is_valid_digits(argv) == 0)
		return (0);
	if (is_integer_range(argv) == 0)
		return (0);
	if (is_duplicate(a_list, ft_atoi(argv)) == 1)
		return (0);
	return (1);
}

t_psw_list	*create_lst(char **argv)
{
	t_psw_list	*list_start;

	while (*argv != NULL)
	{
		if (list_start == NULL)
		{
			list_start = psw_lstnew(ft_atoi(*argv));
			argv++;
		}
		if (is_valid_input_argument(list_start, *argv) == 0)
			error(list_start);
		psw_lstadd_back(&list_start, psw_lstnew(ft_atoi(*argv)));
		argv++;
	}
	return (list_start);
}
