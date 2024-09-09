#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int remaining{m * n};
        int row{}, col{};
        int startRow{1}, startCol{};
        int endRow{m}, endCol{n};
        vector<int> temp(n, -1);
        vector<vector<int>> mat(m, temp);
        while (remaining > 0)
        {
            // increment to right till end
            for (; col < endCol; ++col)
            {
                if (head)
                {
                    mat[row][col] = head->val;
                    head = head->next;
                }
                --remaining;
            }
            if (!remaining)
                break;
            --col;
            ++row;
            --endCol;

            // increment down till end
            for (; row < endRow; ++row)
            {
                if (head)
                {
                    mat[row][col] = head->val;
                    head = head->next;
                }
                --remaining;
            }
            if (!remaining)
                break;
            --row;
            --col;
            --endRow;

            // decrement to left till start
            for (; col >= startCol; --col)
            {
                if (head)
                {
                    mat[row][col] = head->val;
                    head = head->next;
                }
                --remaining;
            }
            if (!remaining)
                break;
            ++col;
            --row;
            ++startCol;

            // decrement to top till start
            for (; row >= startRow; --row)
            {
                if (head)
                {
                    mat[row][col] = head->val;
                    head = head->next;
                }
                --remaining;
            }
            if (!remaining)
                break;
            ++row;
            ++col;
            ++startRow;
        }
        return mat;
    }
};