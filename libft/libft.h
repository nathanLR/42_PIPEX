/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:01:07 by nle-roux          #+#    #+#             */
/*   Updated: 2024/01/13 18:34:55 by nle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef FD_OPEN_LIMIT
#  define FD_OPEN_LIMIT 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/**
*	This function takes an int as a parameter and check wether it is 
*	an uppercase letter or lower case letter.
*
*	@param		int c			The character to check.
*	@return		int				0 or 1.
*/
int		ft_isalpha(int c);

/**
*	This function takes an int as a parameter and check wether it is 
*	a digit (0,1,2,3,4,5,6,7,8 or 9) or not.
*
*	@param		int c			The character to check.
*	@return		int				0 or 1.
*/
int		ft_isdigit(int c);

/**
*	This function takes an int as a parameter and check wether it complies
*	with ft_isalpha and ft_isdigit.
*
*	@param		int c			The character to check.
*	@return		int				0 or 1.
*/
int		ft_isalnum(int c);

/**
*	This function takes an int as a parameter and check wether it is within
*	the [0,127] range or not.
*
*	@param		int c			The character to check.
*	@return		int				0 or 1.
*/
int		ft_isascii(int c);

/**
*	This function takes an int as a parameter and check wether it is a
*	printable character or not.
*
*	@param		int c			The character to check.
*	@return		int				0 or 1.
*/
int		ft_isprint(int c);

/**
*	This function takes an int as a parameter and check wether it is a
*	\n, \t, \r, \v, \f or a space.
*
*	@param		int c			The character to check.
*	@return		int				0 or 1.
*/
int		ft_isspace(int c);

/**
*	This functions takes an int as a parameter and check if it is a
*	lowercase letter, then transform it.
*
*	@param		int c			The character to transform.
*	@return		int				Uppercase c or c.
*/
int		ft_toupper(int c);

/**
*	This functions returns the absolute value of number.
*
*	@param		int number		The value.
*	@return		int				The absolute value.
*/
int		ft_abs(int number);

/**
*	This functions takes an int as a parameter and check if it is an
*	uppercase letter, then transform it.
*
*	@param		int c			The character to transform.
*	@return		int				Lowercase c or c.
*/
int		ft_tolower(int c);

/**
*	This function compares the two strings given as parameters,
*	and returns the difference if it finds one.
*
*	@param		const char *s1	The first string to compare.
*	@param		const char *s2	The second string to compare.
*	@return		int				0 or the difference between 2 characters.
*/
int		ft_strcmp(const char *s1, const char *s2);

/**
*	This function compares the n first characters of the two strings
*	given as parameters, and returns the difference if it finds one.
*
*	@param		const char *s1	The first string to compare.
*	@param		const char *s2	The second string to compare.
*	@param		size_t n		The maximum number of char to compare.
*	@return		int				0 or the difference between 2 characters.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
*	This functions searchs the first occurence of c in the string s
*	and returns its position in the string, or NULL if nothing was
*	found. It deals with unicode characters as c is cast as unsigned char.
*
*	@param		const char *s	The string we want to search in.
*	@param		int c			The character we want to find.
*	@return		char *			The address of the position of the char
*								in the string, or NULL if not found.
*/
char	*ft_strchr(const char *s, int c);

/**
*	This functions searchs the last occurence of c in the string s
*	and returns its position in the string, or NULL if nothing was
*	found. It deals with unicode characters as c is cast as unsigned char.
*
*	@param		const char *s	The string we want to search in.
*	@param		int c			The character we want to find.
*	@return		char *			The address of the position of the char
*								in the string, or NULL if not found.
*/
char	*ft_strrchr(const char *s, int c);

/**
*	This function takes a string as a parameter and returns its length.
*
*	@param		const char *s	The string we want to retrieve the length from.
*	@return		size_t			The length of the string.
*/
size_t	ft_strlen(const char *s);

/**
*	This function takes an array as a parameter and returns its length.
*
*	@param		char **tab		The array we want to retrieve the length from.
*	@return		size_t			The length of the array.
*/
size_t	ft_tablen(char **tab);

/**
*	This functions sets n bytes in s with c.
*
*	@param		void *s			The address of the first element we want to set.
*	@param		int c			The value we want to set for each element.
*	@param		size_t n		The number of elements we want to set.
*	@return		void *			s.
*/
void	*ft_memset(void *s, int c, size_t n);

/**
*	This functions works like ft_memset except it fills each element with 0.
*
*	@param		void *s			The address of the first element we want to set.
*	@param		size_t n		The number of elements we want to set.
*/
void	ft_bzero(void *s, size_t n);

/**
*	This function copies n bytes for the memory area pointed to by src
*	into the memory area pointed to by dest.
*
*	@param		void *dest		The address of the first element we want to
*								copy in.
*	@param		void *src		The address of the first element we want to
*								copy from.
*	@return		void *			dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
*	This function copies n bytes for the memory area pointed to by src
*	into the memory area pointed to by dest. This functions deals with
*	overlapping memory.
*
*	@param		void *dest		The address of the first element we want to
*								copy in.
*	@param		void *src		The address of the first element we want to
*								copy from.
*	@return		void *			dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
*	This functions looks for the first occurence c in the first n bytes of s.
*	It returns a pointer to the found element or NULL if nothing was found.
*
*	@param		const void *s	The first address of the memory area
*								we want to look in.
*	@param		int c			The value we want to look for.
*	@param		size_t n		The maximum number of element we want
*								to check.
*	@return		void *			The address of the found element or NULL.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
*	This function compares the n first bytes of thetwo memory areas 
*	pointed to by s1 and s2. It return ether the difference between 
*	two different bytes or 0 if no difference was found.
*
*	@param		const void *s1	The first memory area to compare.
*	@param		const void *s2	The second memory area to compare.
*	@param		size_t n		The number of bytes we want to check.
*	@return		int				The difference between two bytes or 0.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
*	This function looks for little string in the big string in the n
*	first bytes, and return the pointer to the begining of the matched
*	strings.
*
*	@param		const char *big		The big string we want to look in.
*	@param		const char *little	The little string we want to look for.
*	@param		size_t	len			The maximum number of bytes we want ti check.
*	@return		char *				The pointer to 
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
*	This function takes a string as a parameter and returns the number
*	represented by the string.
*
*	@param		const char *nptr	The string representing the number.
*	@return		int					
*/
int		ft_atoi(const char *nptr);

/**
*	This function takes a string as a parameter and returns the number
*	represented by the string.
*
*	@param		const char *nptr	The string representing the number.
*	@return		long					
*/
long	ft_atol(const char *nptr);

/**
*	This function dynamicaly allocate memory, and fills it with 0. It
*	makes sure the total amount of bytes we want to allocate is within
*	reasonable range IE. does not go beyond unsined long long.
*
*	@param		size_t nmemb	The number of element we want to allocate.
*	@param		size_t	size	The size of one element.
*	@return		void *			A pointer to the first element, or NULL.
*/
void	*ft_calloc(size_t nmemb, size_t size);

/**
*	This function takes a string as an arguement an returns a duplicate
*	of it that we can later free. Or NULL if something went wrong.
*
*	@param		const char *s	The string to duplicate.
*	@return		char *			The duplicate string or NULL.
*/
char	*ft_strdup(const char *s);

/**
*	This function copies up to size bytes from src into dest, it is 
*	safer then strcpy and strncpy as it assures to null terminate
*	dest. src as to be null terminated as well.
*
*	@param		char *dest		The string we want to copy in.
*	@param		const char *src	The string we want to copy from.
*	@param		size_t size		The maximum number of bytes to copy.
*	@return		size_t			The length of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
*	This function copies up to size bytes from src into dest, starting
*	from the end of dest. It is safer then strcat and strncat as it
*	assures to null terminate dest. Both src and dst need to be null
*	terminated to begin with.
*
*	@param		char *dst		The string we want to copy in.
*	@param		const char *src	The string we want to copy from.
*	@param		size_t size		The maximum number of bytes to copy.
*	@return		size_t			The length of the string it tried to create.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
*	This function extract a part of the string s and returns it.
*	The returned string can be freed.
*
*	@param		const char *s		The string we want to extract from.
*	@param		unsigned int start	The index we want to start from.
*	@param		size_t len			The length of the substring.
*	@return		char *				The substring or NULL.
*/
char	*ft_substr(const char*s, unsigned int start, size_t len);

/**
*	This function takes two strings and returns a new string containing
*	the two strings concatenated.
*
*	@param		const char *s1	The first string to join.
*	@param		const char *s2	The second string to join.
*	@return		char *			The new string or NULL.
*/
char	*ft_strjoin(const char *s1, const char *s2);

/**
*	This function trims the given string s1 with the set of character set
*	and returns the new string created.
*
*	@param		const char *s1	The string to be trimmed.
*	@param		const char *set	The set of character to check.
*	@return		char *			The trimmed string or NULL.
*/
char	*ft_strtrim(const char *s1, const char *set);

/**
*	This function takes a string s as parameter and split it into
*	an array of string, each string divided by c.
*
*	@param		const char *s	The string to split.
*	@param		char c			The divider.
*	@return		char **			An array of string, or NULL.
*/
char	**ft_split(const char *s, char c);

/**
*	This function is like ft_atoi, but in reverse.
*
*	@param		int n		The number to transform.
*	@return		char *		The string representing the number.
*/
char	*ft_itoa(int n);

/**
*	This function takes a string as a parameter, and map it with the
*	given function f. The new string creating is then returned.
*
*	@param		const char *s	The string to be mapped.
*	@param		char (*f)(unsigned int, char)	The pointer to function
*								used to map s.
*	@return		char *			The mapped string, or NULL.
*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
*	This function iterates throught s and calls f for each character.
*
*	@param		char *s		The string to iterate on.
*	@param		void (*f)(unsigned int, char *)	The pointed to function
*							used on each element.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
*	This functions prints a character on the given file descriptor.
*
*	@param		char c		The character to be printed.
*	@param		int fd		The file descriptor to print on.
*	@return		int			Numbers of characteres printed.
*/
size_t	ft_putchar_fd(char c, int fd);

/**
*	This function prints a string on the given file descriptor.
*
*	@param		char *s		The string to be printed.
*	@param		int fd		The file descriptor to print on.
*	@return		int			Numbers of characteres printed.
*/
size_t	ft_putstr_fd(char *s, int fd);

/**
*	This function prints a string followed by a new line
*	on the given file descriptor.
*
*	@param		char *s		The string to be printed.
*	@param		int fd		The file descriptor to print on.
*	@return		size_t		Numbers of characteres printed.
*/
size_t	ft_putendl_fd(char *s, int fd);

/**
*	This function prints a integer on the given file descriptor.
*
*	@param		int n		The number to be printed.
*	@param		int fd		The file descriptor to print on.
*	@return		size_t		Numbers of characteres printed.
*/
size_t	ft_putnbr_fd(int n, int fd);

/**
*	This function prints an unsigned integer on the given file descriptor.
*
*	@param		unsigned int n	The number to be printed.
*	@param		int fd			The file descriptor to print on.
*	@return		size_t			Numbers of characteres printed.
*/
size_t	ft_putunbr_fd(unsigned int n, int fd);

/**
*	This function prints an unsigned number on the given file descriptor,
*	based on the given base.
*
*	@param		size_t n		The number to be printed.
*	@param		char *base		The base use to transform the number.
*	@param		size_t size		The size of the base.
*	@param		char *base		The file descriptor to print on.
*	@return		size_t			Numbers of characteres printed.
*/
size_t	ft_putnbr_base_fd(size_t n, char *base, size_t size, int fd);

/**
*	This function prints a pointer on the given file descriptor.
*
*	@param		void *p			The pointer to be printed.
*	@param		int fd			The file descriptor to print on.
*	@return		size_t			Numbers of characteres printed.
*/
size_t	ft_putptr_fd(void *ptr, int fd);

/**
*	Utility function used to free array of data.
*
*	@param		void **tab		The array to be freed
*/
void	ft_free_tab(void **tab);

/**
*	==================== LINKED LIST ====================
*	This function create and return a new node, and fills its content
*	with the content passed as a parameter, the content can be anything.
*
*	@param		void *content	The content to put in the node.
*	@return		t_list *		The new node created or NULL.
*/
t_list	*ft_lstnew(void *content);

/**
*	==================== LINKED LIST ====================
*	This function add a node in front of the list.
*
*	@param		t_list **lst	The address of the list to work on.
*	@param		t_list *new		The node to add.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
*	==================== LINKED LIST ====================
*	This function returns the size of a list.
*
*	@param		t_list *lst		The list to work on.
*	@return		int				The size of the list.
*/
int		ft_lstsize(t_list *lst);

/**
*	==================== LINKED LIST ====================
*	This function retrieve the address of the last element in the list.
*
*	@param		t_list *lst		The first element of the list.
*	@return		t_list *lst		The last element of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/**
*	==================== LINKED LIST ====================
*	This function retrieve the address of the element before the last in the list.
*
*	@param		t_list *lst		The first element of the list.
*	@return		t_list *lst		The last element of the list.
*/
t_list	*ft_lstblast(t_list *lst);

/**
*	==================== LINKED LIST ====================
*	This function add a new node to the ebd of the list.
*
*	@param		t_list **lst	The address of the first element of the list.
*	@param		t_list *new		The node to add.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
*	==================== LINKED LIST ====================
*	This function delete one element of the list, without freeing the next one.
*
*	@param		t_list *lst		The node to delete
*	@param		void (*del)(void *)	The pointer to function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
*	==================== LINKED LIST ====================
*	This function clears the entire list pointed to by lst.
*
*	@param		t_list **lst	The address of the first element of the list.
*	@param		void (*del)(void *)	The pointer to function used to delete the content.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
*	==================== LINKED LIST ====================
*	This function iterate of a list and call f with the content of the 
*	node as parameter.
*
*	@param		t_list *lst		The first element of the list.
*	@param		void (*f)(void *)	The pointer to function called
*								for each iteration.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
*	==================== LINKED LIST ====================
*	This function iterate over the list pointed to by lst, and returns a mapped
*	version of it, calling f on the list content for each node it passes throught.
*
*	@param		t_list *lst		The first element of the list we want to map.
*	@param		void *(*f)(void *)	The pointer to function used on a node content.
*	@param		void (*del)(void *)	The pointer to function used to delete
*								the mapped list if something went wrong.
*	@return		t_list *		The new list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
*	This function is a cheap knock-off of the real printf function
*	it handles the following flags c,s,d,u,i,p,x,X and %.
*
*	@param		const char *format	The format of the string we want to display.
*	@param		...					The variadic parameters
*	@return		int					The number of characters printed.
*/
int		ft_printf(const char *format, ...);

/**
*	This function is used to retrieve the next line of any file (or the first one
*	if it's the first call to this function)
*
*	@param		int fd			The file descriptor to retrieve the line from.
*	@return		char *			The line it read or NULL if there was nothing to read.
*/
char	*get_next_line(int fd);

/**
*	This function is used to retrieve the next line of any file (or the
*	first one if it's the first call to this function).
*	The diffrerence between get_next_line and get_next_line_multiple 
*	is that the last one can handle up to 1024 file at the same time,
*	without creating a conflict between them.
*
*	@param		int fd			The file descriptor to retrieve the line from.
*	@return		char *			The line it read or NULL if there was nothing to read.
*/
char	*get_next_line_multiple(int fd);

/**
*	Set of utility functions for get_next_line and get_next_line_multiple
*/
char	*ft_gnl_read(int fd, char *content);
char	*ft_gnl_extract_line(char *content);
char	*ft_gnl_remove_line(char *content);
#endif
