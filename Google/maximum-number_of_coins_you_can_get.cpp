class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int alice_score=0;
        int my_score=0;
        int bob_score=0;
        
        sort(piles.begin(),piles.end(),greater<int>());
        
        int temp1=0;
        int temp2=1;
        int temp3=piles.size()-1;
        
        while(temp2<temp3)
        {
            alice_score=alice_score+piles[temp1];
            my_score=my_score+piles[temp2];
            bob_score=bob_score+piles[temp3];
            
            temp1=temp1+2;
            temp2=temp2+2;
            temp3--;
        }
        return my_score;  
    }
};
