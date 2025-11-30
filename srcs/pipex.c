/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:34:40 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/08 17:17:55 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	mess_error(char *str, int code)
{
	if (errno)
	{
		ft_putstr_fd("zsh: ", 2);
		perror(str);
	}
	else
	{
		ft_putstr_fd("zsh: ", 2);
		ft_putstr_fd(str, 2);
	}
	exit(code);
}

int	main(int ac, char **av, char **ev)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		ft_putstr_fd("ERROR: More or less arg than expected!\n", 2);
		return (exit(0), 1);
	}
	pipex.outfile = open(av[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (pipex.outfile < 0)
		mess_error(av[4], 1);
	if (pipe(pipex.fd) < 0)
		mess_error("ERROR: Pipe error\n", 1);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		mess_error("ERROR: Fork fail\n", 1);
	if (pipex.pid1 == 0)
		child(pipex, av, ev);
	else
	{
		waitpid(pipex.pid1, NULL, 0);
		parent(pipex, av, ev);
	}
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	return (0);
}
