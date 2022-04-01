void	ft_remove_first_char(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		str[0] = str[1];
		str++;
	}
}

void	ft_remove_first_slash(char *str)
{
	ft_remove_first_char(str);
}
