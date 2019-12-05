#include <stdio.h>
#include <stdlib.h> 
typedef int ElementType; 
typedef struct 
{
    int element[16];
    int length;
}StaticTable;
int BinarySearch(StaticTable* Tbl, ElementType K)
{
    int left, right, mid, NotFound = -1;
    left = 1;                
    right = Tbl->length;    
    while (left <= right)
    {
        mid = (left + right) / 2;            
        if (K < Tbl->element[mid]) right = mid - 1;       
        else if (K > Tbl->element[mid]) left = mid + 1;    
        else    return mid;        
    }
    return NotFound;        
}
int Index(StaticTable *Tbl, ElementType K)
{ 
    int i ;
    Tbl->element[0] = K;
    for (i = Tbl->length; Tbl->element[i] != K; i--);
    return i;
} 
int main()
{
    StaticTable * Tb1 = (StaticTable*)malloc(sizeof(StaticTable));
    Tb1->length = 15;
    for (int i = 1; i < 16; i++)
    {
        Tb1->element[i] = i;
    }
    int index1 = BinarySearch(Tb1, 15);
    printf("%d\n", index1);
    int index2 = Index(Tb1, 5);
    printf("%d\n", index2);
    return 0;
}
