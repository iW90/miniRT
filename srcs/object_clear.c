/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:05:27 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/24 13:53:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clear_objects(void)
{
	t_object	*head;
	t_object	*tmp;

	head = get_data()->objects;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->object);
		free(tmp);
	}
	get_data()->objects = NULL;
}
