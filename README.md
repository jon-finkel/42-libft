# Libft - @42Born2Code
My implementation of some of the Standard C Library functions and some additional ones.

### TOC
* [What is libft?](#what-is-libft)
* [What's in it?](#whats-in-it)

### What is libft?
[Libft][1] is an individual project at [42][2] that requires us to re-create some of the standard C library functions, and some additional ones, to build our own library that can be used in all our future 42 projects.

Disclaimer: *As a freshman and an overall rookie in programming, my implementation will obviously not be the best, but 42 make us do this just so we can have a deeper understanding of data structures and basic algorithms. Plus, at 42 we're not allowed to use almost any standard library function in our projects, so we have to keep growing this library with our own, in order to not have to code everything from scratch every single time.*

### What's in it?

As you can see from the [Project instructions][1], there are 4 sections:

1.  **Libc Functions:** Some of the standard C functions.
2.  **Additional functions:** Functions 42 deems will be useful for later projects.
3.  **LinkedList Functions:** Linked list manipulation functions 42 deems will be useful, plus few of my owns.
4.  **Personal Functions:** Functions I made that are or will be useful to me. [Documented here][3].

Libc functions | Additional functions | LinkedList functions | Personal functions
:----------- | :-----------: | :-----------: | -----------:
atoi		 |	ft_itoa		 |	ft_lstadd	 |	ft_dprintf
bzero		 |	ft_memalloc	 |	ft_lstclear	 |	ft_intlen
isalnum		 |	ft_memdel	 |	ft_lstdel	 |	ft_isinvert
isalpha		 |	ft_putchar	 |	ft_lstdelone |	ft_islower
isascii		 |	ft_putchar_fd|	ft_lstgetnode|	ft_isupper
isdigit		 |	ft_putendl	 |	ft_lstiter	 |	ft_kill
isprint		 |	ft_putendl_fd|	ft_lstmap	 |	ft_printf
memccpy		 |	ft_putnbr	 |	ft_lstnew	 |	ft_putuchar
memchr		 |	ft_putnbr_fd |	ft_lstsize	 |	ft_putuchar_fd
memcmp		 |	ft_putstr	 |	|	ft_snprintf
memcpy		 |	ft_putstr_fd |	|	ft_sprintf
memmove		 |	ft_strclr	 |	|	ft_strrev
memset		 |	ft_strdel	 |	|	ft_strrevcpy
strcat		 |	ft_strequ	 |	|	ft_vdprintf
strchr		 |	ft_striter	 |	|	ft_vprintf
strcmp		 |	ft_striteri	 |	|	ft_vsnprintf
strcpy		 |	ft_strjoin	 |	|	ft_vsprintf
strdup		 |	ft_strmap	 |	|	get_next_line
strlcat		 |	ft_strmapi	 |	|
strlen		 |	ft_strnequ	 |	|
strncat		 |	ft_strnew	 |	|
strncmp		 |	ft_strsplit	 |	|
strncpy		 |	ft_strsub	 |	|
strnstr		 |	ft_strtrim	 |	|
strrchr		 |	|	|
strstr		 |	|	|
tolower		 |	|	|
toupper		 |	|	|


Notes:

- Most of the files and function names are namespaced with a **ft** in front. It stands for Fourty Two.
- The project instructions require that we put all the source files in the root directory, but for the sake of readability, I organized them into different directories matching their class (ie. libc function, personal function, etc.).
- You can run a "make" to create a static library, and a "make so" to create a shared library.
- This repository shall be updated everytime there is a function I deem useful to be added to the library. If you don't know what a function does, refer to the [Project instructions][1] for additional and bonus functions, or the [Wiki][3], where I document all the personal ones.

[1]: https://github.com/jon-nimrod/42-libft/blob/master/projects_instructions/libft.en.pdf "Libft PDF"
[2]: http://42.us.org "42 Silicon Valley"
[3]: https://github.com/jon-nimrod/42-libft/wiki
