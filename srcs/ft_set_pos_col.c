#include "21sh.h"

void	ft_set_pos_col(t_env *env)
{
	t_btree		*cmd;
	char		*s;

	env->pos_col = 0;
	cmd = env->last->content;
	if (cmd->content == NULL)
		return ;
	while (cmd != env->cur_il)
	{
		s = cmd->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			env->pos_col = 0;
		else
			env->pos_col++;	
		cmd = cmd->right;
	}
}
