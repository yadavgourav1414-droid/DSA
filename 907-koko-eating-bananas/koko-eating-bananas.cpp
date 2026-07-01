class Solution {
public:
    long long totalHours(vector<int>& piles, int speed) {
        long long totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = maxPile;
        int high = maxPile;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = totalHours(piles, mid);
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};