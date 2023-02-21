/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_from_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:18:57 by chris             #+#    #+#             */
/*   Updated: 2023/02/21 15:04:41 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	str_number_len(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0' && ((*str >= '0' && *str <= '9') || *str == '-'))
	{
		len++;
		str++;
	}
	return (len);
}

static int	is_integer_range(char *str)
{
	int	number_len;

	number_len = str_number_len(str);
	if ((number_len == 10 && ft_strncmp(str, "2147483647", number_len) > 0)
		|| (number_len == 11
			&& ft_strncmp(str, "-2147483648", number_len) > 0))
		return (0);
	return (1);
}

static int	is_valid_input_argument(t_psw_list *a_list, char *argv)
{
	if (is_valid_digits(argv) == 0)
		return (0);
	if (is_integer_range(argv) == 0)
		return (0);
	if (psw_lstsize(a_list) > 1 && is_duplicate(a_list, ft_atoi(argv)) == 1)
		return (0);
	return (1);
}

t_psw_list	*create_lst_from_str(char *str)
{
	t_psw_list	*list_start;

	list_start = NULL;
	if ((*str < '0' || *str > '9') && *str != '-')
		error(list_start, NULL);
	while (*str)
	{
		if (list_start == NULL)
		{
			list_start = psw_lstnew(ft_atoi(str));
			if (is_valid_input_argument(list_start, str) == 0)
				error(list_start, NULL);
			seed_to_next_nbr(&str);
			if (*str == '\0')
				break ;
		}
		if (is_valid_input_argument(list_start, str) == 0)
			error(list_start, NULL);
		psw_lstadd_back(&list_start, psw_lstnew(ft_atoi(str)));
		seed_to_next_nbr(&str);
	}
	if (*(str - 1) < '0' || *(str - 1) > '9')
		error(list_start, NULL);
	return (list_start);
}
