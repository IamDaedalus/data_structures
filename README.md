# Data Structures Implementation

This repository contains my initial attempt at implementing a few data structures from scratch using my limited knowledge of C programming. The focus is on getting the work done rather than aiming for the most efficient or fastest implementation. As a restriction, I am implementing each data structure with a maximum of 2048 entries to keep the scope manageable and focus on achieving results.

I may periodically update the repository with more data structures or improve the existing implementations as I gain more experience.

## Stack

The stack is a data structure that follows the principle of First In, First Out (FIFO), similar to stacking plates. The first item pushed into the stack falls to the bottom, and the most recently added item is on top. It is commonly used in scenarios like implementing an undo feature or managing function call stacks.

I'll be implementing the following basic features for the Stack data structure:
- Push: Add an item to the top of the stack.
- Pop: Remove and return the item from the top of the stack.
- Peek: Return the item at the top of the stack without removing it.
- IsEmpty: Check if the stack is empty.
- Init: Initialize a new stack.

## Dictionary

The dictionary (also known as a map or associative array) is a data structure that stores unique key-value pairs. It provides efficient retrieval of values based on their associated keys. It is commonly used for tasks like implementing a dictionary or storing data with key-based access.

I'll be implementing the following basic features for the Dictionary data structure:
- Insert: Add a new entry into the dictionary. Entries are only added if the key is unique.
- Delete: Remove an entry from the dictionary based on the key.
- Search: Search the dictionary for a value based on a provided key.
- Clear: Remove all entries from the dictionary for easy reusability.
- Update: Change the value associated with a given key without modifying the entire dictionary structure.

Please note that the implementations may not be the most efficient or optimized, as the main goal is to focus on progress and results rather than the intricacies of performance.

Feel free to explore the implementations and contribute improvements or additional data structures to the repository.
