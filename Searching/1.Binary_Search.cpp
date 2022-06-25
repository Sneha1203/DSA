int iterativeBS (int arr[], int size, int key) {
    int start = 0;
    int end = size;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int recursiveBS (int arr[], int start, int end, int key) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid]) 
        return recursiveBS (arr, start, mid - 1, key);
    else 
        return recursiveBS (arr, mid + 1, end, key);
}
