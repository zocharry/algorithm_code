 #include <iostream>  
  
using namespace std;

//二分搜索
int BinarySearch(int *array, int aSize, int n)//输入数组、数组大学、查找值
{

    if ( array == NULL || aSize == 0 )//如果数组为空则返回-1
        return -1;

    int left = 0;
    int right = aSize - 1;
    int mid = 0;

    while ( left <= right )
    {
        mid = (left + right )/2;

        if ( array[mid] < n)//如果n大于mid则查找右侧部分 
            left = mid + 1;
        else if ( array[mid] > n )//如果n小于mid则查找左侧部分 
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int array[10];
    for (int i=0; i<10; i++)
        array[i] = i;

    cout<<"位置在:"<<BinarySearch(array, 10, 6)<<endl;

    return 0;
}
