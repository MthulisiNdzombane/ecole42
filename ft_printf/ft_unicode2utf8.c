#include "ft_printf.h"

size_t		ft_charsize(t_unicode c)
{
	if ((int)c < 128)
		return 1;
	else if ((int)c < 2048)
		return 2;
	else if ((int)c < 65536)
		return 3;
	else if ((int)c < 2097152)
		return 4;
	else
		return 5;
}

size_t		ft_strsize(t_unicode *str)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		size += ft_charsize(str[i]);
		i++;
	}
	return (size);
}


t_utf8		*ft_unicode2utf8(t_unicode *i_str, size_t *size)
{
	t_utf8	*c_str;
	size_t	i;

	i = 0;
	*size = 0;
	if (!(c_str = (t_utf8*)ft_strnew(ft_strsize(i_str))))
		return (NULL);
	while (i_str[i])
	{
		size_t chars = ft_charsize(i_str[i]);
		int		nbr;
		int		save = i_str[i];
		nbr = 0;
		if (chars == 1)
		{
			c_str[*size] = (t_utf8)i_str[i];
			i++;
			(*size)++;
			continue;
		}
		else if (chars == 2)
			nbr = 0xC080;
		else if (chars == 3)
			nbr = 0xE08080;
		else if (chars == 4)
			nbr = 0xF0808080;
		int 	toWrite = 0x3F;
		while (chars--)
		{
			nbr = (nbr | (save & toWrite));			
			save = save << 2;
			toWrite = toWrite << 8;
		}
		chars = ft_charsize(i_str[i]);
		(*size) += chars;
		while (chars--)
			c_str[(*size) - chars] = (t_utf8)(nbr >> (8 * chars));
		(*size)++;
		i++;		
	}
	return c_str;
}