# get_next_line : a 42 school project

DISCLAIMER : THIS CODE WAS MADE USING THE OLD SUBJECT (which was harder than the current one)
IF YOU'RE FROM 42 AND YOU COPY IT, YOU WILL GET AN INSTANT KO (and probably a cheat flag) AS IT WON'T COMPILE SINCE IT DOESN'T HAVE THE SAME PROTOTYPE

This is the project "get_next_line" from 42 school. The goal of this project is to recreate a function that modifies a pointer, giving it the first line from a file the first time you call it, then the second line, etc. This project also introduces us to static variables.
This code has been validated by both correctors and the moulinette, with a 115/100.

Before you take a look at this project, I advise you to search the different notions used for this project : the read function, file descriptors, the -D flag from gcc, macros, and static variables. You can also search more about pointers, it's always a good thing.

# HOW DID I MANAGE TO ACHIEVE THIS PROJECT

Get_next_line asks us to create a function with the following prototype:
int get_next_line(int fd, char** line)
fd correspond to the file descriptor, line is a pointer that can be freed and we're using it to put our line there.
Finally, the return value: 1 if a line has been read, 0 if we reach the end of the file, -1 if there is any error.

I'm going to divide this subject in four parts :
-Error handling
-Reading the line
-Give the line to the pointer, and the rest to our static variable
-Return value

# ERROR HANDLING

The subject tells us to handle some basic errors to avoid segfault, bus error, double free, etc. So, the first step is to list every error that you know when it comes to reading from a file descriptor.

There are 3 of them : fd is equal to -1 (error when opening the file), fd doesn't correspond to any file, and read returns -1.
The first one is very easy to handle, you just have to check if your fd is equal to -1 (or less than 0).
The second one is a little bit trickier. Let's say your function is used with a theorically valid fd (for example, 5), but this fd isn't linked to any file. If you don't manage this case, your function will segfault. A way to handle this case is by reading 0 byte from your file descriptor : if your file descriptor is a good one, read will return 0, which is normal because you just read 0 byte and your "reading pointer" didn't move at all. Else, read will return -1, meaning it's an error and you should return -1.
We'll talk about the third one later, because we won't use read until the second part.

Finally, just to be sure that the function will work perfectly, let's add 2 mores error : if the pointer line doesn't exist (to avoid segfault), and if BUFFER_SIZE is equal or less than 0. BUFFER_SIZE will be used to determine how many bytes you will read on every "read loop", so reading 0 byte will just make an infinite loop, and I don't have to explain why you can't read -1 byte.

# READING THE LINE

We're done with errors, we can move on to the interesting part. First, let's initialize our static variable to NULL. Why ? Because we need this variable to always have some memory in it (with malloc), but because we can't initialize it directly with malloc or ft_strdup, we're going to do do it by checking if the static is equal to NULL, a value that we will never get until the end of the file for sure. Let's also create a temporary char* variable and an int.

So, as we said before, the first time we go into the function, our static variable will be initiaziled with some memory. Notice that I use ft_strdup and not malloc, because I need my variable to have a \0 at the end.
Now, let's head into the "reading loop". It's a function that modifies our static by using the fd to read "BUFFER_SIZE" bytes, putting it into our buffer, and adding it at the end of our static. This part is done by joining the static with the buffer (ft_strjoin), putting it into a temporary variable to free the static before assigning the temporary variable into it, without any memory leaks. The function also returns an int, which is the return value from read : if read returns -1 or 0, there is no need to join our static since we didn't read anything. Plus, if the function returns -1, that is an error case, and we have to return -1 as soon as we're out of the "new_line" function (that's our final error handling we talked about earlier).

Notice that, if the static already has a \n when the function is called, it will skip the loop thanks to ft_strchr.

# ASSIGNING THE LINE TO THE POINTER

The "reading loop" loops until we get a \n (thanks to ft_strchr, we know if we got one), if there's an error (n == -1) or if there's nothing left to read (n == 0).

In the first case, the static may have something after the \n. So we need to extract the line (everything before the \n), and this is where 2 functions are used : ft_substr, which takes a string and returns another one based on the starting position and the length of the final string, and bufL, which is basically a strlen that stops if it reaches a \n. With that, we can take our line into the pointer. The same thing is done to the static variable. Notice that the same thing used in "new_line" is done there : a temporary variable is used to execute ft_substr in order to free the static right after, and assign the final result to it without any memory leak. 

# RETURN VALUE

The return value is simple : if the return from read is greater than 0, it means that a line has been read : we can return 1 and stop there. However, read returned 0, it means we reached the end of file. The static is now useless, so we can free it and assign it the NULL value (for some reason, if we free without assigning it the NULL value, the program may crash) and return 0.

And what about bonuses ?
Well, it's pretty easy : the static variable isn't a char* anymore, but a char**, but you declare it as a char* \[max_fd] (i used 1024 to have enough space, but it's probably too much and it depends of your system). Let's say you static is called s, replace every apparition of s by s\[fd], to keep your text from fd4 into the fourth string, fd5 into fifth string, etc.
That's all you need to do, since you're already using a single static in your mandatory code !

Congratulations, now you know how to do the get_next_line project step by step ! If you have any questions, feel free to send me a message !
