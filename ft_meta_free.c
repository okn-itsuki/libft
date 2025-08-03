/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meta_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:30:29 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/04 04:17:37 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees memory allocated with `meta_malloc` or `ft_realloc`.
 *
 * This function correctly calculates the original allocation address by
 * moving the pointer back to the metadata block (before the user data),
 * and calls `free()` on that location.
 *
 * Important:
 * - Only use this to free memory allocated by `meta_malloc` or `ft_realloc`.
 * - Passing a pointer from standard `malloc()` will cause undefined behavior.
 *
 * @param ptr Pointer previously returned by `meta_malloc` or `ft_realloc`.
 */

void	ft_meta_free(void *ptr)
{
	t_block	*block;

	if (!ptr)
		return ;
	block = ((t_block *)ptr) - 1;
	free(block);
}
