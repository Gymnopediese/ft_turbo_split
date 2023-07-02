/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turbo_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:12:31 by albaud            #+#    #+#             */
/*   Updated: 2023/07/02 17:33:15 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <malloc/malloc.h>

char	**ft_split(char *str, char c)
{
	char			*d;
	char			**r;
	const size_t	i[6] = (const size_t []){-1, -1, -1, 0, -1, -1};

	while (str && str[++((size_t *)i)[1]])
		;
	d = malloc(i[1] + (str != 0));
	if (d == 0)
		return (0);
	while (str[++((size_t *)i)[0]])
		d[i[0]] = 0;
	while (str[++((size_t *)i)[2]])
		if (str[i[2]] != c || (i[2] && d[i[2] - 1] && ++((size_t *)i)[3] > -1))
			d[i[2]] = str[i[2]];
	r = malloc((i[3] + 4 - (d[i[2]] == 0) - (d[i[1] - 1] == 0)) * 8);
	if (r == 0)
		free(d);
	if (r == 0)
		return (0);
	while ((long long)++((size_t *)i)[4] < (long long)(i[1] - 1))
		if ((i[4] == 0 && d[i[4]] != 0) || (d[i[4] + 1] != 0 && d[i[4]] == 0))
			r[++((size_t *)i)[5]] = &d[i[4] + !(i[4] == 0 && d[i[4]] != 0)];
	r[++((size_t *)i)[5]] = 0;
	r[++((size_t *)i)[5]] = d;
	return (r);
}

int	main(int argc, char **argv)
{
	char	**r;
	size_t	i;

	ft_split(0, 0);
	if (argc != 2)
	{
		printf("invalid args\n");
		return (0);
	}
	r = ft_split(argv[1], ' ');
	if (r == 0)
		return (0);
	if (r[0] == 0)
	{
		free(r[1]);
		free(r);
		printf("split[0] is null\n");
		return (0);
	}
	i = -1;
	while (r[++i])
		printf("%s$\n", r[i]);
	free(r[++i]);
	free(r);
}
