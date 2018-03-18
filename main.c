#include "libft.h"
int main(int argc, const char *argv[])
{
	unsigned char		mem[4] = {255, 255, 255, 255};
	ft_printf("%lu\n", ft_mtoi(mem, 4));
	return 0;
}
