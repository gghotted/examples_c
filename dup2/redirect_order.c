/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gypark <gypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:31:10 by gypark            #+#    #+#             */
/*   Updated: 2021/02/14 09:59:41 by gypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	run_dummy_cmd()
{
	write(1, "this cmd is dummy\n", 18);
	write(2, "an error has occurred.", 22);
}

void	test1()
{
	int fd = open("output/redirect_order_test1.txt", O_WRONLY | O_CREAT, 0644);

	dup2(fd, 1);
	dup2(1, 2);
	run_dummy_cmd();
	close(fd);
}

void	test2()
{
	int fd = open("output/redirect_order_test2.txt", O_WRONLY | O_CREAT, 0644);

	dup2(1, 2);
	dup2(fd, 1);
	run_dummy_cmd();
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argv[1][0] == '1')
		test1();
	if (argv[1][0] == '2')
		test2();
	return(0);
}
