#pragma once
#include <iostream>
#include <string>

using namespace std;
class FuckQQMusic
{
public:
	FuckQQMusic();
	virtual ~FuckQQMusic();
	int printmenu(void); //����˵�
	void clear(void); //��������
	void fucksonglink(string); //���ڽ�������
	string getonweb(string); //���ڴ�api��ȡjson
	string indata; //���ڽ�������
private:
	string mid; //����id
	string title; //��������
	string album; //����ר��
	string author; //��������
	string url; //ͼƬurl
	string lrc; //���url
};