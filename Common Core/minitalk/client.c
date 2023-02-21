/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:34:40 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/20 16:34:42 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"


int	main(int argc, char **argv)
{
	int	    pid;
	char	*message;

	if (argc != 3)
	{
        ft_printf("The client need 2 parameters instead of %i\n", argc);
        exit(EXIT_FAILURE);
	}
    pid = ft_atoi(argv[1]);
	kill(pid,SIGUSR1);
    return(0);
}