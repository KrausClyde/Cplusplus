#include "file.h"
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef struct person
{
	char name[30];
	char id[5];
	char number[5];
	char score[3];
}PERSON;
int textFileRead()
{
	ifstream infile;
	vector<string> v;
	infile.open("D:\\git\\code\\script\\text.txt");
	if (!infile) cout << "error" << endl;

	string str;
	while(getline(infile,str))   //按行读取,遇到换行符结束
	{
	    cout<<str<<endl;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}
	infile.close();
	return 0;
}

vector<PERSON> vPerson;
int excelFileRead()
{
	ifstream infile;
	ofstream outfile;
	vector<string> v;
	PERSON person;
	char seps[] = ",";
	char *token[3];
	int i = 0;
	infile.open("D:\\git\\code\\script\\test.csv");
	outfile.open("D:\\git\\code\\script\\outTEST.csv", ios::out | ios::trunc);
	if (!infile) cout << "error" << endl;

	string str;
	while (getline(infile, str))   //按行读取,遇到换行符结束
	{
		v.push_back(str);
	}
	for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		string str = *iter;
		int length = str.length();
		cout << "length : " << length << endl;
		cout << "sizeof(str.c_str()) : " << sizeof(str.c_str()) << endl;
		cout << "strlen(str.c_str()) : " << strlen(str.c_str()) << endl;
		cout << "str.c_str() : " << str.c_str() << endl;
		char *buf = new char[length +1];
		char *result[3];
		for (i = 0 ;i < 3; i++)
		{
			result[i] = new char[30];
		}
		char *ptr;
		memcpy_s(buf, length, str.c_str(), length);
		cout << "buf : " << buf << endl;
#if 0
		while ((token[i] = strtok(buf, seps)) != NULL)
		{
			printf("%s\n", token[i]);
			i++;
			buf = NULL;
		}
#endif
		ptr = strtok_s(buf, seps, result);
		memcpy_s(person.name, strlen(ptr), ptr, strlen(ptr));
		while (ptr != NULL)
		{
			ptr = strtok_s(NULL, seps, result);
		}
		vPerson.push_back(person);
		*iter = *iter + ",SCORE";
		cout << *iter << endl;
		outfile << *iter << endl;
	}
	infile.close();
	
	return 0;
}