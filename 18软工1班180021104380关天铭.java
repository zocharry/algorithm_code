import java.util.Scanner;

public class BinarySearch {
	public static int binarySerach(int data[], int start, int end, int n) {
		if (start > end) {
			return -1;
		}
		int i = (start + end) / 2;
		if (data[i] == n) {
			return i;
		}
		if (data[i] > n) {
			return binarySerach(data, start, i - 1, n);
		}
		return binarySerach(data, i + 1, end, n);
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入数组的长度：");
		int n = sc.nextInt();
		System.out.println("请输入您的数组：");
		int data[] = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = sc.nextInt();
		}
		// 数组排序 冒泡排序
		for (int i = 0; i < data.length; i++) {
			for (int j = 0; j < data.length - 1; j++) {
				if (data[j] > data[j + 1]) {
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = data[j];
				}
			}
		}
		System.out.println("请输入您要查找的数组元素");
		int b = sc.nextInt();
		int x = binarySerach(data, 0, n - 1, b);
		if (x == -1) {
			System.out.println(b + "不在数组中，请重新输入：");
			b = sc.nextInt();
			x = binarySerach(data, 0, n - 1, b);
		}
		System.out.println("您查找的数组元素下标为：" + x);
	}
}