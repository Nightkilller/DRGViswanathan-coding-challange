class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0;
        int r=h.size()-1;
        int ma=0;

        while(l<r){
            int c=min(h[l],h[r])*(r-l);
            ma=max(ma,c);

            if(h[l]<h[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ma;
    }
};
