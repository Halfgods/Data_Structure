#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 2048

typedef struct {
    int key;     // nums[i]
    int value;   // index i
} Entry;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    Entry* table[TABLE_SIZE] = {NULL};

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = hash(complement);

        while (table[idx] != NULL) {
            if (table[idx]->key == complement) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = table[idx]->value;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
            idx = (idx + 1) % TABLE_SIZE;  // Linear probing
        }

        // Insert current value
        int insertIdx = hash(nums[i]);
        while (table[insertIdx] != NULL) {
            insertIdx = (insertIdx + 1) % TABLE_SIZE;
        }

        table[insertIdx] = (Entry*)malloc(sizeof(Entry));
        table[insertIdx]->key = nums[i];
        table[insertIdx]->value = i;
    }

    *returnSize = 0;
    return NULL;
}