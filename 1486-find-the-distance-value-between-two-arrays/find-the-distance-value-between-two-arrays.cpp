class Solution{
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c = 0;
        for (auto& x : arr1) {
            bool o = true;
            for (auto& y : arr2) {
                o &= (abs(x - y) > d);
            }
            c += o;
        }
        return c;
    }
};