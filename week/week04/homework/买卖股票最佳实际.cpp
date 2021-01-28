//
// Created by Administrator on 2020/11/15.
//

int maxProfit(vector<int> &prices) {

    int sum = 0;
    int min = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        if (min < prices[i]) {
            sum += (prices[i] - min);
        }
        min = prices[i];
    }
    return sum;
}
