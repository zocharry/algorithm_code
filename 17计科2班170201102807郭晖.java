package test;

public class homework {
    
    public static int binaryFind(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    
    public static int findFirstGNumOpen(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            System.out.println("left=" + left + " mid= " + mid + " right= " + right);
            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        System.out.println("left=" + left);
        System.out.println("right=" + right);
        return (left == arr.length) ? -1 : left;
    }

    
    public static int findFirstLNumOpen(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        System.out.println("left=" + left);
        System.out.println("right=" + right);
        return (right == 0) ? -1 : right - 1;
    }

}
