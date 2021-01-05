/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 07:26:58 by mel-kada          #+#    #+#             */
/*   Updated: 2021/01/05 07:35:31 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/libasm.h"

#include <errno.h>
#include <fcntl.h>

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define CYAN "\033[1m\033[36m"

void launch_strdup()
{
	char str[] = "Hello World";
	char big[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s";

	char *ptr;

	printf(CYAN "\n\n========= FT_STRDUP & FT_STRCMP =========\n" RESET);
	if ((ptr = ft_strdup(str)) && ft_strcmp(ptr, str) == 0)
		printf("[1] - ft_strdup & ft_strcmp  " GREEN "OK\n" RESET);
	else
		printf("[1] - ft_strdup & ft_strcmp " RED "KO\n" RESET);
	if ((ptr = ft_strdup("")) && ft_strcmp(ptr, "") == 0)
		printf("[2] - ft_strdup & ft_strcmp  " GREEN "OK\n" RESET);
	else
		printf("[2] - ft_strdup & ft_strcmp " RED "KO\n" RESET);
	if ((ptr = ft_strdup(big)) && ft_strcmp(ptr, big) == 0)
		printf("[3] - ft_strdup & ft_strcmp  " GREEN "OK\n" RESET);
	else
		printf("[3] - ft_strdup & ft_strcmp " RED "KO\n" RESET);
	free(ptr);
}

void launch_strlen()
{
	char str[] = "Hello world";
	char big[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s";

	printf(CYAN "========= FT_STRLEN =========\n" RESET);

	if (ft_strlen(str) == strlen(str))
		printf("[1] - ft_strlen " GREEN "OK\n" RESET);
	else
		printf("[1] - ft_strlen " RED "KO\n" RESET);

	if (ft_strlen(big) == strlen(big))
		printf("[2] - ft_strlen " GREEN "OK\n" RESET);
	else
		printf("[2] - ft_strlen " RED "KO\n" RESET);

	if (ft_strlen("") == strlen(""))
		printf("[3] - ft_strlen " GREEN "OK\n" RESET);
	else
		printf("[3] - ft_strlen " RED "KO\n" RESET);
}

void launch_strcpy()
{
	char *dest;
	char big[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s";

	dest = malloc(300);

	printf(CYAN "\n\n========= FT_STRCPY & FT_STRCMP =========\n" RESET);

	if (NULL != ft_strcpy(dest, "Hello world") && ft_strcmp(dest, "Hello world") == 0)
		printf("[1] - ft_strcpy & ft_strcmp " GREEN "	OK\n" RESET);
	else
		printf("[1] - ft_strcpy & ft_strcmp " RED "	KO\n" RESET);

	if (NULL != ft_strcpy(dest, "") && ft_strcmp(dest, "") == 0)
		printf("[2] - ft_strcpy & ft_stsrcmp " GREEN "	OK\n" RESET);
	else
		printf("[2] - ft_strcpy & ft_strcmp " RED "	KO\n" RESET);

	if (NULL != ft_strcpy(dest, big) && ft_strcmp(dest, big) == 0)
		printf("[3] - ft_strcpy & ft_strcmp " GREEN "	OK\n" RESET);
	else
		printf("[3] - ft_strcpy & ft_strcmp " RED "	KO\n" RESET);
	free(dest);
}

void launch_write()
{
	ssize_t ret;

	char str[] = "Hello world";
	char big[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s";
  
	ret = 0;
	printf(CYAN "\n\n========= FT_WRITE =========\n" RESET);
	if ((ret = ft_write(1, str, ft_strlen(str))) && ret == (int)ft_strlen(str))
		printf("\n[1] - ft_write " GREEN "	OK\n" RESET);
	else
		printf("\n[1] - ft_write " RED "	KO\n" RESET);
	if ((ret = ft_write(1, big, ft_strlen(big))) && ret == (int)ft_strlen(big))
		printf("\n[2] - ft_write " GREEN "	OK\n" RESET);
	else
		printf("\n[2] - ft_write " RED "	KO\n" RESET);

	if ((ret = ft_write(23, str, ft_strlen(str))) && (ret == -1))
		printf("\n[3] - ft_write with bad FD [errno = %s] " GREEN "	OK" RESET, strerror(errno));
	if ((ret = write(23, str, ft_strlen(str))) && (ret == -1))
		printf("\n[3] - write with bad FD [errno = %s] " GREEN "		OK\n" RESET, strerror(errno));
}

void	launch_read()
{
	int	ret;
	int	fd;
	char buf[31];

	ret = 0;
	printf(CYAN "\n\n========= FT_READ =========\n" RESET);

	fd = open("test.c", O_RDONLY);
	ret = ft_read(fd, buf, 30);
	buf[ret] = 0;
	printf("FT_READ content --------\n\n");
	printf("Return = %d\n", ret);
	printf("%s", buf);
	printf("\n------------------------\n");

	memset(buf, 0, 30);
	fd = open("test.c", O_RDONLY);
	ret = read(fd, buf, 30);
	buf[ret] = 0;
	printf("READ content --------\n\n");
	printf("Return = %d\n", ret);
	printf("%s", buf);
	printf("\n------------------------\n");
	memset(buf, 0, 30);
	fd = open("not_exist", O_RDONLY);
	ret = ft_read(fd, buf, 30);
	buf[ret] = 0;
	printf("FT_READ content --------\n\n");
	printf("Return = %d\n", ret);
	printf("errno = %s", strerror(errno));
	printf("\n------------------------\n");

	memset(buf, 0, 30);
	fd = open("not_exist", O_RDONLY);
	ret = read(fd, buf, 30);
	buf[ret] = 0;
	printf("READ content --------\n\n");
	printf("Return = %d\n", ret);
	printf("errno = %s", strerror(errno));
	printf("\n------------------------\n");
}

int main(void)
{
	launch_strlen();
	launch_strcpy();
	launch_strdup();
	launch_write();
	launch_read();
	return (0);
}