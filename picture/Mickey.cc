#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<string>> MC(13,vector<string>(12));

	MC.at(1).at(1)="◢";
	MC.at(1).at(2)="■";
	MC.at(1).at(3)="■";
	MC.at(1).at(4)="◣";
	MC.at(1).at(5)=".";
	MC.at(1).at(6)=".";
	MC.at(1).at(7)="◢";
	MC.at(1).at(8)="■";
	MC.at(1).at(9)="■";
	MC.at(1).at(10)="◣";

	MC.at(2).at(1)="■";
	MC.at(2).at(2)="■";
	MC.at(2).at(3)="■";
	MC.at(2).at(4)="■";
	MC.at(2).at(5)=".";
	MC.at(2).at(6)=".";
	MC.at(2).at(7)="■";
	MC.at(2).at(8)="■";
	MC.at(2).at(9)="■";
	MC.at(2).at(10)="■";

	MC.at(3).at(1)="■";
	MC.at(3).at(2)="■";
	MC.at(3).at(3)="■";
	MC.at(3).at(4)="■";
	MC.at(3).at(5)=".";
	MC.at(3).at(6)=".";
	MC.at(3).at(7)="■";
	MC.at(3).at(8)="■";
	MC.at(3).at(9)="■";
	MC.at(3).at(10)="■";

	MC.at(4).at(1)="◥";
	MC.at(4).at(2)="■";
	MC.at(4).at(3)="■";
	MC.at(4).at(4)="◢";
	MC.at(4).at(5)="■";
	MC.at(4).at(6)="■";
	MC.at(4).at(7)="◣";
	MC.at(4).at(8)="■";
	MC.at(4).at(9)="■";
	MC.at(4).at(10)="◤";

	MC.at(5).at(1)=".";
	MC.at(5).at(2)="◢";
	MC.at(5).at(3)="■";
	MC.at(5).at(4)="■";
	MC.at(5).at(5)="□";
	MC.at(5).at(6)="□";
	MC.at(5).at(7)="■";
	MC.at(5).at(8)="■";
	MC.at(5).at(9)="◣";
	MC.at(5).at(10)=".";

	MC.at(6).at(1)=".";
	MC.at(6).at(2)="■";
	MC.at(6).at(3)="■";
	MC.at(6).at(4)="□";
	MC.at(6).at(5)="□";
	MC.at(6).at(6)="□";
	MC.at(6).at(7)="□";
	MC.at(6).at(8)="■";
	MC.at(6).at(9)="■";
	MC.at(6).at(10)=".";

	MC.at(7).at(1)=".";
	MC.at(7).at(2)="■";
	MC.at(7).at(3)="□";
	MC.at(7).at(4)="■";
	MC.at(7).at(5)="□";
	MC.at(7).at(6)="□";
	MC.at(7).at(7)="■";
	MC.at(7).at(8)="□";
	MC.at(7).at(9)="■";
	MC.at(7).at(10)=".";

	MC.at(8).at(1)=".";
	MC.at(8).at(2)="□";
	MC.at(8).at(3)="□";
	MC.at(8).at(4)="□";
	MC.at(8).at(5)="◢";
	MC.at(8).at(6)="◣";
	MC.at(8).at(7)="□";
	MC.at(8).at(8)="□";
	MC.at(8).at(9)="□";
	MC.at(8).at(10)=".";

	MC.at(9).at(1)=".";
	MC.at(9).at(2)="▽";
	MC.at(9).at(3)="□";
	MC.at(9).at(4)="□";
	MC.at(9).at(5)="□";
	MC.at(9).at(6)="□";
	MC.at(9).at(7)="□";
	MC.at(9).at(8)="□";
	MC.at(9).at(9)="▽";
	MC.at(5).at(1)=".";

	MC.at(10).at(1)=".";
	MC.at(10).at(2)=".";
	MC.at(10).at(3)="▽";
	MC.at(10).at(4)="□";
	MC.at(10).at(5)="■";
	MC.at(10).at(6)="■";
	MC.at(10).at(7)="□";
	MC.at(10).at(8)="▽";
	MC.at(10).at(9)=".";
	MC.at(10).at(10)=".";

	MC.at(11).at(1)=".";
	MC.at(11).at(2)=".";
	MC.at(11).at(3)=".";
	MC.at(11).at(4)="▽";
	MC.at(11).at(5)="□";
	MC.at(11).at(6)="□";
	MC.at(11).at(7)="▽";
	MC.at(11).at(8)=".";
	MC.at(11).at(9)=".";
	MC.at(11).at(10)=".";

	for(int i=0;i<13;i++){
		for(int j=0;j<12;j++){
			if(MC.at(i).at(j)==" "){
				cout << "d";
			}else{
				cout << MC.at(i).at(j);
			}
		}
		cout << endl;
	}
}