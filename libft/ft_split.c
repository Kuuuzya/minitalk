/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: skuznets <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/24 15:28:31 by skuznets		  #+#	#+#			 */
/*   Updated: 2024/01/24 22:16:08 by skuznets		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	ft_word_len(char const *s, char c, int i)
{
	int	word_len;

	word_len = 0;
	while (s[i + word_len] != c && s[i + word_len] != '\0')
		word_len++;
	return (word_len);
}

char	**ft_create_words(char **result, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = (char *)malloc(sizeof(char) * \
			(ft_word_len(s, c, i) + 1));
			if (!result[j])
				return (NULL);
			k = 0;
			while (s[i] != c && s[i])
				result[j][k++] = s[i++];
			result[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	result[ft_count_words(s, c)] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	return (ft_create_words(result, s, c));
}
