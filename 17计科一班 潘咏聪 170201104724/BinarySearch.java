import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args){
        int a[]={1,2,3,4,5,6,7,8,9};
        int left=0;
        int right=8;
        int x;
        int flag=0;
        System.out.println("输入你要查找的数字：");
        Scanner scan = new Scanner(System.in);
        x=scan.nextInt();
        while (left<=right){
            int middle=(left+right)/2;
            if(x==a[middle]){
                flag=1;
                System.out.println("在数组中的位置为：");
                System.out.println(middle);
                break;
            }
            if(x>a[middle]){
                left=middle+1;
            }
            else {
                right=middle-1;
            }
        }
        if(flag==0){
            System.out.println("没找到该数字");
        }
    }
}
