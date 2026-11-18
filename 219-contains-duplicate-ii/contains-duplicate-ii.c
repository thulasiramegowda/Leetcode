bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    typedef struct {
        int key;
        int index;
        int used;
    } Entry;

    if (k == 0 || numsSize < 2) {
        return false;
    }

    int size = 1;
    while (size < numsSize * 2) {
        size *= 2;
    }

    Entry* table = calloc(size, sizeof(Entry));

    if (table == NULL) {
        return false;
    }

    for (int i = 0; i < numsSize; i++) {
        unsigned int h = ((unsigned int)nums[i] * 2654435761u) & (size - 1);

        while (table[h].used && table[h].key != nums[i]) {
            h = (h + 1) & (size - 1);
        }

        if (table[h].used && i - table[h].index <= k) {
            free(table);
            return true;
        }

        table[h].key = nums[i];
        table[h].index = i;
        table[h].used = 1;
    }

    free(table);
    return false;
}