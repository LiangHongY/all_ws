#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

#define FILENAME "a.yaml .txt"

std::vector<double> bb(6,2);

void save(std::vector<double> aa)
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
		{
			ofs << "xyz_x: " << aa[i] << endl;
		}
		if (i == 5)
		{
			ofs << "xyz_y: " << aa[i]<< endl;
		}
	}
	ofs.close();

	
}



int main()
{
	bb = {1.0,2.0,3.0,4.0,5.0,12};  
	save(bb);
	system("pause");
	return 0;
}
