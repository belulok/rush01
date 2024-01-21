/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyap <eyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:55:36 by eyap              #+#    #+#             */
/*   Updated: 2024/01/21 16:59:55 by eyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	int		top[SIZE];
	int		bottom[SIZE];
	int		left[SIZE];
	int		right[SIZE];
	char	*clues;
	int		**board;

	if (argc != 2)
	{
		ft_putstr("Error: Strictly only include 2 arguments only \n");
		return (1);
	}
	*clues = ft_strdup(argv[1]);
	parse_and_set_clues(clues, top, bottom, left, right);
	free(clues);
	**board = create_board(SIZE);
	initialize_board(board, SIZE);
	if (solve_skyscraper(board, 0, 0, top, bottom, left, right))
		print_board(board, SIZE);
	else
		ft_putstr("Error: Unsolvable \n");
	free_board(board, SIZE);
	return (0);
}
