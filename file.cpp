#include "file.h"

using namespace std;

int fileRead()
{
	ifstream infile;
	infile.open("1.txt");
	if (!infile) cout << "error" << endl;

	string str;
	while(getline(infile,str))   //���ж�ȡ,�������з�����
	{
	    cout<<str<<endl;
	}
	infile.close();
	return 0;
}