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