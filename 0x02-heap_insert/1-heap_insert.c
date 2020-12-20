#include "binary_trees.h"

/**
 * max_heap_height - It finds the max-heap height.
 *
 * @head: root node of max-heap.
 * @h: pointer to height. It starts from 0.
 */

void max_heap_height(heap_t *head, int *h)
{
	*h += 1;

	if (head->left != NULL)
		max_heap_height(head->left, h);
}

/**
 * next_parent - It searches for the parent of the new node.
 *
 * @head: pointer to some tree node, it starts beint the root.
 * @result: found parent of new node.
 * @tree_height: total height of current tree.
 * @height: height (in fact depth) of current selected node.
 */

void next_parent(heap_t *head, heap_t **result, int tree_height, int height)
{
	height += 1;

	if (tree_height - 1 == height)
	{
		if (head->left == NULL || head->right == NULL)
			*result = head;
		return;
	}

	if (head->left != NULL)
		next_parent(head->left, result, tree_height, height);
	if ((*result) == NULL && head->right != NULL)
		next_parent(head->right, result, tree_height, height);
}

/**
 * heapify - Swaps new_node with its parent depending on theirs
 * n values and also sets the root if needed.
 *
 * @root: double pointer to root node.
 * @new_node: double pointer to new node.
 */

void heapify(heap_t **root, heap_t **new_node)
{
	int n_parent = 0;

	if ((*new_node)->parent == NULL)
	{
		*root = *new_node;
		return;
	}

	if ((*new_node)->n > ((*new_node)->parent)->n)
	{
		n_parent = (*new_node)->parent->n;
		(*new_node)->parent->n = (*new_node)->n;
		(*new_node)->n = n_parent;

		*new_node = (*new_node)->parent;

		heapify(root, new_node);
	}
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap.
 *
 * @root	: double pointer to the root node of the Heap.
 * @value: the value store in the node to be inserted.
 *
 * Return: returns a pointer to the inserted node, or NULL on failure.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;
	int tree_height = 0;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	max_heap_height(*root, &tree_height);
	if (tree_height > 1)
		next_parent(*root, &parent, tree_height, 0);
	else
		parent = *root;
	if (parent == NULL)
	{
		parent = *root;
		while (parent->left != NULL)
			parent = parent->left;
	}
	if (parent->left == NULL)
	{
		parent->left = new_node;
		new_node->parent = parent;
	}
	else
	{
		parent->right = new_node;
		new_node->parent = parent;
	}

	heapify(root, &new_node);

	return (new_node);
}
