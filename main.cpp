#include <iostream>
#include <string>
#include <vector>
#include "FuckQQMusic.h"

using namespace std;


int main(){
	FuckQQMusic music;
	for (int xuanze = 0;;)
	{
		xuanze = music.printmenu();
		vector<string> songname,songid;
		switch (xuanze)
		{
		case 1:
			music.clear();
			cout << "����ؼ���" << endl;
			cin >> music.indata;
			break;
		case 2:
			music.clear();
			cout << "���뵥������" << endl;
			cin >> music.indata;
			if (music.indata.find("y.qq.com/n/yqq/song/") != string::npos)
			{
				music.indata = music.indata.substr(music.indata.find("song") + 5, music.indata.find(".html") - music.indata.find("song") - 5);
				music.fucksonglink(music.indata);
				cin.get();
			}else
			{
				cout << "�����!!!!" << endl;
			}
			break;
		case 3:
			music.clear();
			cout << "����赥����" << endl;
			cin >> music.indata;
			break;
		default:
			cout << "����㣡" << endl;
			break;
		}
	}
	return 0;
}