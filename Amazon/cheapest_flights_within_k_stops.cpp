class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prices(n, 1e8), temp;
    prices[src] = 0;
    for(int i=0;i<=k;i++) {
        temp = prices;
        for(auto &x : flights) {
            int u = x[0], v=x[1], w=x[2];
            if(prices[u] + w < temp[v])
                temp[v] = prices[u] + w;
        }
        prices = temp;
    }
    if(prices[dst] == 1e8)
        return -1;
    return prices[dst];
}
};
