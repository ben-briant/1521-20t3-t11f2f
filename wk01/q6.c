// Assume that somewhere above this code snippet, we have
// a 'struct node' type, which contains a field 'data'.
// Also assume that the required libraries are #included.

struct node *a, *b, *c, *d;
a = NULL;

// 1. type
// 2. variable

b = malloc(sizeof *b); // Same as malloc(sizeof(struct node));
c = malloc(sizeof(struct node));
d = malloc(8); // Use sizeof, don't give num of bytes directly
c = a;
d->data = 42;
c->data = 42;