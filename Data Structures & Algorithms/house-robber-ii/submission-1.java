class Solution {
    public int max(int a,int b)
    {
        if(a>=b)return a;
        return b;
    }

    public int max(int a,int b,int c)
    {
        if(a>=b && a>=c)return a;
        if(b>=a && b>=c)return b;
        return c;
    }

    public int maxRob(int[] modifiedNums)
    {
        int len=modifiedNums.length;
        int []maxRobList=new int[len];
        maxRobList[len-1]=modifiedNums[len-1];
        maxRobList[len-2]=modifiedNums[len-2];
        if(len>=3)maxRobList[len-3]=modifiedNums[len-1]+modifiedNums[len-3];
        //System.out.println(maxRobList[len-1]);
        //System.out.println(maxRobList[len-2]);
        //System.out.println(maxRobList[len-3]);
        for(int i=len-4;i>=0;i--)
        {
            maxRobList[i]=modifiedNums[i]+max(maxRobList[i+2],maxRobList[i+3]);
            //System.out.println(maxRobList[i]);
        }
        return max(maxRobList[0],maxRobList[1]);
    }

    public int rob(int[] nums) {
        if(nums.length==1)return nums[0];
        if(nums.length==2)return max(nums[0],nums[1]);
        if(nums.length==3)return max(nums[0],nums[1],nums[2]);

        int []nums1=new int[nums.length-1];
        int []nums2=new int[nums.length-1];
        for(int i=0;i<nums.length-1;i++)
        {
            nums1[i]=nums[i];
        }
        for(int i=1;i<nums.length;i++)
        {
            nums2[i-1]=nums[i];
        }
        int gain1=maxRob(nums1);
        //System.out.println();
        int gain2=maxRob(nums2);
        //System.out.println(gain1);
        //System.out.println();
        //System.out.println(gain2);
        return max(gain1,gain2);
    }
}
