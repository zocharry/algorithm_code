package test1;

import java.util.Scanner;

public class test1 {
	public static void main(String[] args) {  
		Scanner scanner = new Scanner(System.in);
	     System.out.println(" ‰»Î:");
	     int[] sort = new int[10];
	     for(int i=0;i<10;i++) {
	         sort[i] = scanner.nextInt();
	     }
        int mask = binarySearch(sort,6);  
        System.out.println(mask);  
          
    }  
      
      
      
    private static int binarySearch(int[] sort,int data){  
        if(data<sort[0] || data>sort[sort.length-1]){  
            return -1;  
        }  
        int begin = 0;  
        int end = sort.length;  
        int mid = (begin+end)/2;  
        while(begin <= end){  
            mid = (begin+end)/2;  
            if(data > sort[mid]){  
                begin = mid + 1;  
            }else if(data < sort[mid]){  
                end = mid - 1;  
            }else{  
                return mid;  
            }  
        }  
        return -1;  
          
    }  
}
