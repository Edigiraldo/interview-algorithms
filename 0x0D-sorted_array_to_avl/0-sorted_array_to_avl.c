#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * add_middle_value - create node with value in the middle of the array.
 *
 * @tree: - double pointer to root of new tree.
 * @array: array with the values of nodes.
 * @idx_l: left index of subarray.
 * @idx_r: right index of subarray.
 *
 * Return: new node created.
 */

avl_t *add_middle_value(avl_t **tree, int *array, int idx_l, int idx_r)
{
	int value = 0;
	size_t value_idx = 0;
	avl_t *node = NULL;

	if (tree == NULL || idx_r < idx_l)
		return (NULL);

	value_idx = (idx_r  - idx_l) / 2 + idx_l;
	value = array[value_idx];

	node = binary_tree_node(NULL, value);
	if (node == NULL)
		return (NULL);
	if (*tree == NULL)
		*tree = node;

	node->left = add_middle_value(tree, array, idx_l, value_idx - 1);
	if (node->left != NULL)
		(node->left)->parent = node;
	node->right = add_middle_value(tree, array, value_idx + 1, idx_r);
	if (node->right != NULL)
		(node->right)->parent = node;

	return (node);
}



/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 *
 * @array: is a pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 * You can assume there will be no duplicate value in the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	add_middle_value(&tree, array, 0, (int) size - 1);

	return (tree);
}
