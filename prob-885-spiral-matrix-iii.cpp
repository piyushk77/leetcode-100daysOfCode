#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {
        vector<vector<int>> coordinates;
        int hSteps{1}, vSteps{1};
        int elements{rows * cols};

        while (elements)
        {
            // move right
            for (int i{rStart}, j{cStart}; j < cStart + hSteps; ++j)
            {
                if (i >= 0 && i < rows && j >= 0 && j < cols)
                {
                    coordinates.push_back({i, j});
                    --elements;
                }
            }
            cStart += hSteps;
            ++hSteps;

            // move down
            for (int i{rStart}, j{cStart}; i < rStart + vSteps; ++i)
            {
                if (i >= 0 && i < rows && j >= 0 && j < cols)
                {
                    coordinates.push_back({i, j});
                    --elements;
                }
            }
            rStart += vSteps;
            ++vSteps;

            // move left
            for (int i{rStart}, j{cStart}; j > cStart - hSteps; --j)
            {
                if (i >= 0 && i < rows && j >= 0 && j < cols)
                {
                    coordinates.push_back({i, j});
                    --elements;
                }
            }
            cStart -= hSteps;
            ++hSteps;

            // move up
            for (int i{rStart}, j{cStart}; i > rStart - vSteps; --i)
            {
                if (i >= 0 && i < rows && j >= 0 && j < cols)
                {
                    coordinates.push_back({i, j});
                    --elements;
                }
            }
            rStart -= vSteps;
            ++vSteps;
        }
        return coordinates;
    }
};