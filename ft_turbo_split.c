/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turbo_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:12:31 by albaud            #+#    #+#             */
/*   Updated: 2023/07/02 16:19:05 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char c)
{
	char	*d;
	char	**r;
	size_t	*i;

	if (str == 0)
		return (0);
	i = (size_t []){-1, -1, -1, 0, -1, -1};
	while (str[++i[1]])
		;
	d = malloc(i[1] + 1);
	if (d == 0)
		return (0);
	while (str[++i[0]])
		d[i[0]] = 0;
	while (str[++i[2]])
		if (str[i[2]] != c || (i[2] > 0 && d[i[2] - 1] && ++i[3] > -1))
			d[i[2]] = str[i[2]];
	r = malloc((i[3] + 3 - (d[i[2]] == 0) - (d[i[1] - 1] == 0)) * 8);
	if (r == 0 && sizeof(free(d)))
		return (0);
	while ((long long)++i[4] < (long long)(i[1] - 1))
		if ((i[4] == 0 && d[i[4]] != 0) || (d[i[4] + 1] != 0 && d[i[4]] == 0))
			r[++i[5]] = &d[i[4] + !(i[4] == 0 && d[i[4]] != 0)];
	r[++i[5]] = 0;
	return (r);
}

int	main(int argc, char **argv)
{
	char	**r;
	size_t	i;

	if (argc != 2)
	{
		printf("invalid args\n");
		return (0);
	}
	r = ft_split(argv[1], ' ');
	if (r == 0)
	{
		printf("split is null\n");
		return (0);
	}
	if (r[0] == 0)
	{
		printf("split[0] is null\n");
		return (0);
	}
	i = -1;
	while (r[++i])
		printf("%s$\n", r[i]);
}
