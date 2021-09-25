/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:53 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/15 17:16:02 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>	//per waitpid
# include <fcntl.h>		//per unlink
# include <string.h>
# define MAXLINE 64

typedef struct s_data
{
	char	**cmd_and_flags;
	char	**cmd_and_flags_2;
	char	*cmd_1;
	char	*cmd_2;
	char	*path_cmd_1;
	char	*path_cmd_2;
	char	*file_1;
	char	*file_2;
	char	*buffer_read;
	int		fd_file_1;
	int		fd_file_2;
	int		pipe_fd[2];
	short	i;
	short	x;
}			t_data;

/*
** MiniLibft functions
*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
char		**ft_strsplit(char *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_strcat(char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *s, size_t n);
size_t		ft_strcpy(char *dst, const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
** Pipex program functions
*/
void		ft_check_args(t_data *data, char **argv, char **envp);
void		ft_call_parent(pid_t pid, t_data *data, char **envp);
int			ft_access_file(char *path);
void		ft_parse_cmd_1(t_data *data, char **argv, char **envp);
void		ft_parse_cmd_2(t_data *data, char **argv, char **envp);
int			ft_search_cmd_1(t_data *data, char **envp);
int			ft_search_cmd_2(t_data *data, char **envp);
void		ft_exec_cmd_1(t_data *data, char **envp);
void		ft_exec_cmd_2(t_data *data, char **envp);
void		ft_checkfile_1(t_data *data, char **argv, char **envp);
void		ft_checkfile_2(t_data *data, char **argv, char **envp);
int			ft_search_file_1(t_data *data, char **envp);
int			ft_search_file_2(t_data *data, char **envp);
/*
** Utils functions
*/
int			ft_index_position(char **src, char *to_find);
char		*ft_strtoupper(char *str);
int			ft_toupper(int c);
char		*ft_strnew(size_t size);
int			get_nbwords(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
