#include <iostream>
using namespace std;

int main(){

	int h, m, s;
	
	cin >> h >> m >> s;
	
		s = s + 1;
	
	if (s == 60){
		s = 0;
		m = m + 1;
	}
	if (m == 60){
		m = 0;
		h = h + 1;
	}
	if (h == 24){
		h = 0;
	}

	if(h < 10 and m < 10 and s < 10){
	
		cout <<0<<h<<":"<<0<<m<<":"<<0<<s<<endl;
		}
	else if(s < 10 and m < 10){
	
		cout <<h<<":"<<0<<m<<":"<<0<<s<<endl;
		}
		
	else if(h < 10 and m < 10){
	
		cout <<0<<h<<":"<<0<<m<<":"<<s<<endl;
		}
		
	else if(h < 10 and s < 10){
	
		cout <<0<<h<<":"<<m<<":"<<0<<s<<endl;
		}
		
	else if(s < 10){
	
		cout <<h<<":"<<m<<":"<<0<<s<<endl;
		}
	
		
	else if(m < 10){
	
		cout <<h<<":"<<0<<m<<":"<<s<<endl;
		}

		
	else if(h < 10){
	
		cout <<0<<h<<":"<<m<<":"<<s<<endl;
		}
		
	else{
	
		cout <<h<<":"<<m<<":"<<s<<endl;
	}






}
