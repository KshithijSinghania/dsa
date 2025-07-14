class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1=0;
        int score2=0;
        score1=player1[0];
        score2=player2[0];
        if(player1.size()>=2){
        score1+=(score1==10?(2*player1[1]):player1[1]);
        score2+=(score2==10?(2*player2[1]):player2[1]);
        for(int i=2;i<player1.size();i++){
            score1+=((player1[i-1]==10||player1[i-2]==10)?(2*player1[i]):player1[i]);
            score2+=((player2[i-1]==10||player2[i-2]==10)?(2*player2[i]):player2[i]);
        }        
        }
        cout<<score1<<score2;
        if(score1==score2)
        return 0;
        else if(score1>score2)
        return 1;
        return 2;
    }
};