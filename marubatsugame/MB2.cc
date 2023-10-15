#include<bits/stdc++.h>
using namespace std;
int x,y;

//判定横
bool checkW(vector<vector<char>> data2){
	bool flg;
	int cnt=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(data2[i][j]==data2[i][j+1]){
				cnt++;
			}
		}
		if(cnt==3 && data2[i][0]!='-'){
			flg=true;
			return flg;
		}
		cnt=1;
	}
	flg=false;
	return flg;
}

//判定縦
bool checkH(vector<vector<char>> data2){
	bool flg;
	int cnt=1;
	for(int i=0;i<1;i++){
		for(int j=0;j<3;j++){
			if(data2[i][j]==data2[i+1][j]){
				if(data2[i+1][j]==data2[i+2][j]){
					cnt=3;
				}
			}
			if(cnt==3 && data2[0][j]!='-'){
				flg=true;
				return flg;
			}
			cnt=1;
		}
	}
	flg=false;
	return flg;
}

//判定ななめ右
bool checkNR(vector<vector<char>> data2){
	int cnt=1;
	if(data2[0][2]==data2[1][1]){
		if(data2[1][1]==data2[2][0]){
			cnt=3;
		}
	}
	if(cnt==3 && data2[0][2]!='-'){
		return true;
	}else{
		return false;
	}
}

//判定ななめ左
bool checkNL(vector<vector<char>> data2){
	int cnt=1;
	if(data2[0][0]==data2[1][1]){
		if(data2[1][1]==data2[2][2]){
			cnt=3;
		}
	}
	if(cnt==3 && data2[0][0]!='-'){
		return true;
	}else{
		return false;
	}
}

//勝敗表示
int prt(bool flg,int i){
	if(flg){
		if(i%2==0){
			printf("oの勝ち！\n");
			return 8;
		}else{
			printf("xの勝ち！\n");
			return 8;
		}
	}
	return i;
}

int main(void){
	vector<vector<char>> data2(3,vector<char>(3,'-'));
	for(int i=0;i<9;i++){
		if(i%2==0){
			cout <<"【 o 】のターン"<<endl;
			cin >>x>>y;
			data2[x][y]='o';
		}else if(i%2!=0){
			cout <<"【 x 】のターン"<<endl;
			cin >>x>>y;
			data2[x][y]='x';
		}

		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				cout <<data2[j][k];
			}
			cout <<endl;
		}


		//判定
		bool flgW=checkW(data2);
		int ansW=prt(flgW,i);
		i=ansW;

		bool flgH=checkH(data2);
		int ansH=prt(flgH,i);
		i=ansH;

		bool flgNR=checkNR(data2);
		int ansNR=prt(flgNR,i);
		i=ansNR;

		bool flgNL=checkNL(data2);
		int ansNL=prt(flgNL,i);
		i=ansNL;
	}	
	return 0;
}
