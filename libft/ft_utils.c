/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:36 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/30 14:02:01 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_numlen(int num)
{
	int		ret;

	ret = 0;
	if (num < 0)
	{
		ret++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		if (num == 0)
			break ;
		ret++;
	}
	return (ret + 1);
}
