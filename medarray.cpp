class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i,j;
        i = 0;
        for( j = 0; i<nums1.size()&&j<nums2.size();)
        {
            if(nums1[i]<nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
               res.push_back(nums2[j]);
                j++;
            }
            else
            {
                res.push_back(nums1[i]);
                res.push_back(nums2[j]);
                i++; j++;
            }
        }
        while(i<nums1.size())
            res.push_back(nums1[i++]);
        while(j<nums2.size())
            res.push_back(nums2[j++]);
            int l = res.size();
            if(l%2)
                return res[l/2];
            return (double)(res[l/2] + res[(l/2)-1])/2; 
       
        
    }
};
