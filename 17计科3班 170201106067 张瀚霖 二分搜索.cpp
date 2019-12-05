#include <stdio.h>
#include <stdlib.h>
 
#define MAXSIZE 20
typedef int ZHL;
 
typedef int pos;
typedef struct DK *List;
struct DK {
    ZHL bass[MAXSIZE];
    pos Last; 
};

List rinput(); 
pos BinarySearch(List L,ZHL X);
 
int main()
{
    List L;
    ZHL X;
    pos P;
    L=rinput();
    scanf("%d", &X); //输入的个数 
    P=BinarySearch(L,X);
    printf("%d\n", P);
    return 0;
}
 
List rinput(){ //输入的数字 
	int i,n;
	List a;    
	scanf("%d", &n);
	for (i=1;i<=n;i++){
		scanf("%d", &a->bass[i]); 
	}   
	a->Last=n;    
	return a;    
}
 
pos BinarySearch(List L,ZHL X) { //二分搜索代码 
	pos left,right,midth;	
	left=1,right=L->Last;   
	while (left<=right){    
		midth=(left + right)/2;
		if(L->bass[midth]==X) 
			return midth;
		else if(L->bass[midth]>X) 
			right=midth-1;
		else 
			left=midth+1;
	}
		
	return -1;
}

