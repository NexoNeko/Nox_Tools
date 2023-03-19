/**
* swap_nodes - swaps two nodes in a doubly linked list
*
* @to_right - node on the left that's going right| R | >> | L |
* @to_left - node on the right that's going left | R | << | L |
*/
void swap_nodes(listint_t *to_right, listint_t *to_left)
{
	if (to_left->next)
		to_left->next->prev = to_right;
	if (to_right->prev)
		to_right->prev->next = to_left;

	to_right->next = to_left->next;
	to_left->next = to_right;
	to_left->prev = to_right->prev;
	to_right->prev = to_left;
}