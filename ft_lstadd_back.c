/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:56:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/13 17:12:55 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((lst == NULL) || (new == NULL))
		return ;
	while ((*lst != NULL) && ((*lst)->next != NULL))
		*lst = (*lst)->next;
	new->next = NULL;
	if (*lst != NULL)
		*lst = new;
	else
}
