class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, long long> freq1, freq2;
        
        for (int x : nums1) ++freq1[x];
        for (int x : nums2) ++freq2[x];
        
        auto countWays = [](const vector<int>& source,
                            const unordered_map<long long, long long>& targetFreq) {
            long long result = 0;
            
            for (long long x : source) {
                long long square = x * x;
                
                for (const auto& [value, count] : targetFreq) {
                    if (square % value != 0) continue;
                    
                    long long other = square / value;
                    auto it = targetFreq.find(other);
                    if (it == targetFreq.end()) continue;
                    
                    if (value < other) {
                        result += count * it->second;
                    } else if (value == other) {
                        result += count * (count - 1) / 2;
                    }
                }
            }
            
            return result;
        };
        
        long long answer = countWays(nums1, freq2) + countWays(nums2, freq1);
        return static_cast<int>(answer);
    }
};