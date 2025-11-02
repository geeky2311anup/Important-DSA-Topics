//problem link -> https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2025-11-02

class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        char[][] arr = new char[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]='n';
            }
        }
        for(int i=0;i<guards.length;i++){
            arr[guards[i][0]][guards[i][1]]='g';
        }
         for(int i=0;i<walls.length;i++){
            arr[walls[i][0]][walls[i][1]]='w';
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]=='g'){
                    //left
                    for(int k=j-1;k>=0;k--){
                        if(arr[i][k]=='n'){
                            arr[i][k]='l';
                        }
                        else if(arr[i][k]=='g' || arr[i][k]=='w' || arr[i][k]=='l' || arr[i][k]=='r'|| arr[i][k]=='a'){
                            break;
                        }
                        else if(arr[i][k]=='u' || arr[i][k]=='d'){
                            arr[i][k]='a';
                        }
                    }
                    //right
                      for(int k=j+1;k<n;k++){
                        if(arr[i][k]=='n'){
                            arr[i][k]='l';
                        }
                        else if(arr[i][k]=='g' || arr[i][k]=='w' || arr[i][k]=='l' || arr[i][k]=='r'|| arr[i][k]=='a'){
                            break;
                        }
                        else if(arr[i][k]=='u' || arr[i][k]=='d'){
                            arr[i][k]='a';
                        }
                    }
                    //up
                        for(int k=i-1;k>=0;k--){
                        if(arr[k][j]=='n'){
                            arr[k][j]='u';
                        }
                        else if(arr[k][j]=='g' || arr[k][j]=='w' || arr[k][j]=='u' || arr[k][j]=='d'|| arr[k][j]=='a'){
                            break;
                        }
                        else if(arr[k][j]=='l' || arr[k][j]=='r'){
                            arr[k][j]='a';
                        }
                    }
                    //down
                        for(int k=i+1;k<m;k++){
                        if(arr[k][j]=='n'){
                            arr[k][j]='d';
                        }
                        else if(arr[k][j]=='g' || arr[k][j]=='w' || arr[k][j]=='u' || arr[k][j]=='d'|| arr[k][j]=='a'){
                            break;
                        }
                        else if(arr[k][j]=='l' || arr[k][j]=='r'){
                            arr[k][j]='a';
                        }
                    }
                }
            }
        }
        int count=0;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if( arr[i][j]=='n'){
                count++;
               }
            }
        }
        return count;

    }
}
