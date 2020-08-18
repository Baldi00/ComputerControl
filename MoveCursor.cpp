#include <iostream>
#include <string>
#include <Windows.h>
 
using namespace std;
 
int main(int argc, char* argv[]) {
	
	POINT p;
	GetCursorPos(&p);
	
	if(argv[1][0]=='x') {
		if(strcmp(argv[2],"-50")==0){
			SetCursorPos(p.x-50,p.y);
		}else if(strcmp(argv[2],"-10")==0){
			SetCursorPos(p.x-10,p.y);
		}else if(strcmp(argv[2],"50")==0){
			SetCursorPos(p.x+50,p.y);
		}else{
			SetCursorPos(p.x+10,p.y);
		}
	} else if (argv[1][0]=='y') {
		if(strcmp(argv[2],"-50")==0){
			SetCursorPos(p.x,p.y-50);
		}else if(strcmp(argv[2],"-10")==0){
			SetCursorPos(p.x,p.y-10);
		}else if(strcmp(argv[2],"50")==0){
			SetCursorPos(p.x,p.y+50);
		}else{
			SetCursorPos(p.x,p.y+10);
		}
	} else if (argv[1][0]=='s') {
		SetCursorPos(atoi(argv[2]),atoi(argv[3]));
	} else if (argv[1][0]=='o') {
		SetCursorPos(p.x+atoi(argv[2]),p.y+atoi((argv[3])));
	}
	
    return 0;
}
