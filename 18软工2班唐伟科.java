import java.util.*;
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] ary=new int[10];
		Scanner reader=new Scanner(System.in);
		System.out.println("请按顺序输入10个数字：");
		for(int i=0;i<10;i++){
			int a=reader.nextInt();//输入10个数字
			ary[i]=a;
		}
		System.out.println("请输入需要查找的数字：");
		int b=reader.nextInt();//输入要查找的数据
		System.out.println();
		int i=10;
		for(int j=4;j<0;j--){
			i=i/2;
			if(b<ary[i]){
				i=i-1;
			}if(b==ary[i]){
				System.out.println("已找到");
				System.out.println("i为"+i);
				break;
			}else{
				i=ary.length+i;
			}
		}
		System.out.println("未找到");
	}
}

