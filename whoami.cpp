#include <windows.h>
#include <iostream>
#include <locale>
#include <Lmcons.h>

using namespace std;

int main(){
	setlocale(LC_ALL,"RUS");
	
	char username[UNLEN + 1] = {0};
	DWORD username_len = UNLEN + 1;
	GetUserName(username,&username_len);
	cout << username << endl;
}
