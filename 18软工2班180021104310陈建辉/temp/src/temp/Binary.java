package temp;

public class Binary {
		public static void main(String[] args) {
			int[] a = { 1, 2, 4, 7, 8, 10, 11 };
			int s1 = BinarySearch(a, 8, 0, a.length - 1);
			System.out.println(s1);
		}
		public static int BinarySearch(int[] a, int x, int right, int left) {
			while (right<= left) {
				int middle = (right + left) / 2;
				if (a[middle] > x) {
					left = middle - 1;
				} else if (a[middle] < x) {
					right = middle + 1;
				} else {
					return middle;
				}
			}
			return -1;
		}
	}
