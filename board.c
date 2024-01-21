/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyap <eyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:30:35 by eyap              #+#    #+#             */
/*   Updated: 2024/01/21 16:47:37 by eyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**create_board(int size)
{
	int	**board;
	int	i;
	int	j;

	**board = (int **)malloc(size * sizeof(int *));
	if (board == NULL)
	{
		ft_putstr("Memory allocation failed for board.\n");
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		board[i] = (int *)malloc(size * sizeof(int));
		if (board[i] == NULL)
		{
			ft_putstr("Memory allocation failed for board row ");
			ft_putnbr(i);
			ft_putchar('\n');
			j = 0;
			while (j < i)
			{
				free(board[j]);
				j++;
			}
			free(board);
			return (NULL);
		}
		i++;
	}
	return (board);
}

// Function to free the board
void	free_board(int **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

// Function to initialize the board with zeros
void	initialize_board(int **board, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

// Function to print the board
void	print_board(int **board, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putnbr(board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
