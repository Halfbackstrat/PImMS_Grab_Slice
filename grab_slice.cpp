#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Declarations and definitions of variables
int x, y, t, shot, bin;
vector<vector<int> > image(72, vector<int> (72,0)); 
int tcount = 0;
int var;
int main(int argc, char *argv[])

{

if (argc < 3)
{return 0;}

ifstream myfile;
myfile.open(argv[1]);

int var;

var = stoi(argv[2]);

cout << "var = " << var << endl;
if (myfile.is_open())
{
	while(myfile >> x >> y >> t >> shot)
	{
		//cout << "x = " << x << " y = " << y << " t = " << t << " shot = " << shot << " bin = " << bin << endl;
		//cout << "t = " << t << " arg2 = " << argv[2] << endl;
		if (t == var)
		{
			tcount++;
			//cout << tcount << endl;
			if ( x < 72 && y < 72 && x > 0 && y > 0)
			{
			//++tcount;
			image[x-1][y-1]++;
			}
			else 
			{
				cout << "x = " << x << " y = " << y << endl;
			}
		}
			 
	}

}
else
{
	return 0;
}

cout << "tcount = " << tcount << endl;

myfile.close();

ofstream outputfile("output");

for (int i = 0; i < image.size(); ++i)
{
	for (int j = 0; j < image[i].size(); ++j)
	{
		outputfile << image[i][j] << "\t";
	}

	outputfile << endl;
}

outputfile.close();

return 0;

}

