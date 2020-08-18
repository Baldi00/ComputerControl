#include <iostream>
#include <Windows.h>
 
using namespace std;
 
int main() {
	
	// Create a generic keyboard event structure
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    
    SetCursorPos(0,0);
    SetCursorPos(100,100);
    
    Sleep(3000);
    
	ip.ki.wVk = VK_LWIN;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = VK_SNAPSHOT;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = VK_SNAPSHOT;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.wVk = VK_LWIN;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    return 0;
	
    /*while (true) {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) { // Exit
            return 0;
        }
        if (GetAsyncKeyState(VK_NUMPAD1)) {//Mouseposition
            POINT p;
            GetCursorPos(&p);
            cout << "x-position: " << p.x << " | y-position: " << p.y << endl;
            Sleep(1000);
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) { // leftclick
            INPUT iNPUT = { 0 };
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            ZeroMemory(&iNPUT, sizeof(iNPUT));
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &iNPUT, sizeof(iNPUT));
        }
        if (GetAsyncKeyState(VK_NUMPAD3)) { //write a
            INPUT Input = { 0 };
            Input.type = INPUT_KEYBOARD;
            Input.ki.wVk = VkKeyScanA('a');
            SendInput(1, &Input, sizeof(Input));
            ZeroMemory(&Input, sizeof(Input));
            Input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &Input, sizeof(Input));
        }
    }*/
}
