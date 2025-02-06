/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:11:28 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/05 12:27:00 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdarg.h>

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *hs, const char *n, size_t len);
void	execute(char *av, char **envp);
void	error(void);
char	*free_paths_return(char **paths, char *return_value);
char	*find_path(char *command, char **envp);
char	*extract_regular_word(const char *s, int *i, char c);
int		is_delimiter(char const *s, char c, int *i);
char	*process_word(char const *s, char c, int *i, int is_quote_word);
int		is_quote(char c);
char	**free_array(char **str, int i);
char	*extract_quoted_word(const char *s, int *i, char quote_type);
void	ft_putstr_fd(char *s, int fd);
void	min_error(void);

#endif