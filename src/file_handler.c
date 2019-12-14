/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:04:01 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/12 20:16:29 by wsmoked          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mtrxalloc(t_matrix *m)
{
	int		i;

	i = 0;
	if (!(m->m = (t_fdf **)malloc(sizeof(t_fdf *) * (m->rows))))
		return (-1);
	while (i < m->rows)
	{
		if (!(m->m[i] = (t_fdf *)malloc(sizeof(t_fdf) * (m->cols))))
			return (-1);
		ft_bzero(m->m[i], sizeof(t_fdf) * (m->cols));
		i++;
	}
	return (0);
}

int	ft_init_struct(t_matrix *mtrx, t_list *f)
{
	int		i;
	int		j;
	char	**data;

	i = -1;
	while (++i < mtrx->rows)
	{
		data = ft_strsplit(((char *)f->content), ' ');
		if (ft_2darr_len(data) != mtrx->cols)
		{
			ft_del_2darr(data);
			return (-1);
		}
		j = -1;
		while (++j < mtrx->cols)
		{
			mtrx->m[i][j].x = j;
			mtrx->m[i][j].y = i;
			if (data[j][0] >= '0' && data[j][0] <= '9')
				mtrx->m[i][j].z = ft_atoi(data[j]);
			else
				return (-1);
			mtrx->m[i][j].color = ft_get_color(data[j], mtrx->m[i][j].z);
		}
		f = f->next;
		ft_del_2darr(data);
	}
	return (0);
}

int	ft_file_review(char *fname)
{
	int		fd;
	char	buf[1];

	if (!(fd = open(fname, O_RDONLY)) || fd < 0 || (read(fd, NULL, 0) == -1))
		return (E_NOFILE);
	if (read(fd, buf, 1) == 0)
		return (E_EMPTY_FILE);
	close(fd);
	return (0);
}

int	ft_list_init(t_list **f, t_env *win, char *fname)
{
	int		fd;
	t_list	*next;
	char	**data;

	fd = open(fname, O_RDONLY);
	(*f) = ft_lstnew(NULL, 0);
	next = (*f);
	while (get_next_line(fd, (char **)&(next->content)))
	{
		next->next = ft_lstnew(NULL, 0);
		next = next->next;
	}
	close(fd);
	next = (*f);
	win->mtrx.rows = 0;
	while (next->next != NULL)
	{
		next = next->next;
		win->mtrx.rows++;
	}
	data = ft_strsplit((char *)((*f)->content), ' ');
	win->mtrx.cols = ft_2darr_len(data);
	ft_del_2darr(data);
	return (0);
}

int	reading_file(t_env *win, char *fname)
{
	t_list	*f;
	int		err_numb;

	if ((err_numb = ft_file_review(fname)) < 0)
		return (-1);
	ft_list_init(&f, win, fname);
	if (ft_mtrxalloc(&(win->mtrx)) < 0)
		return (-1);
	if (ft_init_struct(&(win->mtrx), f) < 0)
	{
		ft_del_list(&f);
		return (-1);
	}
	ft_del_list(&f);
	win->draw_mtrx.cols = win->mtrx.cols;
	win->draw_mtrx.rows = win->mtrx.rows;
	if (ft_mtrxalloc(&(win->draw_mtrx)) < 0)
		return (-1);
	return (0);
}
