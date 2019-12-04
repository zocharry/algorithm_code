	 class BinaryTest
		{
		 BinaryTest(){
			 
		 }
		    int binary(int[] array, int value)
		    {
		        int low = 0;
		        int high = array.length - 1;
		        while(low <= high)
		        {
		            int middle = (low + high) / 2;
		            if(value == array[middle])
		            {
		                return array[middle];
		            }
		            if(value > array[middle])
		            {
		                low = middle + 1;
		            }
		            if(value < array[middle])
		            {
		                high = middle - 1;
		            }
		        }
		        return -1;
		    }
		}
public class en {
	public static void main (String[] args) {			    		    
		        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		        BinaryTest k=new BinaryTest();
		        int value = k.binary(a,9);
		        System.out.println(value);
		}
}
	
	
