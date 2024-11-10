#pragma once
#include<fstream>

class IFile
{
public:
	virtual void Save(std::ofstream& stream) const = 0;
	virtual void Save() = 0;
	virtual void Load(std::ifstream& stream) = 0;
	virtual void Load() = 0;

};

