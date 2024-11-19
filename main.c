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
	/*close(1);*/
	tmp = ft_printf("%s", "");
	tmp2 = printf("%s", "");
	/*dup2(stdout_cpy, 1);*/
	ft_putnbr_fd(tmp, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(tmp2, 1);
	write(1, "\n", 1);
	tmp = write (1, "", strlen(""));
	write(1, "\n", 1);
	ft_putnbr_fd(tmp, 1);
	write(1, "\n", 1);
}
