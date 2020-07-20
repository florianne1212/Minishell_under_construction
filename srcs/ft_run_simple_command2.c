/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_simple_command2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:57:14 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/07/20 17:07:37 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ------not a command-------
** dispays message if the path is not a valid regular file
*/

int		not_a_command(char *command, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(str, 2);
	errno = ENOENT;
	return (1);
}

/*
** -------ft change case instruction--------
** change capital letters in a single command
** no change of letter in absolute or relative paths
*/

void	ft_change_case_instruction(char *instruction)
{
	int	i;

	i = 0;
	if (instruction[0] == '.')
		return ;
	if (instruction[0] == '/')
		return ;
	while (instruction[i])
	{
		if (instruction[i] > 64 && instruction[i] < 91)
			instruction[i] += 32;
		i++;
	}
}