/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyap <eyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:15:25 by eyap              #+#    #+#             */
/*   Updated: 2024/01/21 17:19:40 by eyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid(int **board, int row, int col, int *top, int *bottom, int *left, int *right)
{
	int	i;
	int	col_values[SIZE];

	i = 0;
	while (i < col)
	{
		if (board[row][i] == board[row][col] && board[row][col] != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (board[i][col] == board[row][col] && board[row][col] != 0)
			return (0);
		i++;
	}
	if (col == SIZE - 1)
	{
		if (count_visible_from_left(board[row]) != left[row] || count_visible_from_right(board[row]) != right[row])
			return (0);
	}
	if (row == SIZE - 1)
	{
		i = 0;
		while (i < SIZE)
		{
			col_values[i] = board[i][col];
			i++;
		}
		if (count_visible_from_top(board, col) != top[col] || count_visible_from_bottom(board, col) != bottom[col])
			return (0);
	}
	return (1);
}

int	count_visible_from_left(int *row)
{
	int	visible_count;
	int	max_height;
	int	i;

	visible_count = 0;
	max_height = 0;
	i = 0;
	while (i < SIZE)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int	count_visible_from_top(int **board, int col)
{
	int	visible_count;
	int	max_height;
	int	i;

	visible_count = 0;
	max_height = 0;
	i = 0;
	while (i < SIZE)
	{
		if (board[i][col] > max_height)
		{
			max_height = board[i][col];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int	count_visible_from_bottom(int **board, int col)
{
	int	visible_count;
	int	max_height;
	int	i;

	visible_count = 0;
	max_height = 0;
	i = SIZE - 1;
	while (i >= 0)
	{
		if (board[i][col] > max_height)
		{
			max_height = board[i][col];
			visible_count++;
		}
		i--;
	}
	return (visible_count);
}

int	count_visible_from_right(int *row)
{
	int	visible_count;
	int	max_height;
	int	i;

	visible_count = 0;
	max_height = 0;
	i = SIZE - 1;
	while (i >= 0)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			visible_count++;
		}
		i--;
	}
	return (visible_count);
}
