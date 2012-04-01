#include "FileReader.h"

FileReader::FileReader(){

}
FileReader::~FileReader(){
	if (m_readFile.is_open())
		m_readFile.close();

}

bool FileReader::OpenFile(char* file_path){
	m_readFile.open(file_path);
	return m_readFile.is_open();
}
bool FileReader::CloseFile(){
	m_readFile.close();
	return !m_readFile.is_open();
}
string FileReader::ReadLine(){
	if(m_readFile.is_open() && !m_readFile.eof()){
		getline(m_readFile,m_lineBuffer);
		return m_lineBuffer;
	}
	else
		return "";
}
string FileReader::ReadToken(){
	if(m_readFile.is_open() && !m_readFile.eof()){
		m_readFile >> m_tokenBuffer;
		return m_tokenBuffer;
	}
	else
		return "";
}
bool FileReader::TokenizeFile(){
	m_tokens.clear();
	string token = "";
	while(!m_readFile.eof()) // To get you all the lines.
	{
		token = ReadToken();
		m_tokens.push_back(token);
	}
	CloseFile();
	return true;
}
string FileReader::GetToken(unsigned int i){
	if(i < m_tokens.size())
		return m_tokens.at(i);
	else
		return "";
}
unsigned int FileReader::GetTotalTokens(){
	return m_tokens.size();
}
unsigned int FileReader::GetAllFileNamesInDirectory(string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}