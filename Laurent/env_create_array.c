/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:54:29 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/07/14 18:41:12 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** renvoie un tableau avec chaque terme sous la forme environ
** chaque elt du tableau est sous la forme :
** "NAME=value"
** dans le programme envirron plutot que eviron pour ne pas avoir de collision
** avec la macro environ !
*/

#include "minishell.h"

int		ft_list_env_size(t_list_env *begin_list)
{
	int count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

void	env_destroy_array(char **envirron)
{
	int	i;

	i = 0;
	if (!envirron)
		return ;
	while (envirron[i])
	{
		free(envirron[i]);
		envirron[i] = NULL;
		i++;
	}
	free(envirron);
	envirron = NULL;
}

char	**destroy_and_errno_ret(char **ret, char **envirron, int errnb)
{
	env_destroy_array(envirron);
	errno = errnb;
	return (ret);
}

char	*create_str_env(char *name, char *value)
{
	char	*str;
	char	*temp;

	if (!(temp = ft_strjoin(name, "=")))
		return (NULL);
	if (!(str = ft_strjoin(temp, value)))
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (str);
}

char	**env_create_array(t_list_env *env, char **envirron)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	env_destroy_array(envirron);
	size = ft_list_env_size(env);
	if (!(envirron = (char**)malloc(sizeof(char *) * (size + 1))))
		return (destroy_and_errno_ret(NULL, envirron, ENOMEM));
	envirron[size] = NULL;
	while ((i < size) && env)
	{
		if (!(str = create_str_env(env->name, env->value)))
			return (destroy_and_errno_ret(NULL, envirron, ENOMEM));
		envirron[i] = str;
		i++;
		env = env->next;
	}
	return (envirron);
}
