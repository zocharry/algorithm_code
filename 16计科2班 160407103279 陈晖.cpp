#include<stdio.h>
#include<assert.h>
int binary_search(void*data,int n,int size,void*ele,int(*cmp)(void*,void*))
{
if(n <=0||(*cmp)(ele, data)<0||(*cmp)(data+(n-1)*size, ele)<0){
return-1;
}
int left =0, right = n-1;
int middle;
while(left <= right){
middle =(left + right)/2;
if((*cmp)(ele, data+size*middle)==0){
return middle;
}elseif((*cmp)(data+size*middle, ele)<0){
left = middle +1;
}else{
right = middle -1;
}
}
return-1;
}
int cmp_int(void*a,void*b){
return*(int*)a -*(int*)b;
}
int main()
{
int data[]={1,2,3,4,5,6,7,8,9,10};
int x =3;
int index = binary_search(data,10,sizeof(int),&x, cmp_int);
printf("%d\n", index);// 2
return0;
}

