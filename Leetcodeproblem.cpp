#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> merged;
        int min = 0;
        double median = 0;
        int index=0;
        bool from_i=true;
        int max = nums1.size()+nums2.size();
        while(merged.size()<max){
            min=nums2[0];
            index=0;
            from_i=true;
            if (!nums1.empty()){
                min=nums1[0];
                for(int i=0;i<nums1.size();++i){
                    if(min>nums1[i]){
                        min=nums1[i];
                        index=i;
                    }
                }
            }
            if(!nums2.empty()){
                for(int j=0;j<nums2.size();++j){
                    if(min>nums2[j]){
                        min=nums2[j];
                        from_i=false;
                        index=j;
                    }
                }
            }
            if(from_i==true){
                if(!nums1.empty()){
                    nums1.erase(nums1.begin()+index);
                }
            }
            else {
                if(!nums2.empty()){
                    nums2.erase(nums2.begin()+index);
                }
            }
            merged.push_back(min);
            cout << min << endl;
        }
        if(merged.size()%2==0){
            int med1 = 0;
            int med2 = 0;
            med1=merged[(merged.size()/2)-1];
            med2=merged[(merged.size()/2)];
            median=(med1+med2)/2.0;
        }
        else {
            median=merged[(merged.size()/2)+0.5];
        }
        return median;
    }
};
int main(){
    Solution s1;
    vector <int> r1{3,4};
    vector <int> r2{1,5};
    cout << s1.findMedianSortedArrays(r1,r2) << endl;
}