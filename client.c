// use atoi for handling the pid
// if pid is invalid; handle that
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	pc(char c, pid_t nbr)
{
	int i;
	unsigned char octet;

	i = 8;
	while (i--)
	{
		if (((octet >> i) & 1) == 1)
			kill(nbr, SIGUSR2);
		else
			kill(nbr, SIGUSR1);
		usleep(42);
	}
}

int ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

int ft_atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int re = 0;
	while (ft_isspace(s[i]))
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
	return (re * sign);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nbr)
{
	long n = nbr;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

// write a function that takes either sigusr1 or sigusr2 
// and print either 0 or 1 based on which signal you received!

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "{-} Not Enough arguement\n", 25);
		exit(1);
	}
	int nbr = ft_atoi(argv[1]);
	char *s = argv[2];
	int i = 0;
	while (s[i])
	{
		pc(s[i], nbr); // process character
		i++;
	}
	return (0);
}
