/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:29:51 by elangari          #+#    #+#             */
/*   Updated: 2025/11/29 20:29:55 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_return_cnt(char c, int num, unsigned long unum)
{
	size_t	n;
	size_t	base;

	if (c == 'd' || c == 'i' || c == 'u')
		base = 10;
	else
		base = 16;
	n = 0;
	if (c == 'd' || c == 'i')
	{
		if (num < 0)
		{
			unum = ((long)num) * (-1);
			n++;
		}
		else
			unum = num;
	}
	while (unum > (base - 1))
	{
		unum = unum / base;
		n++;
	}
	return (n + 1);
}

static int	ft_ifprint_pnt(char c, va_list args)
{
	char			*str;
	unsigned long	unum;

	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		return (ft_putstr_fd(str, 1), ft_strlen(str));
	}
	else
	{
		unum = va_arg(args, unsigned long);
		if (!unum)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		write(1, "0x", 2);
		ft_putnbr_long_base(unum, "0123456789abcdef");
		return (ft_return_cnt(c, 0, unum) + 2);
	}
}

static int	ft_ifprint_num(char c, va_list args)
{
	int				num;
	unsigned long	unum;

	unum = 0;
	num = 0;
	if (c == 'd' || c == 'i')
	{
		num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
		return (ft_return_cnt(c, num, unum));
	}
	unum = va_arg(args, unsigned);
	if (c == 'u')
		ft_putuns(unum);
	else if (c == 'x')
		ft_putnbr_base(unum, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(unum, "0123456789ABCDEF");
	return (ft_return_cnt(c, num, unum));
}

static int	ft_ifprint(char c, va_list args)
{
	int		n;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		n = 1;
	}
	else if (c == 's' || c == 'p')
		n = ft_ifprint_pnt(c, args);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		n = ft_ifprint_num(c, args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		n = 1;
	}
	else
		return (0);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	size_t		cnt;
	va_list		args;
	char		c;
	int			n;

	n = 0;
	cnt = 0;
	va_start(args, s);
	while (s[cnt] != 0)
	{
		if (s[cnt] == 37)
		{
			cnt++;
			c = s[cnt];
			n += ft_ifprint(c, args);
			cnt++;
		}
		else
		{
			ft_putchar_fd(s[cnt], 1);
			n++;
			cnt++;
		}
	}
	return (n);
}
