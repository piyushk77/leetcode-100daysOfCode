#include <vector>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft =
            _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight =
            _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int value{grid[0][0]};
        int m{static_cast<int>(grid.size())};
        bool leaf{true};
        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < m; ++j)
            {
                if (grid[i][j] != value)
                {
                    leaf = false;
                    break;
                }
            }
            if (!leaf)
                break;
        }

        if (leaf)
        {
            Node *head = new Node(value, leaf);
            return head;
        }
        else
        {
            vector<vector<int>> topLeft;
            vector<vector<int>> topRight;
            vector<vector<int>> bottomLeft;
            vector<vector<int>> bottomRight;

            for (int i{}; i < m / 2; ++i)
            {
                vector<int> temp;
                for (int j{}; j < m / 2; ++j)
                {
                    temp.push_back(grid[i][j]);
                }
                topLeft.push_back(temp);
            }

            for (int i{}; i < m / 2; ++i)
            {
                vector<int> temp;
                for (int j{m / 2}; j < m; ++j)
                {
                    temp.push_back(grid[i][j]);
                }
                topRight.push_back(temp);
            }

            for (int i{m / 2}; i < m; ++i)
            {
                vector<int> temp;
                for (int j{}; j < m / 2; ++j)
                {
                    temp.push_back(grid[i][j]);
                }
                bottomLeft.push_back(temp);
            }

            for (int i{m / 2}; i < m; ++i)
            {
                vector<int> temp;
                for (int j{m / 2}; j < m; ++j)
                {
                    temp.push_back(grid[i][j]);
                }
                bottomRight.push_back(temp);
            }

            Node *head =
                new Node(true, false, construct(topLeft), construct(topRight),
                         construct(bottomLeft), construct(bottomRight));
            return head;
        }
    }
};