# Libft - @42Born2Code
My implementation of some of the Standard C Library functions and some additional ones.

### TOC
* [What is libft?](#what-is-libft)
* [What's in it?](#whats-in-it)

### What is libft?
[Libft][1] is an individual project at [42][2] that requires us to re-create some of the standard C library functions, and some additional ones, to build our own library that can be used in all our future 42 projects.

Disclaimer: *As a freshman and an overall rookie in programming, my implementation will obviously not be the best, but 42 make us do this just so we can have a deeper understanding of data structures and basic algorithms. Plus, at 42 we're not allowed to use almost any standard library function in our projects, so we have to keep growing this library with our own, in order to not have to code everything from scratch every single time.*

### What's in it?

As you can see from the [Project instructions][1], there are 3 sections:

1.  **Libc functions:** Some of the standard C functions, I've marked them with an (L) next to their name.
2.  **Additional functions:** Functions 42 deems will be useful for later projects, I've marked them with an (A) next to their name.
3.  **Bonus functions:** Linked list manipulation functions 42 deems will be useful, I've marked them with a (B) next to their name.
4. **Projects functions:** These are 42 projects by themselves, asking us to either recode an existing function or group of functions, or create a new one. They're marked with a (P) next to their name and their documentation can be accessed from the PDF located in the projects_instructions folder.
5.  All the other functions are personal functions, their documentation can be checked on the [wiki][3], and they're not marked.

API functions | Character functions | IO functions | Linked List functions | Memory functions | String functions
:----------- | :-----------: | :--------------: | ------------: | :------------: | ------------:
ft_getenv	 | ft_isalnum(L) | ft_asprintf(P)	|
ft_setenv	 | ft_isalpha(L) | ft_dprintf(P)	|
ft_unsetenv	 | ft_isascii(L) | ft_kill			|
| ft_isdigit(L)	| ft_printf(P)		|
| ft_islower	| ft_putchar(A)		|
| ft_isprint(L) | ft_putchar_fd(A)	|
| ft_isupper	| ft_putendl(A)		|
| ft_tolower(L) | ft_putendl_fd(A)	|
| ft_toupper(L) | ft_putnbr(A)		|
|| ft_putnbr_fd(A)	|
|| ft_putstr(A)		|
|| ft_putstr_fd(A)	|
|| ft_snprintf(P)	|
|| ft_sprintf(P)	|
|| ft_vasprintf(P)	|
|| ft_vdprintf(P)	|
|| ft_vprintf(P)	|
|| ft_vsnprintf(P)	|
|| ft_vsprintf(P)	|
|| get_next_line(P)	|


Notes:

- Most of the files and function names are namespaced with a **ft** in front. It stands for Fourty Two.
- The project instructions require that we put all the source files in the root directory, but for the sake of readability, I organized them into different directories matching their class (ie. libc function, personal function, etc.).
- You can run a "make" to create a static library, and a "make so" to create a shared library.
- This repository shall be updated everytime there is a function I deem useful to be added to the library. If you don't know what a function does, refer to the [Project instructions][1] for additional and bonus functions, or the [Wiki][3], where I document all the personal ones.

[1]: https://github.com/jon-finkel/libft/blob/master/projects_instructions/libft.en.pdf "Libft PDF"
[2]: http://42.us.org "42 Silicon Valley"
[3]: https://github.com/jon-finkel/libft/wiki
