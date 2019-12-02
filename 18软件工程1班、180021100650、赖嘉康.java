import java.util.Scanner;
public class getIndex {

	public static void main(String[] args) {
		Scanner sr = new Scanner(System.in);
        int f = sr.nextInt(); 
        int n = sr.nextInt(); 
        int attr[] = new int[n]; 
        for (int i=0;i<n;i++){
            attr[i]=sr.nextInt();
        }
        int index = searchmy(attr,f,n);
        if (index==-1){
            System.out.println("no found");
        }else{
            System.out.println(f+" found£º"+index);
        }
	}
	   static int  searchmy(int att[],int m ,int n){
	
	    
	        int low = 0;
	        int high=att.length;
	        int  mid = 0;
	           while(low<high){
	               mid = (low+high)/2;
	               if(att[mid]==m){
	                   return mid;
	               }else if(m<att[mid]){
	                   high = mid - 1;
	               }else{ //m>att[mid]
	                   low = mid+1;
	               }
	            }
	        return -1;
	    }


}
