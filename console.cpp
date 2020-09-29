#include <windows.h>
#include <iostream>
#include <Lmcons.h>
#include <locale>
#include <tchar.h>


using namespace std;

string console_line;
string path_str;

int get_number_commands(string command){
	if(command == "whoami"){
		return 1;
	}
	if(command == "echo"){
		return 2;
	}
	if(command == "pwd"){
		return 3;
	}
	if(command == "rm"){
		return 4;
	}
	if(command == "date"){
		return 5;
	}
	if(command == "clear"){
		return 6;
	}
	if(command == "infocmp"){
		return 7;
	}
	if(command == "exit"){
		exit(0);	
	}else{
		return 0;
	}
	
}

void console(void){
	
	while(true){
		string cin_line;
		cout << console_line + path_str + "$ ";
		getline(cin, cin_line,'\n');
		char check[UNLEN + 1] = {0};
		int k = 0;
		for(int i = 0; i < cin_line.size(); i++ ){
			if(cin_line[i] == ' ' || cin_line[i] == '\0' || cin_line[i] == '\n'){
				break;		
			}
			check[i] = cin_line[i];		
		}
		string check_str = string(check);
		
		int number_com = get_number_commands(check);
		
		switch(number_com){
			case 1:{
				char *argv[]={"whoami.exe",NULL};
				_spawnvp(_P_WAIT,argv[0],argv);	
				break;
			}
			case 2:{
				char b[UNLEN + 1]={0};
				for(int i = 4, j = 0; i < cin_line.size() && i < UNLEN + 1; i++, j++){
					b[j]=cin_line[i];
				}
				
				char *argv[]={"echo.exe",b,NULL};
				_spawnvp(_P_WAIT,argv[0],argv);
				cout<<endl;
				break;
			}
			case 3:{
				char *argv[]={"pwd.exe",NULL};
				_spawnvp(_P_WAIT,argv[0],argv);
				break;
			}
			case 4:{
				char b[UNLEN + 1]={0};
				for(int i = 2, j = 0; i < cin_line.size() && i < UNLEN + 1; i++, j++){
					b[j]=cin_line[i];
				}
				
				char *argv[]={"rm.exe",b,NULL};
				_spawnvp(_P_WAIT,argv[0],argv);
				break;
			}
			case 5:{
				char *argv[]={"date.exe",NULL};
				_spawnvp(_P_WAIT,argv[0],argv);
				break;
			}
			case 6:{
				char *argv[]={"clear.exe",NULL};
				_spawnvp(_P_WAIT,argv[0],argv);
				break;
			}
			case 7:{
				char *argv[]={"infocmp.exe",NULL};
				_spawnvp(_P_WAIT,argv[0],argv);	
				break;
			}	
			default:
				cout<<"Не верная команда"<<endl;
		}	
	}
}

int main(){
	setlocale(LC_ALL,"RUS");
	
	char username[UNLEN + 1] = {0};
	DWORD username_len = UNLEN + 1;
	GetUserName(username,&username_len);
	
	
	
	char computer_name[UNLEN + 1];
	DWORD computer_name_len = UNLEN + 1;
	GetComputerName(computer_name,&computer_name_len);
	
	const string username_str = string(username);
	const string computer_name_str = string(computer_name);
	
	console_line = username_str + "@" + computer_name_str + ":~ ";
	
	
	char path[MAX_PATH] = {0};
	GetCurrentDirectory(sizeof(path),path);
	path_str = string(path);
	
	console();
}
