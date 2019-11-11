package main

import "fmt"

func binarySearch(arr []int, x int, length int) (int) {
	// return the index of x in the array, if it is not exsits, return -1.
	left := 0
	right := length - 1

	for left <= right {
		middle := (left + right) / 2
		if (x == arr[middle]) {
			return middle
		}
		if (x > arr[middle]) {
			left = middle + 1
		} else {
			right = middle - 1
		}
	}

	return -1
}

func main()  {
	arr := []int{1, 2, 3, 4, 5}
	fmt.Println("index: ", binarySearch(arr, 3, 5))
	fmt.Println("index: ", binarySearch(arr, 6, 5))
}
