/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:30:23 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/23 19:08:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_parse_cmd_2(t_data *data, char **argv, char **envp)
{
	data->cmd_and_flags_2 = ft_strsplit(argv[3], ' ');
	if (!data->cmd_and_flags_2)
	{
		perror("Split of command/flags not valid\n");
		exit(1);
	}
	data->cmd_2 = data->cmd_and_flags_2[0];
	if (!ft_search_cmd_2(data, envp))
	{
		ft_putstr_fd("Error: not executable command 2.\n", 1);
		ft_putstr_fd(data->cmd_1, 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(data->cmd_2, 1);
		ft_putstr_fd("\n", 1);
		perror("");
		exit(1);
	}	
}

static void	ft_free_str0(t_data *data, char *bf_pt, char **spl_pt)
{
	data->x = 0;
	data->path_cmd_2 = ft_strdup(bf_pt);
	while (spl_pt[data->x])
	{
		free(spl_pt[data->x]);
		data->x++;
	}
	free(spl_pt);
	free(bf_pt);
}

static void	ft_free_str1(t_data *data, char *bf_pt, char **spl_pt)
{
	data->i = 0;
	free(bf_pt);
	while (spl_pt[data->i])
	{
		free(spl_pt[data->i]);
		data->i++;
	}
	free(spl_pt);
}

int	ft_search_cmd_2(t_data *data, char **envp)
{
	char	*path;
	char	**splitted_paths;
	char	*buffer_tmp;
	char	*buffer_path;

	buffer_path = NULL;
	path = envp[ft_index_position(envp, "PATH=")] + 5;
	splitted_paths = ft_split(path, ':');
	data->i = 0;
	while (splitted_paths[data->i])
	{
		buffer_tmp = ft_strjoin(splitted_paths[data->i], "/");
		if (buffer_path)
			free(buffer_path);
		buffer_path = ft_strjoin(buffer_tmp, data->cmd_2);
		free(buffer_tmp);
		if (access(buffer_path, X_OK) != -1)
		{
			ft_free_str0(data, buffer_path, splitted_paths);
			return (1);
		}
		data->i++;
	}
	ft_free_str1(data, buffer_path, splitted_paths);
	return (0);
}
