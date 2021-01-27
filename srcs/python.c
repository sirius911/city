#include "../includes/city.h"

static char		*ft_strcpy(char *dest, const char *src)
{
	size_t		i;
	
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char		*ft_strcat(char *dest, const char *src)
{
	size_t		i;
	size_t		j;
	
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

void		put_card(t_out out)
{
	char	command[38];
	char	o[2];
	
	ft_strcpy(command, "./python/23017-");
	ft_strcat(command, (out.add == 20) ? "20.py -b " : "21.py -b ");
	command[24] = out.bank;
	command[25] = 0;
	ft_strcat(command, " -o ");
	o[0] = (char)out.o + '0';
	o[1] = 0;
	ft_strcat(command, o);
	ft_strcat(command, " -s ");
	ft_strcat(command, (out.state) ? "high" : "low");
	system(command);
}
