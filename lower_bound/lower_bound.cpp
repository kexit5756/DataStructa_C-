
//2分的多种写法

#include <iostream>
#include <vector>
using namespace std;
//闭区间实现
int lower_bound(vector<int> &nums,int target){
    int left=0,right=(int)nums.size()-1; //左闭右闭
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>=target){
            right=mid-1;
        }else{
            left=mid-1;
        }
    }
    return left;
}
//左闭区间右开：
int lower_bound2(vector<int> &nums,int target){
    int left=0,right=(int)nums.size();
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]>=target){
            right=mid;
        }else{
            left=mid-1;
        }
    }
    return left;

}
//开区间
int lower_bound3(vector<int> &nums,int target){
    int left=-1,right=(int)nums.size();
    while(left+1<right){
        int mid=left+(right-left)/2;
        if(nums[mid]>=target){
            right=mid;
        }else{
            left=mid;
        }
        return right;
        
    }
}