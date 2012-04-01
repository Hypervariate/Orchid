#ifndef FILEREADER_H
#define FILEREADER_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAX_PATH_LENGTH 256

class FileReader{
public:
	FileReader();
	~FileReader();

	bool OpenFile(char* file_path);
	bool CloseFile();

    string ReadLine();
	
	
	string ReadToken();
	string GetToken(unsigned int i);
	unsigned int GetTotalTokens();

	bool TokenizeFile();

private:
	ifstream m_readFile;
	string m_lineBuffer;
	string m_tokenBuffer;
	vector<string> m_tokens;
	

};

#endif