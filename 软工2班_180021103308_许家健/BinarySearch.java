/*
 *学号：180021103308
 *姓名：许家健
 * 分治法-二分搜索代码
 */
package divide_and_conquerMethod;

import java.util.Scanner;

public class BinarySearch {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Please enter the array's length: ");//输入数组长度
		int n=in.nextInt();
		int[] arr=new int[n];
		arr=initArray(arr);										//初始化数组并对从键盘输入的数组进行排序
		System.out.print("\n"+"Please enter what you want to find: ");
		int findOut = ToBinarySearch(arr, in.nextInt(), n);		//寻找查询的元素数组下标值并返回
		in.close();
		System.out.println("You want to search number on the position is  : " + findOut);
	}

	public static int ToBinarySearch(int[] a, int x, int n) {
		int left = 0, right = n - 1;							
		while (left <= right) {
			int middle = (left + right) / 2;					
			if (x == a[middle])									//表示找到元素，返回下标值
				return middle;

			if (x > a[middle])									//表示所需寻找的值大于数组中间的值
				left = middle + 1;								//令指向最左下标的指针往右移动，指向数组中间值右边的数值
			else
				right = middle - 1;
		}
		return -1;

	}
	
	
	
//插入排序
	public static int[] insertionSort(int[] array) {      
		if (array.length == 0)
			return array;
		int current;
		for (int i = 0; i < array.length - 1; i++) {
			current = array[i + 1];
			int preIndex = i;
			while (preIndex >= 0 && current < array[preIndex]) {
				array[preIndex + 1] = array[preIndex];
				preIndex--;
			}
			array[preIndex + 1] = current;
		}
		return array;
	}

	
//对数组进行初始化
	public static int[] initArray(int[] arr) {			
		Scanner inElements = new Scanner(System.in); 
		System.out.println("Please define the array elements at first: ");
		for (int i = 0; i < arr.length; i++) {
			arr[i]=inElements.nextInt();
		}
		System.out.println("Have been defined,and your array is:");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		insertionSort(arr);											//对输入的数组排好序
		System.out.println("\n"+"Then your array was been sorted,the array is:");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		return arr;
		
	}

}
