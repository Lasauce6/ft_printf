#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	tmp;
	int	tmp2;
	int	stdout_cpy;

	stdout_cpy = dup(1);
	close(1);
	tmp = ft_printf("ret : %s\n", 6);
	tmp2 = printf("ret : %s\n", "");
	dup2(stdout_cpy, 1);
	ft_putnbr_fd(tmp, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(tmp2, 1);
	write(1, "\n", 1);
}
