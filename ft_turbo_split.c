/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turbo_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:12:31 by albaud            #+#    #+#             */
/*   Updated: 2023/07/02 21:45:42 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <malloc/malloc.h>

char	**ft_split(char *str, char c)
{
	char			*d;
	char			**r;
	const size_t	i[9] = (const size_t []){-1, -1, -1, 0, -1, -1, -1, -1, -1};

	while (str && str[++((size_t *)i)[1]] && ((i[6] && ((str[i[1]] == c &&
		++((size_t *)i)[7] < (size_t)-1) || ++((size_t *)i)[6])) || 1))
		;
	d = malloc((i[1] - (i[7] + 1) + (str != 0)));
	if (d == 0)
		return (0);
	while (++((size_t *)i)[0] < i[1] - i[7])
		d[i[0]] = 0;
	while (++((size_t *)i)[8] < (size_t)-1 && str[++((size_t *)i)[7]])
		if (str[i[7]] != c || (i[8] && d[i[8] - 1] && ++((size_t *)i)[3] > -1))
			d[i[8]] = str[i[7]];
	r = malloc(((i[3] + 2 - (d[i[8] - (i[8] != 0)] == 0)) * 8));
	if (r == 0)
		free(d);
	if (r == 0)
		return (0);
	while ((long long)++((size_t *)i)[4] < (long long)(i[8] - (i[8] != 0)))
		if ((i[4] == 0 && d[i[4]] != 0) || (d[i[4] + 1] != 0 && d[i[4]] == 0))
			r[++((size_t *)i)[5]] = &d[i[4] + !(i[4] == 0 && d[i[4]] != 0)];
	r[++((size_t *)i)[5]] = 0;
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
	printf("mmais\n");
	if (r == 0)
		return (0);
	if (r[0] == 0)
	{
		free(r[0]);
		free(r);
		printf("split[0] is null\n");
		return (0);
	}
	i = -1;
	while (r[++i])
		printf("%s$\n", r[i]);
	free(r[0]);
	free(r);
}
