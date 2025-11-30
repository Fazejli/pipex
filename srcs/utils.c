/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:34:48 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/08 17:20:48 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
//Recherche du chemin de la commande dans les chemins PATH de l'environnement.
char	*get_path(char **ev, char *cmd)
{
	char	*tmp;
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	if (!cmd || !*cmd | !*ev)
		return (NULL);
	while (*ev && !ft_strnstr(*ev, "PATH", 4))
		ev++;
	if (!*ev)
		return (NULL);
	paths = ft_split(ev[i] + 5, ':');
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

//Decouper l'argument contenant la commande afin de
//la chercher dans les chemins PATH pour l'executer
void	execute(char *av, char **ev)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!av || !*av)
	{
		execve("/bin/cat", cmd, ev);
		mess_error(NULL, 0);
	}
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], F_OK | X_OK) == 0)
			execve(cmd[0], cmd, ev);
		else
			mess_error(cmd[0], 126);
	}
	path = get_path(ev, cmd[0]);
	if (!path)
	{
		free_split(cmd);
		mess_error(av, 127);
	}
	execve(path, cmd, ev);
	mess_error("Command not found\n", 127);
	free(path);
}

/* Redirige la sortie standard vers l'entrée du pipe */
/* Redirige l'entrée standard depuis le fichier d'entrée */
void	child(t_pipex pipex, char **av, char **ev)
{
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		mess_error(av[1], 1);
	dup2(pipex.fd[1], 1);
	dup2(pipex.infile, 0);
	close(pipex.fd[0]);
	execute(av[2], ev);
}

/* Redirige l'entrée standard depuis le pipe */
/* Redirige la sortie standard vers le fichier de sortie */
void	parent(t_pipex pipex, char **av, char **ev)
{
	dup2(pipex.fd[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.fd[1]);
	execute(av[3], ev);
}
