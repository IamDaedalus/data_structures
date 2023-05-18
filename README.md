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
