class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto bound = [&](long long needA, int costA, long long needB, int costB) {
            int A = min(costA, costBoth);
            int B = min(costB, costBoth - A);
            return needA * A + needB * B;
        };
        return max(bound(need1, cost1, need2, cost2), bound(need2, cost2, need1, cost1));
    }
};