class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int ten=0;
        int five=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }else if(bills[i]==10){
                if(!five) return false;
                five--;
            }else{
                if(five && ten){
                    five--;
                    ten--;
                }else if(five>=3){
                    five-=3;
                }else{
                    return false;
                }
            }

        }
        return true;
    }
};