#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(const string& s){
	
	
	int x = s.size()-1;
	int y = 0;
	
	while( x != 0 ){
		
		if(s[x] != s[y]) return false;
		
		--x;
		++y;
	
	}
	return true;
}


