#include<stdio.h>
#define ElemType int
typedef struct
{
	ElemType data[MaxSize];//顺序表元素
	int length;            //顺序表当前长度 
}SqList;

Status InitList(SqList &L)
{
	memset(L.data,0,sizeof(L));//初始化数据为0
	L.length=0;                //初始化长度为0
	return 0;
}

bool CreatList(SqList &L,int n)
{
	if(n<0||n>MaxSize)false;//n非法
	for(int i=0;i<n;i++){
		scanf("%d",&L.data[i]);
		L.length++;
	}
	return true;
}

//二分查找函数

int Binary_search(SqList L,ElemType key)
{
	int low = 0;int mid = 0;int high = L.length-1;
	while(low<=high)
	{
		mid = (low+high)/2;
 		if(key==L.data[mid]){
			return mid;
		}
		else if(key>L.data[mid]){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return -1;
}

void Create(SqList &L)
{
	int n;bool flag;
	printf("请输入要创建的顺序表长度(>1):");
	scanf("%d",&n);
	printf("请输入%d个数（空格隔开）:",n);
	flag=CreatList(L,n);
	if(flag){
		printf("创建成功！\n");
		PrintList(L);
	}
	else printf("输入长度非法！\n");
}

void SelectSort(SqList &L)
{
	int min;int temp;
	for(int i=0;i<L.length;i++){
		min=i;
		for(int j=i+1;j<L.length;j++){
			if(L.data[j]<L.data[min])min=j;
		}			
		if(min!=i){
			temp=L.data[min];
			L.data[min]=L.data[i];
			L.data[i]=temp;
		}
	}
}

void Binary(SqList L){
	int key;int place;
	SelectSort(L);       //二分查找前先排序
	PrintList(L);
	printf("请输入要查找的值：\n");
	scanf("%d",&key);
	place=Binary_search(L,key);
	if(place>=0)printf("位置（从0起）为：%d\n",place);
	else printf("未找到！\n");
}			

int main(){
    SqList L;
	int choice;
    InitList(L);
    Search(L);break;
    PrintList(L);break;
    Binary(L);break;
    return 0;
}
