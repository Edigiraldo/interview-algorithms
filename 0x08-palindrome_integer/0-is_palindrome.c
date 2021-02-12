/**
 * is_palindrome - function that checks whether
 * or not a given unsigned integer is a palindrome.
 *
 * @n: Number to be checked.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	unsigned long copy = n, backwards = 0;

	while (copy)
	{
		backwards = backwards * 10 + copy % 10;
		copy /= 10;
	}
	return (n == backwards);
}
