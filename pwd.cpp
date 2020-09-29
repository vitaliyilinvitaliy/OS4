#include <windows.h>
#include <iostream>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL,"RUS");
	
	setlocale(LC_ALL,"RUS");
	char path[MAX_PATH] = {0};
	GetCurrentDirectory(sizeof(path),path);
	cout << path <<endl;
}
