import java.util.Arrays;
public class Main {

	public static void main(String[] args) {
		int[] arr={1,2,3,4,5,6,7};
		int index1=Binary(arr, 12, 0, arr.length - 1);
		int index2=Binary(arr, 66, 0, arr.length - 1);
		System.out.println(index1);
		System.out.println(index2);
	}
	public static int Binary(int[] arr, int key, int low, int high) {
		while (low <= high) {			
			int mid=(low+high)/2;
			if(arr[mid]>key){
				high = mid - 1;
			}
			else if(arr[mid] < key){
				low = mid + 1;
			}
			else{
				return mid;	
				}
			}
		return -1;
	}

}
