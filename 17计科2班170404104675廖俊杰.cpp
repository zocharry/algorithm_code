#include<iostream>
using namespace std;

int BinarySearchRecursive(int *array, int low, int high, int key)
{
    if ( low > high )
        return -1;
    int mid = ( low + high )/2;

    if ( array[mid] == key )
        return mid;
    else if ( array[mid] < key )
        return BinarySearchRecursive(array, mid+1, high, key);
    else
        return BinarySearchRecursive(array, low, mid-1, key);
}
int main()
{
    int array[10];
    for (int i=0; i<10; i++)
        array[i] = i;

    cout<<"结果:第"<<BinarySearchRecursive(array, 0, 9, 6)<<"个"<<endl;

    return 0;
}

