class Solution {
public:
    int maxArea(vector<int>& height) {
        // int left = 0;
        // int right = height.size() - 1;
        // int maxArea = 0;

        // while (left < right) {
        //     int currentArea = min(height[left], height[right]) * (right - left);
        //     maxArea = max(maxArea, currentArea);

        //     if (height[left] < height[right]) {
        //         left++;
        //     } else {
        //         right--;
        //     }
        // }

        // return maxArea;

        int start = 0, end = height.size()-1;
        int max_ans = INT_MIN;
        while(start < end) {
            int curr_ans = (end-start)*min(height[start], height[end]);
            max_ans = max(curr_ans, max_ans);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return max_ans;
    }
};