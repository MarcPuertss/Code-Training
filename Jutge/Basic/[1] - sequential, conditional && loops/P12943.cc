#include <iostream>
using namespace std;

int main(){

 int x,cntT, cntA = 0,cntB = 0, cntC = 0;
 char a;
 
 cin >> x;
 	for(int i = 0; i < x; ++i){
 		cin >> a;
 		if(a == 'a'){
 		cntA = cntA + 1;
 		}
 		if(a == 'b'){
 		cntB = cntB + 1;
 		}
 		if(a == 'c'){
 		cntC = cntC + 1;
 		}
 }
 if(cntA >= cntB and cntA >= cntC){
 	cntT = cntA;
 	a = 'a';
 }
 if(cntB > cntA and cntB >= cntC){
 	cntT = cntB;
 	a = 'b';
 }
if(cntC > cntA and cntC > cntB){
 	cntT = cntC;
 	a = 'c';
 }
 
 cout <<"majoria de " << a << endl << cntT << " repeticio(ns)" << endl;
}
