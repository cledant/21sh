#include "21sh.h"

void		ft_delete_cur_prompt(t_env *env)
{
	size_t	nb_line;

	nb_line = env->cur_char / env->col;
	while (env->cur_char > 0)
	{
		if (env->cur_char % env->col == 1)
		{
			while (nb_line > 0)
			{
				ft_putstr_fd(env->cd, env->fd_tty);
				nb_line--;
				if (nb_line > 0)
					ft_putstr_fd(env->up, env->fd_tty);
			}
			if (nb_line == 0)
				break ;
		}
		else
		{
			ft_putendl_fd(env->le, env->fd_tty);
			env->cur_char--;
		}
	}
}
