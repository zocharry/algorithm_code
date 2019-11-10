#include <iostream>
using namespace std;
template<class Type> 
int BinarySearch(Type a[],const Type&x,int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>a[middle])
			left=middle+1;
		else
			right=middle-1;
	}
	return -1;
}
int main(void)
{
 int a[10], i, n, flag = 0;
 cout << "输入10个整数：" << endl;
 for (i = 0; i < 10; i++)
  cin >> a[i];
 cout << "输入要查找的数：";
 cin >> n;
 for (i = 0; i < 10; i++)
  if (a[i] == n)
  {
   cout << "该数在数组中的下标是：" << i << endl;
   flag = 1;
   break;
  }
  if (!flag)
   cout << "无此数" << endl;
  return 0;
}
