#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int g;

void	pc(char c, pid_t nbr)
{
	int i;

	i = 0;
	g = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 1)
			kill(nbr, SIGUSR2);
		else
			kill(nbr, SIGUSR1);
		i++;
		while (!g);
	}
}

int ft_atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int re = 0;
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
	return (re * sign);
}


// write a function that takes either sigusr1 or sigusr2 
// and print either 0 or 1 based on which signal you received!

void check_pid(pid_t nbr)
{
	int re = kill(nbr, 0);
	if (re == -1)
	{
		write(1, "INVALID PID\n", 12);
		exit(1);
	}
}

void	handle(int signum)
{
	(void)signum;
	g = 1;
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	int nbr;
	int i;
	char *s;

	if (argc != 3)
	{
		write(1, "{-} Not Enough arguement\n", 25);
		exit(1);
	}
	nbr = ft_atoi(argv[1]);
	s = argv[2];
	i = 0;
	check_pid(nbr);
	sa.sa_handler = handle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	// signal(SIGUSR1, handle);
	while (s[i])
	{
		pc(s[i], nbr); // process character
		i++;
	}
	return (0);
}
