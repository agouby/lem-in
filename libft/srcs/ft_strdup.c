/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:02:46 by agouby            #+#    #+#             */
/*   Updated: 2017/08/21 14:56:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!s1)
		return (NULL);
	if (!(s2 = ft_strnew(ft_strlen(s1))))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}

char	*ft_strndup(const char *s1, size_t len)
{
	char	*s2;

	if (!s1)
		return (NULL);
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	s2 = ft_strncpy(s2, s1, len);
	return (s2);
}
