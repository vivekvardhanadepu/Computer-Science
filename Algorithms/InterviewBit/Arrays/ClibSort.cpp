// You will have to implement a compareFunction. Example shown below. 
    qsort(A, sz, sizeof(int), compareFunction);
    
    // Example of compare function 
    int compareFunction(const void* a, const void* b) {
        int value1 = *((int *)a);
        int value2 = *((int *)b);
        if (value1 < value2) {
            // Return -1 if you want ascending. 1 if you want descending. 
            return -1;
        } else if (value1 > value2) {
            // Return 1 if you want ascending. -1 if you want descending. 
            return 1;
        }
        return 0;
    }

