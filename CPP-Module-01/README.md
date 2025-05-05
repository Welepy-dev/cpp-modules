# CPP Module 01

## EX 00
For this assignment it was asked to us to implement a zombie and it has to announce itself.

After it, we nned to create two functions:

```Zombie* newZombie( std::string name );```

```void randomChump( std::string name );```

And finnaly for debugging porpuses it has to show a message when a zombie is destroyed which is quite easy, you just need to leave a message in the destructor.

This exercise it to teach us the difference between allocating in the stack vs. the heap.

Allocating in the stack means storing data in a region of memory that's fast and automatically managed. It's used for temporary data like function parameters and local variables. When a function ends, its stack data is automatically removed.

Allocating in the heap means storing data in a region of memory that's manually managed. It's used for dynamic memory—like objects or data structures whose size or lifetime isn’t known at compile time. You must explicitly allocate and free this memory.

## EX 01

For this one, it was asked to us to create a function that returns a pointer to the first position of an array. The function must allocate N number of Zombies and assign to each Zombies the name passed as paramenter:

```Zombie* zombieHorde(int N, std::string name);```

Everything is the same as the previous assignment but for the function you just need to create a collection of instances of the Zombie class with ```new``` keyword, and use a loop to set the name to each instance.

# EX 02

This assignment was made to learn what a reference and a pointer is.
pointers are a concept learnt with C and their definition didnt change.
while pointers are variables that store the addres of the variable they are pointing to.
references are like aliases for existing variables.
when declaring a reference like:
int &ref = a;
a and ref both refer to the same thing so it means that if we alter one, it changes the value for "both", it is kind confusing so this picture may explain better:
![alt text](references.png)

## EX 03

In this assignment we will implement references.
We will implement a Weapon class with a attribute ```type``` which is a string.
Two member functions:
``` getType()```
``` setType()```
to get and set the weapon type.

