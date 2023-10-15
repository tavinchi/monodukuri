#include <iostream>
#include <vector>

#define height (3)
#define width (3)

using namespace std;

bool flg=false;     //終了フラグ
int turn=0;
int cnt=0;

class marubatsu{
public:
    marubatsu(){
        field=vector<vector<char>> (3,vector<char>(3,'.'));
    }
    void playGame(){
        while(!flg){
            cnt++;
            printfield();
            printTurn();
            bool FLG=false;
            inputzahyou(FLG);
            checkend();
        }
    }
private:
    vector<vector<char>> field;
    int x,y;    //座標

    void printfield(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                printf("%c",field[i][j]);
            }
            printf("\n");
        }
    }

    void printTurn(){
        if(turn==0){
            printf("〇のターン\n");
            
        }else{
            printf("Xのターン\n");
            
        }
    }

    void inputzahyou(bool FLG){
        while(FLG==false){
            cin >>y>>x;
            if(x>=0 && x<=2 && y>=0 && y<=2){
                if(field[y][x]=='.'){
                    break;
                }else{
                    printf("そこには置けないよ!\n");
                }
            }else{
                printf("そこには置けないよ!\n");
            }
        }
        //checkput(y,x);
        if(turn==0 && field[y][x]=='.'){
            field[y][x]='o';
            turn=1;
        }else if(turn==1 && field[y][x]=='.'){
            field[y][x]='x';
            turn=0;
        }
    }


    void checkend(){
        checkwin();
        if(cnt>=9 || flg==true){
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++){
                    printf("%c",field[i][j]);
                }
                printf("\n");
            }
            flg=true;
            printf("gameは終了です\n");
        }
    }

    void checkwin(){
        checkWidth();       //横
        checkHeight();      //縦
        checkNaname();      //ななめ
    }

    void checkWidth(){
        for(int i=0;i<height;i++){
            for(int j=0;j<1;j++){
                if(field[i][j]=='o' && field[i][j]==field[i][j+1] && field[i][j+1]==field[i][j+2]){
                    flg=true;
                    printf("oが横にそろいました\n");
                }else if(field[i][j]=='x' && field[i][j]==field[i][j+1] && field[i][j+1]==field[i][j+2]){
                    flg=true;
                    printf("xが横にそろいました\n");
                }
            }
        }
    }

    void checkHeight(){
        for(int i=0;i<1;i++){
            for(int j=0;j<width;j++){
                if(field[i][j]=='o' && field[i][j]==field[i+1][j] && field[i+1][j]==field[i+2][j]){
                    flg=true;
                    printf("oが縦にそろいました\n");
                }else if(field[i][j]=='x' && field[i][j]==field[i+1][j] && field[i+1][j]==field[i+2][j]){
                    flg=true;
                    printf("xが縦にそろいました\n");
                }
            }
        }
    }

    void checkNaname(){
        if(field[0][0]=='o' && field[0][0]==field[1][1] && field[1][1]==field[2][2]){
            flg=true;
            printf("oが斜めにそろいました\n");
        }else if(field[0][0]=='x' && field[0][0]==field[1][1] && field[1][1]==field[2][2]){
            flg=true;
            printf("xが斜めにそろいました\n");
        }else if(field[0][2]=='o' && field[0][2]==field[1][1] && field[1][1]==field[2][0]){
            flg=true;
            printf("oが斜めにそろいました\n");
        }else if(field[0][2]=='x' && field[0][2]==field[1][1] && field[1][1]==field[2][0]){
            flg=true;
            printf("xが斜めにそろいました\n");
        }
    }

};


int main(){
    marubatsu obj;
    obj.playGame();
    return 0;
}