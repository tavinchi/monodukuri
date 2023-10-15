#include<bits/stdc++.h>
using namespace std;
#define width 3
#define height 3
int main(){
    vector<vector<char>> MB(3,vector<char>(3,'-'));
    char z;
    bool flg=false;
    for(int i=0;i<9;i++){
        if(i%2==0){
            cout<<"〇のターン"<<endl;
        }else{
            cout<<"×のターン"<<endl;
        }
        cout<< "x,yの位置は？"<<endl;
        int x,y;
        cin >>x>>y;
        if(i%2==0){
            MB.at(x).at(y)='o';
        }else{
            MB.at(x).at(y)='x';
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout <<MB.at(j).at(k);
            }
            cout <<endl;
        }


        bool flg=false;
        int count=0;
        //横数え
        if(flg==false){
            for(int l=0;l<3;l++){
                for(int m=0;m<1;m++){
                    if(MB[l][m]==MB[l][m+1] && MB[l][m] != '-'){
                        count++;
                    }
                    if(MB[l][m]==MB[l][m+2]){
                        count++;
                        z=MB[l][m];
                    }
                }
                if(count==2){
                    printf("%cの勝ちです！\n",z);
                    i=8;
                    flg=true;
                    break;
                }
                count=0;
            }
        }

        //縦数え
        if(flg==false){
            for(int l=0;l<1;l++){
                for(int m=0;m<3;m++){
                    if(MB[l][m]==MB[l+1][m] && MB[l][m] != '-'){
                        count++;
                    }
                    if(MB[l][m]==MB[l+2][m]){
                        count++;
                        z=MB[l][m];
                    }
                    if(count==2){
                        printf("%cの勝ちです！\n",z);
                        i=8;
                        flg=true;
                        break;
                    }
                    count=0;   
                }    
            }
        }

        //右ななめ下数え
        if(flg==false){
            for(int l=0;l<1;l++){
                for(int m=0;m<1;m++){
                    if(MB[l][m]==MB[l+1][m+1] && MB[l][m] != '-'){
                        count++;
                    }
                    if(MB[l][m]==MB[l+2][m+2]){
                        count++;
                        z=MB[l][m];
                    }
                }
                if(count==2){
                    printf("%cの勝ちです！\n",z);
                    i=8;
                    flg=true;
                    break;
                }
                count=0;
            }
        }

        
        //左ななめ下数え
        if(flg==false){
            if(MB[2][0]==MB[1][1] && MB[2][0] != '-'){
                count++;
                if(MB[2][0]==MB[0][2]){
                    count++;
                    z=MB[2][0];
                }
            }
            if(count==2){
                printf("%cの勝ちです！\n",z);
                i=8;
                flg=true;
            }
        }
        if(i==8&&flg!=true){
            printf("引き分けです！\n");
        }
    }
}