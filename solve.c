/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:40:52 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/01/21 17:04:36 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve_skyscraper(int **board, int row, int col, int *top, int *bottom, int *left, int *right)
{
	int	height;

	if (row >= SIZE)
		return (1);
	if (col >= SIZE)
		return (solve_skyscraper(board, row + 1, 0, top, bottom, left, right));
	height = 1;
	while (height <= SIZE)
	{
		board[row][col] = height;
		if (is_valid(board, row, col, top, bottom, left, right))
		{
			if (solve_skyscraper(board, row, col + 1, top, bottom, left, right))
				return (1);
		}
		board[row][col] = 0;
		height++;
	}
	return (0);
}
