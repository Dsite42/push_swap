/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_strjoin_free_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:02:07 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:08 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strjoin create a new string by concatenate two strings.
// Return: Pointer to new string or NULL if memory allocation fails.

#include "push_swap_bonus.h"

void	free_strs(char *str)
{
	if (str != NULL)
		free(str);
}

char	*psw_strjoin_free(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	joined = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	free_strs((char *)s1);
	free_strs((char *)s2);
	return (joined);
}
