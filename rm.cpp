#include <windows.h>
#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char *argv[]){
	
	if(remove(argv[1]) != 0 ){
		cout << "Error delete file " <<argv[1]<< endl;
	}else{
		cout << "File deleted" << endl;	
	}
    
	
}
