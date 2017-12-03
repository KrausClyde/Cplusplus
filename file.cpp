#include "file.h"

using namespace std;

int fileRead()
{
	ifstream infile;
	infile.open("1.txt");
	if (!infile) cout << "error" << endl;

	string str;
	while(getline(infile,str))   //按行读取,遇到换行符结束
	{
	    cout<<str<<endl;
	}
	infile.close();
	return 0;
}