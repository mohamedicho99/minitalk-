#include <unistd.h>


void	print_octet(unsigned char octet)
{
	int i = 7;
	unsigned char o;

	while (i >= 0)
	{
		o = ((octet >> i) & 1) + '0';
		write(1, &o, 1);
		i--;
	}

}

int main(void)
{
	unsigned char o = 2;
	print_octet(o);
	return (0);
}
