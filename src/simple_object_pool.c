#include "simple_object_pool.h"

#include <assert.h>

PoolObject object_pool[NUM_POOL_OBJECTS] = {0};

POOL_OBJECT * borrow_from_pool(void) {
    for (int i = 0; i < NUM_POOL_OBJECTS; i++) {
        if(!object_pool[i].allocated) {
            object_pool[i].allocated = true;
            return &(object_pool[i].pool_object);
        }
    }
    return NULL;
}

void return_to_pool(POOL_OBJECT * object_pointer) {
    unsigned int i = ((uintptr_t)object_pointer - (uintptr_t)object_pool) / sizeof(PoolObject);
    assert(&(object_pool[i].pool_object) == object_pointer);
    assert(object_pool[i].allocated);
    object_pool[i].allocated = false;
}

void return_to_pool_slow(POOL_OBJECT * object_pointer) {
    for (int i = 0; i < NUM_POOL_OBJECTS; i++) {
        if (&(object_pool[i].pool_object) == object_pointer) {
            assert(object_pool[i].allocated);
            object_pool[i].allocated = false;
            return;
        }
    }
    assert(false); // Tried to return a pool_object not from the pool.
}
