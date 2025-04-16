# CPP-Modules
These are 42's modules to learn C++ concepts

## C++ Module 00

This is an introductory module to get familiarized with the C++ language.

### ex00

Here we get introduced to objects, objects data fields, much like structs that can store variables, these are called attributes, also like structs, objects can have functions, these are called methods, different from structs, classes allow us to encapsulate behaviour and abstract complexity (more on that on the next modules).
In this exercise I used ```cout``` which is an object that describes the console output.

This is what the subject assigned to me:

Write a program that produces the this behaviour:
```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

This is quite simple, we just traverse the strings of passed by the command line arguments, check if there are lowercase characters, if so, turn them uppercase.