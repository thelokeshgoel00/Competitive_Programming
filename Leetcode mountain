class Solution {
    public boolean validMountainArray(int[] A) {
        
    
        if(A.length < 2) return false;
		int i = 0; 
		while(i < A.length-1 && A[i] < A[i+1]) i++;
		
        if(i == A.length - 1) 
            return false;
		
        while(i != 0 && i < A.length-1 && A[i] > A[i + 1]) i++;
		
        
        
        return i == A.length-1;
    }
}
