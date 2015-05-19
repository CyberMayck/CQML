#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/**
 * Main function.
 * Readds generated files to MSVC studio.
 */
int main (int arc, char **argv) {
	if(arc!=3)
	{
		printf("requires 2 arguments - <path to project file> <relative include path>");
		return 0;
	}
	vector<string> lines;
	vector<string> fileNames;
	vector<string> headerNames;
	string includePath=argv[2];
	string line;
	ifstream myfile (argv[1]);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			lines.push_back(line);
			//cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file \""<< argv[1] <<"\"\n";
	}
	
	ifstream configFile ("outputfiles.txt");
	if (configFile.is_open())
	{
		while( getline (configFile,line) )
		{
			fileNames.push_back(line);
		}
		configFile.close();
	}
	else 
	{
		cout << "Unable to open file \"outputfiles.txt\"\n";
		return 0;
	}

	bool printing=false;
	ofstream outprojfile (argv[1]);
	if (outprojfile.is_open())
	{
		for(unsigned int i=0;i<lines.size();i++)
		{
			if(string::npos==lines[i].find(string("ClCompile Include")))
			{
				//print
				outprojfile << lines[i] << "\n";
			}
			else
			{
				if(string::npos==lines[i].find(includePath))
				{
					//print
					outprojfile << lines[i] << "\n";
				}
				else
				{
					if(!printing)
					{
						printing = true;
						for(unsigned int j=0;j<fileNames.size();j++)
						{
							string outputLine= "    <ClCompile Include=\"cqml_output\\"+ fileNames[j] + "\" />";
							outprojfile << outputLine << "\n";
						}
					}
				}
			}
		}

		outprojfile.close();
	}
	else cout << "Unable to open file \""<< argv[1] <<"\"\n";

	return 0;
}