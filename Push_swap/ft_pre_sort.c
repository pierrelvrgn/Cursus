/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:06:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/04 13:22:53 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_sort(t_control *control, int place)
{
	int		max;
	int		index;
	t_pile	*actuel;
	int		pos;

	index = 0;
	max = 2147483647;
	actuel = control->list_a;
	while (actuel)
	{
		if (actuel->nb <= max && actuel->pos == -1)
		{
			max = actuel->nb;
			pos = index;
		}
		actuel = actuel->next;
		index++;
	}
	index = 0;
	actuel = control->list_a;
	while (index < pos && actuel->next)
	{
		actuel = actuel->next;
		index++;
	}
	actuel->pos = place;
}

void	sort_pile(t_control *control)
{
	t_pile	*actuel;

	if (control == NULL)
	{
		exit(EXIT_FAILURE);
	}
	actuel = control->list_a;
	while (actuel)
	{
		actuel->pos = -1;
		actuel = actuel->next;
	}
}

int	ft_len_pile_a(t_control *control)
{
	int		nb;
	t_pile	*tmp;

	nb = 0;
	tmp = control->list_a;
	while (tmp)
	{
		tmp = tmp->next;
		nb++;
	}
	return (nb);
}

int	ft_is_sort(t_control *control, int len)
{
	t_pile	*tmp;
	int		nb;

	nb = 0;
	tmp = control->list_a;
	while (tmp && nb < len)
	{
		if (nb > tmp->pos)
			return (0);
		nb++;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_rotate_a(t_control *control)
{
	t_pile	*tmp;
	t_pile	*move;

	move = control->list_a;
	tmp = control->list_a;
	control->list_a = move->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = move;
	move->next = NULL;
	printf("ra\n");
}

void	ft_push_a(t_control *control)
{
	t_pile	*tmp;

	tmp = control->list_b;
	if (!tmp)
		return ;
	if (!control->list_a)
	{
		control->list_b = tmp->next;
		control->list_a = tmp;
		tmp->next = NULL;
	}
	else
	{
		control->list_b = tmp->next;
		tmp->next = control->list_a;
		control->list_a = tmp;
	}
	printf("pa\n");
}

void	ft_push_b(t_control *control)
{
	t_pile	*tmp;

	tmp = control->list_a;
	if (!tmp)
		return ;
	if (!control->list_b)
	{
		control->list_a = tmp->next;
		control->list_b = tmp;
		tmp->next = NULL;
	}
	else
	{
		control->list_a = tmp->next;
		tmp->next = control->list_b;
		control->list_b = tmp;
	}
	printf("pb\n");
}

void	ft_algo_500(t_control *control)
{
	int	i;
	int	j;
	int	k;
	int	len;

	len = ft_len_pile_a(control);
	j = 0;
	while (!ft_is_sort(control, len))
	{
		i = 0;
		while (i < len)
		{
			k = control->list_a->pos >> j;
			if ((k & 1) == 1)
				ft_rotate_a(control);
			else
				ft_push_b(control);
			i++;
		}
		while (control->list_b)
			ft_push_a(control);
		j++;
	}
}

void	sort_0_to_100(t_control *control)
{
	t_pile	*actuel;
	int		place;

	place = 0;
	sort_pile(control);
	actuel = control->list_a;
	while (actuel)
	{
		if (actuel->pos == -1)
		{
			ft_sort(control, place);
			place++;
			actuel = control->list_a;
		}
		actuel = actuel->next;
	}
	ft_doublon(control);
	ft_algo_500(control);
}

// Radix Sort in C Programming
/*
#include <stdio.h>

// Function to get the largest element from an array
int	get_max(t_control *control, int n)
{
	int		max;
	t_pile	*actuel;

	actuel = control->list_a;
	max = actuel->pos;
	while (actuel)
	{
		if (actuel->pos > max)
			max = actuel->pos;
		actuel = actuel->next;
	}
	return (max);
}

// Using counting sort to sort the elements in the basis of significant places
void	countingSort(t_control control, int size, int place)
{
	int	output[size + 1];
	int	max;
	t_pile *actuel;

	max = (actuel->pos / place) % 10;
	for (int i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	int	count[max + 1];

	for (int i = 0; i < max; ++i)
		count[i] = 0;
  // Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
  // Calculate cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
  // Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (int i = 0; i < size; i++)
	array[i] = output[i];
}

// Main function to implement radix sort
void	radix_sort(t_control control, int size)
{
  // Get maximum element
	int	max = get_Max(control, size);

  // Apply counting sort to sort elements based on place value.
	for	(int place = 1; max / place > 0; place *= 10)
	countingSort(control, size, place);
}

// Print an array
void	printArray(t_control control, int size)
{
	for	(int i = 0; i < size; ++i) {
	printf("%d  ", array[i]);
	}
	printf("\n");
}

// Driver code
int	main(void)
{
	int			j;
	int			i;
	t_control	*control;
	t_pile		*actuel;

	actuel = control->list_a;
	i = 0;
	while (actuel)
	{
		actuel->nb = actuel->pos >> j;
		actuel = actuel->next;
		i++;
	}
	actuel = control->list_a;
	int n = sizeof(actuel) / sizeof(actuel->pos);
	radix_sort(control, n);
	printArray(control, n);
}
*/
/*
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
int getMax(struct ListNode *node) // finding biggest integer in linked list
{
  int max=node->val;
  while(node!=NULL)
  {
    if(node->val > max)
    {
      max=node->val;
    }
    node=node->next;
  }
  return max;
}
void addMin(struct ListNode *node, int min) // Adding smallest integer in linked list so that no integer in linked list is negative
{
  while(node!=NULL)
  {
    node->val+=min;
    node=node->next;
  }
}
void subMin(struct ListNode *node, int min) // returning linked list to original values after sorting
{
  while(node!=NULL)
  {
    node->val-=min;
    node=node->next;
  }
}
int getMin(struct ListNode *node) // finding smallest integer in linked list
{
  int min=node->val;
  while(node!=NULL)
  {
    if(node->val < min)
    {
      min=node->val;
    }
    node=node->next;
  }
  return min;
}
void binarySort(struct ListNode **head, int bit) // sorts linked list based on a particular bit
{
  struct ListNode *temp = *head;
  struct ListNode *insertNode = *head;
  struct ListNode *prevNode = NULL;
  int flag=0;
  int flag2=0;
  if((((*head)->val) & (1 << (bit - 1))))
  {
    flag=1;
  }
  while(temp!=NULL)
  {
    if(flag==0 && !((temp->val) & (1 << (bit - 1))))
    {
      if((temp->next)!=NULL && (((temp->next)->val) & (1 << (bit - 1))))
      {
        insertNode=temp;
        flag=1;
        flag2=1;
      }
    }
    else if(flag2==0 && !((temp->val) & (1 << (bit - 1))))
    {
      prevNode->next=temp->next;
      temp->next=*head;
      insertNode=temp;
      *head=temp;
      temp=prevNode;
      flag=1;
      flag2=1;
    }
    else if(!((temp->val) & (1 << (bit - 1))))
    {
      prevNode->next=temp->next;
      temp->next=insertNode->next;
      insertNode->next=temp;
      insertNode=temp;
      temp=prevNode;
    }
    prevNode=temp;
    temp=temp->next;
  }
}
struct ListNode* sortList(struct ListNode* head) // binary radix sort
{
  if(head==NULL)
  {
    return NULL;
  }
  int min=getMin(head);
  if(min<0)
  {
    subMin(head, min);
  }
  int biggest_int_len = log2(getMax(head))+1;
  int i;
  for(i=1 ; i<=biggest_int_len ; i++)
  {
    binarySort(&head, i);
  }
  if(min<0)
  {
    addMin(head, min);
  }
  return head;
}
int main() // code to test the function
{
  srand(time(0));
  int num;
  struct ListNode *head = (struct ListNode*) malloc(sizeof(struct ListNode));
  head->next=NULL;
  printf("Enter input size: ");
  scanf("%d", &num);
  head->val=rand()%1000;
  struct ListNode *prevNode = head;
  while(num-1>0)
  {
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->val=rand()%1000;
    temp->next=NULL;
    prevNode->next=temp;
    prevNode=temp;
    num--;
  }
  printf("\n\n");
  print_list(head);
  clock_t t;
  t = clock();
  struct ListNode *sortedList=sortList(head);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("\n\n");
  print_list(sortedList);
  printf("\n\nfun() took %f seconds to execute \n", time_taken);
}
*/
