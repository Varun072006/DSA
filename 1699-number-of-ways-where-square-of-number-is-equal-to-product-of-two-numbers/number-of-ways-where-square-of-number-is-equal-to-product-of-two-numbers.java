class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int count = 0;
        count += triplets(nums1, nums2);
        count += triplets(nums2, nums1);
        
        return count;        
    }
    
    public int triplets(int[] nums1, int[] nums2) {
        
		Map<Long, Integer> seen = new HashMap<>();
        int count = 0;
        
        for(int i=0; i<nums1.length; i++) {
            long sqr = (long) nums1[i] * nums1[i]; 
            if(seen.containsKey(sqr)) {  
                count += seen.get(sqr);
                continue;
            }
            
            int localCount = 0; 
            int left = 0, right = nums2.length-1; 
			
            while(left < right) {
                if(nums2[left] > sqr)
                    break;
                long multiple = (long) nums2[left] * nums2[right];
                
                if(sqr == multiple) {
                    if(nums2[left] == nums2[right]) { 
						int n = right - left+1;
                        localCount += n * (n-1)/2;
                        break;
                    }
                    localCount++;
                    int newL = left+1;
                    for(newL = left+1; newL < right && nums2[newL] == nums2[left]; newL++) {
                            localCount++;                        
                    }
                    right--;
                    
                } else if (multiple < sqr)
                    left++;
                else
                    right--;
            }
			
			count += localCount;
            seen.put(sqr, localCount);
			
        }
        return count;
    }
}