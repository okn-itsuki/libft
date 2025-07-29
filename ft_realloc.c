/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:04:57 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/29 17:08:59 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reallocates memory previously allocated by meta_malloc.
 *
 * This function reallocates memory blocks that were originally allocated
 * using `meta_malloc`, which stores metadata (such as size) immediately
 * before the returned pointer.
 *
 *  Important:
 * - You must use `meta_free()` to deallocate memory returned by this function.
 * - Do NOT pass pointers allocated by standard `malloc()` to this function.
 *   Doing so results in undefined behavior.
 * - If `ptr == NULL`, this behaves like `meta_malloc(size)`.
 * - If `size == 0`, the memory is freed and `NULL` is returned.
 *
 * @param ptr  Pointer to the memory block allocated with `meta_malloc`.
 * @param size New size in bytes for the reallocated memory.
 * @return A pointer to the newly allocated memory, or NULL on failure.
 */

static void	*meta_malloc(size_t size)
{
	t_block	*block;

	block = malloc(sizeof(t_block) + size);
	block->size = size;
	return ((void *)(block + 1));
}

char	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;
	t_block	*old_block;

	if (ptr == NULL)
		return (meta_malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	old_block = ((t_block *)ptr) - 1;
	old_size = old_block->size;
	new_ptr = meta_malloc(size);
	if (!new_ptr)
		return (NULL);
	if (old_size < size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
