#ifndef FILEREADER_H
#define FILEREADER_H

#include <sys/types.h>
#include "dirent.h"
#include <errno.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAX_PATH_LENGTH 512

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
	unsigned int GetAllFileNamesInDirectory(string dir, vector<string> &files);

private:
	ifstream m_readFile;
	string m_lineBuffer;
	string m_tokenBuffer;
	vector<string> m_tokens;
	

};

#endif