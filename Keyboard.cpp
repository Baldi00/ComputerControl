#include <iostream>
#include <ctype.h>
#include <Windows.h>
 
using namespace std;

void performClick(int);
void closeApp();
void mouseClick(int);
void zoom(bool);
void pressed(int,bool);
 
int main(int argc, char* argv[]) {
	
	argv[1][0] = toupper(argv[1][0]);
	
	if (isalnum(argv[1][0])) {
		performClick(argv[1][0]);
	} else {
		switch(argv[1][1]){
			case 'a': performClick(VK_SPACE); 				break;
			case 'b': performClick(VK_BACK); 				break;
			case 'c': performClick(VK_DELETE); 				break;
			case 'd': performClick(VK_LEFT); 				break;
			case 'e': performClick(VK_RIGHT); 				break;
			case 'f': performClick(VK_UP); 					break;
			case 'g': performClick(VK_DOWN); 				break;
			case 'h': performClick(VK_HOME); 				break;
			case 'i': performClick(VK_END); 				break;
			case 'j': performClick(VK_PRIOR); 				break;
			case 'k': performClick(VK_NEXT); 				break;
			case 'l': performClick(VK_TAB); 				break;
			case 'm': performClick(VK_RETURN); 				break;
			case 'n': performClick(VK_CAPITAL); 			break;
			case 'o': performClick(VK_SCROLL); 				break;
			case 'p': performClick(VK_NUMLOCK); 			break;
			case 'q': performClick(VK_ESCAPE); 				break;
			case 'r': performClick(VK_LWIN); 				break;
			case 's': performClick(VK_ADD);					break;
			case 't': performClick(VK_SUBTRACT);			break;
			case 'u': performClick(VK_MULTIPLY);			break;
			case 'v': performClick(VK_DIVIDE);				break;
			case 'w': performClick(VK_VOLUME_DOWN);			break;
			case 'x': performClick(VK_VOLUME_UP);			break;
			case 'y': performClick(VK_MEDIA_NEXT_TRACK);	break;
			case 'z': performClick(VK_MEDIA_PREV_TRACK);	break;
			case '0': performClick(VK_MEDIA_PLAY_PAUSE);	break;
			case '1': performClick(VK_OEM_COMMA);			break;
			case '2': performClick(VK_OEM_PERIOD);			break;
			case '3': performClick(VK_F5);					break;
			case '4': closeApp();							break;
			case '5': mouseClick(0);						break;
			case '6': mouseClick(1);						break;
			case '7': mouseClick(2);						break;
			case '8': zoom(true);							break;
			case '9': zoom(false);							break;
			case '-': performClick(VK_VOLUME_MUTE);			break;
			case '*': pressed(VK_MENU,true); performClick(VK_TAB); pressed(VK_MENU,false);		break;
			case '/': pressed(VK_LWIN,true); performClick(VK_TAB); pressed(VK_LWIN,false);		break;
			//case '.': 									break; RESERVED
		}
	}
	
    return 0;
}

void performClick(int code) {
	
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    
	ip.ki.wVk = code;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

void closeApp() {
	
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    
	ip.ki.wVk = VK_MENU;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.wVk = VK_F4;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.wVk = VK_F4;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.wVk = VK_MENU;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	
}

void mouseClick(int button){
	
	INPUT ip = {0};
	
    ip.type = INPUT_MOUSE;
    switch(button){
		case 0: ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; break;
		case 1: ip.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN; break;
		case 2: ip.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN; break;
	}
	SendInput(1, &ip, sizeof(ip));
	
	ZeroMemory(&ip, sizeof(ip));
	
    ip.type = INPUT_MOUSE;
    switch(button){
		case 0: ip.mi.dwFlags = MOUSEEVENTF_LEFTUP; break;
		case 1: ip.mi.dwFlags = MOUSEEVENTF_RIGHTUP; break;
		case 2: ip.mi.dwFlags = MOUSEEVENTF_MIDDLEUP; break;
	}
	SendInput(1, &ip, sizeof(ip));
}

void zoom(bool zoom) {
	
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    
	ip.ki.wVk = VK_LWIN;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	
	if(zoom){
		ip.ki.wVk = VK_ADD;
	}else{
		ip.ki.wVk = VK_SUBTRACT;
	}
	
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.wVk = VK_LWIN;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	
}

void pressed(int code, bool pressed){
	INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    
	ip.ki.wVk = code;
	
	if(pressed){
		ip.ki.dwFlags = 0;
	}else{
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
	}
	
	SendInput(1, &ip, sizeof(INPUT));
}
