#include "21sh.h"

t_btree		*ft_btree_pushback_cpy_node(t_btree *src, t_btree *cpy, t_env *env)
{
	t_btree		*new;
	t_btree		*first;
	

	if (cpy == NULL)
	{
		if ((first = ft_btree_new(src->content, 4)) == NULL)
			return (NULL);
	}
	else
	{
		first = cpy;
		while(cpy->right != NULL)
			cpy = cpy->right;
		if ((new = ft_btree_new(src->content, 4)) == NULL)
		{
			ft_btree_del_all_node(&first);
			return (NULL);
		}
		env->cur_il = new;
		new->left = cpy;
		cpy->right = new;
	}
	return (first);
}
