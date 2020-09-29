#include <windows.h>
#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char *argv[]){
	setlocale(LC_ALL,"RUS");
	
	int i = 0;
	while(argv[i++] != NULL){
		cout<<argv[i]<<" ";
	}
	
}
