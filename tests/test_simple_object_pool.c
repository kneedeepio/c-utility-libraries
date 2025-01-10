#include "unity.h"

typedef struct {
    long long x;
    int y;
    char z;
} TestStruct;

#define POOL_OBJECT TestStruct
#define NUM_POOL_OBJECTS 123

#include "simple_object_pool.h"

extern PoolObject * object_pool;

void test_SimpleObjectPool_VerifyObjectPool(void) {
    uintptr_t obj_ptr = (uintptr_t)NULL;
    for (int i = 0; i < NUM_POOL_OBJECTS; i++) {
        obj_ptr = (uintptr_t)object_pool + (i * sizeof(PoolObject));
        TEST_ASSERT(&(object_pool[i]) == obj_ptr);
    }
}

void test_SimpleObjectPool_BorrowAndReturn(void) {
    POOL_OBJECT * po = borrow_from_pool();
    return_to_pool(po);
    TEST_ASSERT(true);
}

void test_SimpleObjectPool_BorrowAndSlowReturn(void) {
    POOL_OBJECT * po = borrow_from_pool();
    return_to_pool_slow(po);
    TEST_ASSERT(true);
}

// Test past the borrow limit

// Test borrowing the max, getting a NULL, returning one, and borrowing one more

void run_SimpleObjectPool(void) {
    RUN_TEST(test_SimpleObjectPool_VerifyObjectPool);
    RUN_TEST(test_SimpleObjectPool_BorrowAndReturn);
    RUN_TEST(test_SimpleObjectPool_BorrowAndSlowReturn);
}
