#include <vector>

using namespace std;

class Solution {
public:
/////////////////////////////////////////////////
 bool cube_traverse(int i,int j,int counts,vector<vector<char>>& board){
            vector<int> arr(10);
            fill(arr.begin(),arr.end(),0);
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){

                   if(board[k][l]!='.'){
                if(arr[board[k][l]-'0']==0){
                   arr[board[k][l]-'0']++;
                }
                else{
                    counts++;
                    return counts;
                }
                }

                }
            }
            return counts;
        }
/////////////////////////////////////////////
    int isValidSudoku(vector<vector<char>>& board) {
        int count=0;
        int count2=0;
        int count3=0;

        vector<int> arr(10);
        fill(arr.begin(),arr.end(),0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                if(arr[board[i][j]-'0']==0){
                    arr[board[i][j]-'0']++;
                }
                else{
                    count++;
                    break;
                }
                }
            }
            if(count>0){
                break;
            }
            else{
              fill(arr.begin(),arr.end(),0);  
            }
        }
//////////////////////////////////////////////////////
        fill(arr.begin(),arr.end(),0);
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                if(arr[board[i][j]-'0']==0){
                    arr[board[i][j]-'0']++;
                }
                else{
                    count2++;
                    break;
                }
                }
            }
            if(count>0){
                break;
            }
            else{
              fill(arr.begin(),arr.end(),0);  
            }
        }
        /////////////////////////////////
       
        ///////////////////////////////////////////
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                count3=cube_traverse(i,j,0,board);
                if(count3>0){
                    break;
                }

            }
            if(count3>0){
                break;
            }
        }

        //////////////////////////////////////
        
       if((count+count2+count3)>0){
        return false;
       } 
       else{
        return true;
       }
    }
};