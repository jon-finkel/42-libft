# Libft - @42Born2Code
My implementation of some of the Standard C Library functions and some additional ones.

### TOC
* [What is libft?](#what-is-libft)
* [What's in it?](#whats-in-it)

### What is libft?
[Libft][1] is an individual project at [42][2] that requires us to re-create some of the standard C library functions, and some additional ones, to build our own library that can be used in all our future 42 projects.

Disclaimer: *As a freshman and an overall rookie in programming, my implementation will obviously not be the best, but 42 make us do this just so we can have a deeper understanding of data structures and basic algorithms. Plus, at 42 we're not allowed to use almost any standard library function in our projects, so we have to keep growing this library with our own, in order to not have to code everything from scratch every single time.*

### What's in it?

As you can see from the [project instructions][1], there are 3 sections:

1.  **Libc functions:** Some of the standard C functions, I've marked them with an (L) next to their name.
2.  **Additional functions:** Functions 42 deems will be useful for later projects, I've marked them with an (A) next to their name.
3.  **Bonus functions:** Linked list manipulation functions 42 deems will be useful, I've marked them with a (B) next to their name.
4. **Projects functions:** These are 42 projects by themselves, asking us to either recode an existing function or group of functions, or create a new one. They're marked with a (P) next to their name and their documentation can be accessed from the PDF located in the projects_instructions folder.
5.  All the other functions are personal functions, their documentation can be checked on the [wiki][3], they're not marked, except for some that are modified versions of some libraries functions and share the same name, which are marked with an (~).

String functions | IO functions | Memory functions | Linked List functions | Character functions | API functions
:-----------: | :-------------: | :-----------: | :------------: | :-----------: | :-----------:
ft_atoi(L)	  | ft_asprintf(P)	| ft_bzero(L)	| ft_lstadd(B)	 | ft_isalnum(L) | ft_ctime(~)
ft_intlen	  | ft_dprintf(P)	| ft_cleanup	| ft_lstappend	 | ft_isalpha(L) | ft_getenv(~)
ft_itoa(A)	  | ft_fatal		| ft_memalloc(A)| ft_lstdel(B)	 | ft_isascii(L) | ft_setenv(~)
ft_strcat(L)  | ft_perror(~)	| ft_memccpy(L)	| ft_lstdelone(B)| ft_isdigit(L) | ft_unsetenv(~)
ft_strchr(L)  | ft_printf(P)	| ft_memchr(L)	| ft_lstfree	 | ft_islower	 |
ft_strclr(A)  | ft_putchar(A)	| ft_memcmp(L)	| ft_lstgetnode	 | ft_isprint(L) |
ft_strcmp(L)  | ft_putchar_fd(A)| ft_memcpy(L)	| ft_lstiter(B)	 | ft_isupper	 |
ft_strcpy(L)  | ft_putendl(A)	| ft_memdel(A)	| ft_lstmap(B)	 | ft_tolower(L) |
ft_strdel(A)  | ft_putendl_fd(A)| ft_memmove(L)	| ft_lstnew(B)	 | ft_toupper(L) |
ft_strdup(L)  | ft_putnbr(A)	| ft_memnccpy	| ft_lstsize	 |
ft_strequ(A)  | ft_putnbr_fd(A)	| ft_memset(L)	| ft_lstsnipe	 |
ft_striter(A) | ft_putstr(A)	| ft_realloc(~)	|
ft_striteri(A)| ft_putstr_fd(A)	|
ft_strjoin(A) | ft_snprintf(P)	|
ft_strlcat(L) | ft_sprintf(P)	|
ft_strlen(L)  | ft_vasprintf(P)	|
ft_strmap(A)  | ft_vdprintf(P)	|
ft_strmapi(A) | ft_vprintf(P)	|
ft_strncat(L) | ft_vsnprintf(P)	|
ft_strncmp(L) | ft_vsprintf(P)	|
ft_strncpy(L) | get_next_line(P)|
ft_strnequ(A) |
ft_strnew(A)  |
ft_strnstr(L) |
ft_strrchr(L) |
ft_strrev	  |
ft_strrevcpy  |
ft_strrewrite |
ft_strsplit(A)|
ft_strstr(L)  |
ft_strsub(A)  |
ft_strtrim(A) |

Notes:

- Most of the files and function names are namespaced with a **ft** in front. It stands for Fourty Two.
- The project instructions require that we put all the source files in the root directory, but for the sake of readability, I organized them into different directories matching their class (ie. libc function, personal function, etc.).
- You can run a "make" to create a static library, and a "make so" to create a shared library.
- This repository shall be updated everytime there is a function I deem useful to be added to the library. If you don't know what a function does, refer to the [Project instructions][1] for additional and bonus functions, or the [Wiki][3], where I document all the personal ones.

[1]: https://github.com/jon-finkel/libft/blob/master/projects_instructions/libft.en.pdf "Libft PDF"
[2]: http://42.us.org "42 Silicon Valley"
[3]: https://github.com/jon-finkel/libft/wiki
