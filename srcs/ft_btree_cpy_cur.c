#include "21sh.h"

t_btree		*ft_btree_cpy_cur(t_btree *previous, t_env *env)
{
	t_btree		*cpy;
	t_btree		*base;
	t_btree		*src;
	
	src = env->cur->content;
	cpy = NULL;
	if ((base = ft_btree_new(NULL, 0)) == NULL)
		return (NULL);
	while (src)
	{
		if ((cpy = ft_btree_pushback_cpy_node(src, cpy, env)) == NULL)
		{
			free(base);
			return (NULL);
		}
		src = src->right;
	}
	base->content = cpy;
	previous->right = base;
	base->left = previous;
	return (base);
}
