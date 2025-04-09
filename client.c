/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:52:11 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/08 21:33:53 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int g;

void	pc(char c, pid_t nbr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g = 0;
		if (((c >> i) & 1) == 1)
			kill(nbr, SIGUSR2);
		else
			kill(nbr, SIGUSR1);
		// usleep(500);
		while (!g);
		i++;
	}
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	handle(int sig)
{
	(void)sig;
	g = 1;
}


int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	re;

	i = 0;
	sign = 1;
	re = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		re = re * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
	{
		write(1, "INVALID PID\n", 12);
		exit(1);
	}
	return (re * sign);
}

void	check_pid(pid_t nbr)
{
	int	re;

	if (nbr < 0 || nbr == 0)
	{
		write(1, "INVALID PID\n", 12);
		exit(1);
	}
	re = kill(nbr, 0);
	if (re == -1)
	{
		write(1, "INVALID PID\n", 12);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		nbr;
	char	*s;
	int		i;

	if (argc > 3)
	{
		write(1, "{-} More Than Enough Arguements\n", 32);
		exit(1);
	}
	if (argc != 3)
	{
		write(1, "{-} Not Enough arguement\n", 25);
		exit(1);
	}
	nbr = ft_atoi(argv[1]);
	s = argv[2];
	i = 0;
	check_pid(nbr);
	signal(SIGUSR1,  handle);
	while (s[i])
	{
		pc(s[i], nbr);
		i++;
	}
	// global var access 
	return (0);
}
