class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinks{};
        int emptyBottles{};
        while (numBottles) {
            drinks += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles - numBottles * numExchange;
        }
        return drinks;
    }
};