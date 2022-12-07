#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
int main() {
queue q;
int i;
q = queue_create();
assert(queue_is_empty(q));
for(i = 0; i < 10000; i++) {
queue_push(q, i);
assert(queue_first(q) == 0);
}
assert(queue_size(q) == 10000);
assert(!queue_is_empty(q));
for(i = 0; i < 10000; i++) {
assert(queue_pop(q) == i);
}
assert(queue_is_empty(q));
assert(queue_size(q) == 0);
queue_destroy(q);
}