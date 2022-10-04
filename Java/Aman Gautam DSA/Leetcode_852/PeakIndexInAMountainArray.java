class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int start =0;
        int end = arr.length-1;
        while(start<end){
            int mid = start+(end-start)/2;
            if(arr[mid]>arr[mid+1]){
                end = mid;
            }else{
            start=mid+1;
            }
        }
        // in the end start and end will point to the largest element because of the above two conditions
        // when they are pointing to the same element that is our max element
        return start; // we can also return end
    }
}