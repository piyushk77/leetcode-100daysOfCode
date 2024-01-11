class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // first rectangle coordinates
        int ax3 {ax2}, ay3 {ay1};
        int ax4 {ax1}, ay4 {ay2};

        // second rectangle coordinates
        int bx3 {bx2}, by3 {by1};
        int bx4 {bx1}, by4 {by2};

        // making outer selection rectangle
        int oTopLeftx {}, oTopLefty {};
        int oBottomRightx {}, oBottomRighty {};
        
        oTopLeftx = (ax4 < bx4) ? ax4 : bx4;
        oTopLefty = (ay4 < by4) ? by4 : ay4;

        oBottomRightx = (ax3 > bx3) ? ax3 : bx3;
        oBottomRighty = (ay3 < by3) ? ay3 : by3;

        int area {};

        for(int y {oTopLefty - 1}; y >= oBottomRighty; --y){
            int x = oTopLeftx + 1;
            while(x <= oBottomRightx){
                if(x > ax1 && x <= ax2){
                    if(y < ay2 && y >= ay1){
                        ++area;
                        ++x;
                        continue;
                    }
                }
                if(x > bx1 && x <= bx2){
                    if(y < by2 && y >= by1){
                        ++area;
                        ++x;
                        continue;
                    }
                }
                ++x;
            }
        }

        return area;
    }
};