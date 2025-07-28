/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okunoitsuki <okunoitsuki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:14:05 by okunoitsuki       #+#    #+#             */
/*   Updated: 2025/07/29 08:23:58 by okunoitsuki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_find_next_line(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    return (i);
}
