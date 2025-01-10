#include "unity.h"

void setUp(void) {};
void tearDown(void) {};

void run_SimpleObjectPool(void);

int main(void) {
    UNITY_BEGIN();

    run_SimpleObjectPool();

    return UNITY_END();
}