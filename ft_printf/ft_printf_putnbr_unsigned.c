/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:10:58 by mprevot           #+#    #+#             */
/*   Updated: 2017/01/23 19:11:00 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_printf_getarg_nbr_unsigned(va_list args, t_args a)
{
	uintmax_t	nbr;

	nbr = va_arg(args, uintmax_t);
	if (a.lenght == SIZE_HH)
		nbr = (unsigned char)nbr;
	else if (a.lenght == SIZE_H)
		nbr = (unsigned short int)nbr;
	else if (a.lenght == SIZE_L)
		nbr = (unsigned long int)nbr;
	else if (a.lenght == SIZE_LL)
		nbr = (unsigned long long int)nbr;
	else if (a.lenght == SIZE_J)
		nbr = (uintmax_t)nbr;
	else if (a.lenght == SIZE_Z)
		nbr = (size_t)nbr;
	else if (a.type == 'p')
		nbr = (unsigned long)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

void	ft_printf_nbrlen_unsigned_recursive(uintmax_t nbr, t_args *a, char base)
{
	a->tmp++;
	if (nbr == 0 && a->tmp != 0)
		return;
	ft_printf_nbrlen_unsigned_recursive(nbr / base, a, base);
}

void	ft_printf_putnbr_unsigned_recursive(uintmax_t nbr, t_args *a, char base)
{
	uintmax_t	n;

	a->tmp++;
	if (nbr == 0 && a->tmp != 0)
		return ;
	ft_printf_putnbr_unsigned_recursive(nbr / base, a, base);
	n = nbr % base;
	if (n <= 9)
		ft_putchar('0' + n);
	if (n >= 10 && n <= 36)
	{
		if (a->type == 'X')
			ft_putchar('A' + (n - 10));
		else
			ft_putchar('a' + (n - 10));
	}
}

void	ft_printf_putnbr_unsigned(uintmax_t nbr, t_args *a, char base)
{
	int 		spaces;
	int			save;
	uintmax_t	n;

	ft_printf_nbrlen_unsigned_recursive(nbr, a, base);
	save = a->tmp;
	if ((a->zero == -1 || a->precision > 0) && a->width != -1 && a->minus == -1)
	{
		if (a->precision != -1 && a->precision > a->tmp)
			spaces = a->width - a->precision;
		else
			spaces = a->width - a->tmp;
		if (a->hash != -1 && (nbr > 0 || a->type == 'p'))
			spaces--;
		if (a->hash != -1 && ((nbr > 0 && base == 16) || a->type == 'p'))
			spaces--;

		while (spaces-- > 0)
		{
			ft_putchar(' ');
			a->tmp++;
		}
	}
	if(a->hash != -1)
	{
		if ((a->type == 'o' && nbr != 0 && a->precision <= a->tmp) || (a->type != 'o' && (nbr > 0 || a->type == 'p')))
		{
			ft_putchar('0');
			a->tmp++;
		}
		if ((nbr > 0 && base == 16) || a->type == 'p')
		{
			ft_putchar((a->type == 'X' ? 'X' : 'x'));
			a->tmp++;
		}
	}
	if (a->zero != -1 &&  a->precision == -1 &&  a->width != -1 && a->minus == -1)
	{
		spaces = a->width - a->tmp;
		while (spaces-- > 0)
		{
			ft_putchar('0');
			a->tmp++;
		}
	}
	if (a->precision != -1)
	{
		n = (a->precision > save) ? a->precision - save : 0;
		while(n--)
		{
			write(1, "0", 1);
			a->tmp++;
		}
	}


	save = a->tmp;
	a->tmp = -1;
	if ((a->precision != 0 || (a->precision == 0 && nbr != 0)) || (a->hash != -1 && a->type == 'o' ))
		ft_printf_putnbr_unsigned_recursive(nbr, a, base);
	else if (a->type != 'p')
		save = 0;
	else if (a->type == 'p')
		save--;
	a->tmp = save;
	if (a->width != -1 && a->minus != -1)
	{
		spaces = a->width - a->tmp;
		while (spaces-- > 0)
		{
			ft_putchar(' ');
			a->tmp++;
		}
	}
}