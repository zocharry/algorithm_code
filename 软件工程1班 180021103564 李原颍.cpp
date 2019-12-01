Int BinarySearch(Type a[],const Type& x,int n)
{    
      Int left=0;int right = n-1;
While(left<right){
   If(x==a[middle]) return middle;
   If(x>a[middle]) left= middle+1;
   Else right =middle-1;
}
return -1;
}

