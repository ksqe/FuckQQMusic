#include <iostream>
#include <curl/curl.h>
#include "FuckQQMusic.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace std;
using namespace rapidjson;

FuckQQMusic::FuckQQMusic()
{
}


FuckQQMusic::~FuckQQMusic()
{
}

static int writer(char *data, size_t size, size_t nmemb, string *writerData)//
{
	unsigned long sizes = size * nmemb;
	writerData->append(data, sizes);
	return sizes;
}


void FuckQQMusic::clear(void)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

int FuckQQMusic::printmenu(void)
{
	FuckQQMusic::clear();
	int xuanze = 0;
	cout << "#####################" << endl << endl;
	cout << "1.���Ҹ���(δʵ��)" << endl;
	cout << "2.��������" << endl;
	cout << "3.�����赥(ʩ����)" << endl << endl;
	cout << "#####################" << endl;
	cout << "Powered By Kcass" << endl;
	cout << "��������Ĺ�Ƥѡ��" << endl;
	fflush(stdin);
	cin.clear();
	cin >> xuanze;
	return xuanze;
}

void FuckQQMusic::fucksonglink(string indata)
{
	string webjson = FuckQQMusic::getonweb("https://api.mlwei.com/music/api/?key=523077333&type=song&id=002obk1M1cqpjS");
	//string webjson = FuckQQMusic::getonweb("https://api.mlwei.com/music/api/?key=523077333&type=song&id=" + indata);
	const char* json = webjson.data();
	Document document;
	document.SetObject();
	document.Parse(json);
	mid = document["mid"].GetString();
	title = document["title"].GetString();
	album = document["album"].GetString();
	author = document["author"].GetString();
	url = document["url"].GetString();
	lrc = document["lrc"].GetString();
	cout << "id:" << mid << endl;
	cout << "����:" <<title << endl;
	cout << "ר��:" << album << endl;
	cout << "����:" << author << endl;
	cout << "URL:" << url << endl;
	cout << "���" << lrc << endl;
}

string FuckQQMusic::getonweb(string url)
{
	curl_global_init(CURL_GLOBAL_ALL);
	CURL *easy_handle = curl_easy_init();
	// ������ַ
	curl_easy_setopt(easy_handle, CURLOPT_URL, url.data());
	// ���ûص�����
	curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, writer);
	// �ص���������
	string data;
	curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &data);
	// ִ����������
	curl_easy_perform(easy_handle);
	// �ͷ���Դ
	curl_easy_cleanup(easy_handle);
	curl_global_cleanup();
	return data;
}