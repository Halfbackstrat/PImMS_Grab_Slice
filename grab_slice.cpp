#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Declarations and definitions of variables
int x, y, t, shot, bin;
vector<vector<int> > image(72, vector<int> (72,0)); 

int main(int argc, char *argv[])

{


ifstream myfile;
myfile.open(argv[1]);

if (myfile.is_open())
{
	while(myfile >> x >> y >> t >> shot >> bin)
	{	
		if (t == *argv[2])
		{
			if ( x < 72 && y < 72 && x > 0 && y > 0)
			{
			++image[x-1][y-1];
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

