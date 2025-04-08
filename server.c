// what function should we use to cancel all other singal but the ones we want to use!
// use atoi for handling the pid
// if pid is invalid; handle that

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


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

void	sig_super_func(int n, siginfo_t *more, void *pure)
{
	// static var to keep track of how many bit written so far!
	// one other variable to store the value so far for the character
	static int i_bits = 0;
	static char c = 0;
	(void)pure;
	(void)more;
	if (n == SIGUSR2)
		c |= (1 << (i_bits));
	i_bits++;
	if (i_bits == 8)
	{
		write(1, &c, 1);
		c = 0;
		i_bits = 0;
	}
}

int main(void)
{
	int nbr = getpid();
	ft_putnbr(nbr);
	ft_putchar('\n');
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_super_func;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
