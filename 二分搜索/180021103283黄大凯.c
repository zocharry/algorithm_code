int BinarySearch(int a[], int target, int left, int right)
{
    if(left > right)   goto fail;
    int low = left, high = right, mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (a[mid]==target) return mid;
        if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    fail:
    return -1;
}

