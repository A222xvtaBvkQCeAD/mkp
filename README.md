# mkp
Multiple Knapsack Problem

This program uses an evolutionary algorithm to solve the multiple knapsacks problem (MKP). In this problem, *n* items, each with weights *w<sub>i</sub>* and values *v<sub>i</sub>*, are packed into a set of *K* knapsacks, each of which has capacity *C*. The goal of the problem is to pack the items such that the value contained in the set of knapsacks is maximized while ensuring that the weight does not exceed the capacity of any of the knapsacks. As a trivial example, suppose that there are two knapsacks, each with a maximum capacity of 5, and four items with (weight, value) pairs of *I<sub>1</sub>* = (5, 16), *I<sub>2</sub>* = (5, 20), *I<sub>3</sub>* = (2, 10), *I<sub>4</sub>* = (2, 12). One way to pack the items into the knapsack is to put *I<sub>1</sub>* into the first knapsack and *I<sub>2</sub>* into the second, in which case the knapsacks contain a total value of 36. However, if *I<sub>2</sub>* is packed in one knapsack, and items *I<sub>3</sub>* and *I<sub>4</sub>* are packed in the other, the total value is 42.

Solutions to the MKP are encoded using a string of *n* integers from 0 to *K*. Each integer's position is associated with an item, and the value of an integer determines which knapsack the item is assigned to. A value of 0 means an item is not included in any knapsack; any other value from 1 to *K* represents the knapsack the item is assigned to. For example, the string 302 means that item 1 is assigned to knapsack 3, item 2 is not assigned to any knapsack, and item 3 is assigned to knapsack 2.

The algorithm solves the MKP by reading in a list of (weight, value) pairs from a file, where each pair represents an item. The initial population is then established by randomly generating chromosome strings and assigning items to knapsacks accordingly. Once the initial population has been established, each generation evolves in the same way: two parents are selected, two children are created from recombinationl, and both children have a chance for mutation to occur. When there are as many children as the previous generation, the parent generation is replaced with the child generation and the process repeats.
