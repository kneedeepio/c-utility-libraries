#ifndef C_UTILITY_LIBRARIES_SIMPLE_OBJECT_POOL_H
#define C_UTILITY_LIBRARIES_SIMPLE_OBJECT_POOL_H

# include <stdbool.h>

typedef struct {
    int x;
    int y;
    int z;
} example;

#ifndef POOL_OBJECT
#define POOL_OBJECT example
#endif

typedef struct {
    POOL_OBJECT pool_object;
    bool allocated;
} PoolObject;

#ifndef NUM_POOL_OBJECTS
#define NUM_POOL_OBJECTS 10
#endif

POOL_OBJECT * borrow_from_pool(void);
void return_to_pool(POOL_OBJECT * object_pointer);
void return_to_pool_slow(POOL_OBJECT * object_pointer);

#endif //C_UTILITY_LIBRARIES_SIMPLE_OBJECT_POOL_H
