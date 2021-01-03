#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "./srcs/libasm.h"

int	main(void)
{
	char *buf;

	int fd = open("./srcs/ft_read.s", O_RDONLY);

	ft_read(fd, buf, 20000);
	printf("%s", buf);
	return (0);
}