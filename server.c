// what function should we use to cancel all other singal but the ones we want to use!
// use atoi for handling the pid
// if pid is invalid; handle that

#include <stdio.h>
#include <unistd.h>


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
	int nbr = getpid();
	ft_putnbr(nbr);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
