This repo is my initial attempt at implementing a few data structures
from scratch with a few weeks of C programming knowledge. I'll be 
implementing the following simple data structures and their operations
with focus being on getting the work done and not aiming for the most
efficient or fastest implementation yet.

With that said I may come back periodically or will be updating the repo
with more data structures and as time goes I might be updating the old
implementations.

I'll be working on the following data structures as a start and we'll
see how far this goes!

Stack
    The stack is a data type that works on the principle of First In,
    First Out which means items are "stacked" on top of each other like
    plates. This makes the first item in the Stack fall to the bottom
    of the List and the last item on top of the Stack.
    This is useful for implementing something like a simple undo tree
    where actions done are stacked on top of previous ones and can be
    undone by popping the first elements.
    I'll be implementing the following basic features of the Stack data
    structure
        * Push      -   This operation adds an item on top of the stack
        * Pop       -   This operation removes an item from the top of
                        the stack and returns it
        * Peek      -   This operation returns the item at the item a the
                        top of the stack without removing it
        * IsEmpty   -   This checks if there are still elements in the
                        Stack
        * Init      -   This operation initialises a new Stack


Dictionary
    THe dictionary is a data structure that works through a key-value
    pair system where keys are unique values that act as retrieval 
    points for the associated value. It is a provides a good way to 
    search and retrieve data only from its key.
    A useful implementation of Dictionary is using it in a real world
    Dictionary implementation or for storing students names and their
    scores in a school grading system.
    I'll be implementing the following basic features of the Dictionary
    data structure
        * Insert    -   This operation adds a new entry into the Dictionary
                        data structure. Before an entry is added we make
                        sure that its key is unique otherwise we don't add
        * Delete    -   This operation removes an entry from the Dictionary
                        by based on the key of the item
        * Search    -   This operation searches the entire Dictionary struct
                        for a value based on a key provided
        * Clear     -   This operation removes every entry in the structure
                        for easy reusability
        * Update    -   This operation allows changing the value of the key
                        provided so without needing to modify the entire
                        structure. This also saves on memory
