#include<windows.h>
int main(void)
{
	HKEY hKey,hKey3;
	unsigned char reg[80]="infected1";
	unsigned char reg2[80]="infected2";
	unsigned char reg5[80]="KeyboardSpeed";
    unsigned char reg4[200]="Search Results Folder";

	RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\run",&hKey);/*infected delete*/
	RegDeleteValue(hKey,reg);
	RegDeleteValue(hKey,reg2);
	RegCloseKey(hKey);
	RegOpenKey(HKEY_CURRENT_USER,"Control Panel\\Keyboard",&hKey3);/*keyboard speed*/
	RegDeleteValue(hKey3,reg5);
	RegSetValueEx(hKey3,reg5,0,REG_SZ,"31",sizeof(reg5));
	RegCloseKey(hKey3);


RegCreateKey(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Desktop\\NameSpace\\{e17d4fc0-5564-11d1-83f2-00a0c90dc849}",&hKey); 
RegSetValueEx(hKey,"",0,REG_SZ,reg4,sizeof(reg4));/*search folder*/
RegCloseKey(hKey);
DeleteFile("c:\\a.inf");
DeleteFile("d:\\a.inf");
DeleteFile("c:\\w.exe");
DeleteFile("d:\\w.exe");


system("shutdown -r -t 0");

	return 0;
}