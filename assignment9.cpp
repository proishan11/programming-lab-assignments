#include<iostream>

using namespace std;
#define cross -1

int chess[8][8] = {0};

void initialize(){
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			chess[i][j] = 0;
}

int mark(int x, int y){
	chess[x][y] = 1;
	if(x+2<8 && y+1<8)
		chess[x+2][y+1] = cross;
	if(x+2<8 && y-1<8 && y-1>=0)
		chess[x+2][y-1] = cross;
	if(x-2<8 && x-2>=0 && y+1<8)
		chess[x-2][y+1] = cross;
	if(x-2<8 &&x-2>=0 && y-1<8 && y-1>=0)
		chess[x-2][y-1] = cross;
	if(x-1<8 && x-1>=0 && y+2<8)
		chess[x-1][y+2] = cross;
	if(x-1<8 &&x-1>=0 && y-2<8 && y-2>=0)
		chess[x-1][y-2] = cross;
	if(x+1<8 && y+2<8)
		chess[x+1][y+2] = cross;
	if(x+1<8 && y-2<8 && y-2>=0)
		chess[x+1][y-2] = cross;
	return 0;
}

int getcommon(int x, int y){
	int count = 0;
	if(x+2<8 && y+1<8)
		if(chess[x+2][y+1] == -1){count++;}
	if(x+2<8 && y-1<8 && y-1>=0)
		if(chess[x+2][y-1] == -1){count++;}
	if(x-2<8 && x-2>=0 && y+1<8)
		if(chess[x-2][y+1] == -1){count++;}
	if(x-2<8 &&x-2>=0 && y-1<8 && y-1>=0)
		if(chess[x-2][y-1] == -1){count++;}
	if(x-1<8 && x-1>=0 && y+2<8)
		if(chess[x-1][y+2] == -1){count++;}
	if(x-1<8 &&x-1>=0 && y-2<8 && y-2>=0)
		if(chess[x-1][y-2] == -1){count++;}
	if(x+1<8 && y+2<8)
		if(chess[x+1][y+2] == -1){count++;}
	if(x+1<8 && y-2<8 && y-2>=0)
		if(chess[x+1][y-2] == -1){count++;}
	return count;
}

void getPosition(int* x, int* y, int p, int q){
	int maxi=p, maxj=q, no_common, maxCommon=-1;

	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(chess[i][j] == 0){
				no_common = getcommon(i,j);
				if(maxCommon < no_common){
					maxCommon = no_common;
					maxi = i;
					maxj = j;
				}
			}
		}
	}
	*x = maxi;
	*y = maxj;
	return;
}

int printChess(){
	int count = 0;
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			cout << chess[i][j] << "     ";
			if(chess[i][j] == 1)
				count++;
		}
		cout<<endl;
	}
	return count;
}	

bool noneEmpty(){
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j){
			if(chess[i][j]==0)
				return true;
		}
	return false;
}



int main(){
	int x,y,no_of_knight;
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			initialize();
			mark(i,j);
			while(noneEmpty()){

				getPosition(&x,&y,i,j);
				mark(x,y);
			}
			cout<<"final state of chess if we put first knight at" << i <<","<< j<<"th position"<<endl;
			cout<< "\n----\n";
			no_of_knight = printChess();
			cout<< "The number of knights we can put is " << no_of_knight<<endl;
		}
	}
}
