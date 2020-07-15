/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:12:11 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/07/14 23:39:12 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** comme pwd de bash
*/

int	builtin_pwd(t_shell *glob, int fd, char **arg)
{
	char	*pwd;

	(void)arg;
	(void)glob;
	if (!(pwd = getcwd(NULL, 1)))
		return (1);
	ft_putendl_fd(pwd, fd);
	free(pwd);
	return (0);
}