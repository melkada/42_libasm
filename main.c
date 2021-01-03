#include <stdio.h>
#include <errno.h>
#include "./srcs/libasm.h"

int	main(void)
{
	printf("%d", write(9, "He", 2));
	printf("\n%d", errno);
	return (0);
}
