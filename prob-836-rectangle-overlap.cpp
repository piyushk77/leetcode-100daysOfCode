#include <vector>
using namespace std;
class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        // vertex check 1
        int ax1{rec1[0]}, ay1{rec1[1]};
        int ax2{rec1[2]}, ay2{rec1[3]};
        int ax3{ax2}, ay3{ay1};
        int ax4{ax1}, ay4{ay2};

        int smallX{rec2[0]}, largeX{rec2[2]};
        int smallY{rec2[1]}, largeY{rec2[3]};

        if (ax1 > smallX && ax1 < largeX)
        {
            if (ay1 > smallY && ay1 < largeY)
                return true;
        }
        if (ax2 > smallX && ax2 < largeX)
        {
            if (ay2 > smallY && ay2 < largeY)
                return true;
        }
        if (ax3 > smallX && ax3 < largeX)
        {
            if (ay3 > smallY && ay3 < largeY)
                return true;
        }
        if (ax4 > smallX && ax4 < largeX)
        {
            if (ay4 > smallY && ay4 < largeY)
                return true;
        }

        // vertex check 2
        ax1 = rec2[0];
        ay1 = rec2[1];
        ax2 = rec2[2];
        ay2 = rec2[3];
        ax3 = ax2;
        ay3 = ay1;
        ax4 = ax1;
        ay4 = ay2;

        smallX = rec1[0];
        largeX = rec1[2];
        smallY = rec1[1];
        largeY = rec1[3];

        if (ax1 > smallX && ax1 < largeX)
        {
            if (ay1 > smallY && ay1 < largeY)
                return true;
        }
        if (ax2 > smallX && ax2 < largeX)
        {
            if (ay2 > smallY && ay2 < largeY)
                return true;
        }
        if (ax3 > smallX && ax3 < largeX)
        {
            if (ay3 > smallY && ay3 < largeY)
                return true;
        }
        if (ax4 > smallX && ax4 < largeX)
        {
            if (ay4 > smallY && ay4 < largeY)
                return true;
        }

        // cross check
        int aLowerX{rec1[0]}, aUpperX{rec1[2]};
        int aLowerY{rec1[1]}, aUpperY{rec1[3]};

        int bLowerX{rec2[0]}, bUpperX{rec2[2]};
        int bLowerY{rec2[1]}, bUpperY{rec2[3]};

        if ((aLowerY >= bLowerY && aLowerY <= bUpperY) &&
            (aUpperY >= bLowerY && aUpperY <= bUpperY))
        {
            if ((bLowerX >= aLowerX && bLowerX <= aUpperX) &&
                (bUpperX >= aLowerX && bUpperX <= aUpperX))
                return true;
        }
        else if ((bLowerY >= aLowerY && bLowerY <= aUpperY) &&
                 (bUpperY >= aLowerY && bUpperY <= aUpperY))
        {
            if ((aLowerX >= bLowerX && aLowerX <= bUpperX) &&
                (aUpperX >= bLowerX && aUpperX <= bUpperX))
                return true;
        }
        return false;
    }
};