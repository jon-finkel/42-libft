# LIBFT - @42Born2Code
My implementation of some of the Standard C Library functions and some additional ones.

### TOC
* [Why is your coding style so hideous?] (#why-is-your-coding-style-so-hideous)
* [What is libft?](#what-is-libft)
* [What's in it?](#whats-in-it)

### Why aren't you initializing your variables when you declare them ? Why aren't you doing functions with more than 25 lines ? Why aren't you commenting ? Why is your coding style so hideous ?

Meet the [norm][3].
42 explicitely requires us to code a certain way. It's a way that sometimes makes sense, most of the time doesn't, but unfotunately is enforced. It's here to teach new students how to acquire some good practices, like don't make a function that does 35 different things. But it also prevents us from using 'for', 'switch', declaring and initializing variables at the same times (save for statics and constants), and many different things that makes the code readable and maintainable.
Please don't think the code in this repository reflects my own coding practices.

### What is libft?
[Libft][1] is an individual project at [42][2] that requires us to re-create some of the standard C library functions, and some additional ones, to build our own library that can be used in all our future 42 projects.

Disclaimer: *As a freshman and an overall rookie in programming, my implementation will obviously not be the best, but 42 make us do this just so we can have a deeper understanding of data structures and basic algorithms. Plus, at 42 we're not allowed to use almost any standard library function in our projects, so we have to keep growing this library with our own, in order to not have to code everything from scratch every single time.*

### What's in it?

As you can see from the [project instructions][1], there are 3 sections:

1.  **Libc functions:** Some of the standard C functions.
2.  **Additional functions:** Functions 42 deems will be useful for later projects.
3.  **Bonus functions:** Linked list manipulation functions 42 deems will be useful.
4.  All the other functions are personal functions.

Notes:
- Most of the files and function names are namespaced with a **ft** in front. It stands for Fourty Two.
- The project instructions require that we put all the source files in the root directory, but for the sake of readability, I organized them into different directories matching their class (ie. string manipulation, intput output, etc.).
- You can run a "make" to create a static library, and a "make so" to create a shared library.
- This repository shall be updated everytime there is a function I deem useful to be added to the library. If you don't know what a function does, refer to the [Project instructions][1].

### Final Mark

`Libft: 125/100 (MAX GRADE)`

`Get_Next_Line: 125/100 (MAX GRADE)`

`ft_printf: 115/100`

[1]: https://github.com/jon-finkel/libft/blob/master/projects_instructions/libft.en.pdf "Libft PDF"
[2]: http://42.fr "42 Paris"
[3]: https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf
