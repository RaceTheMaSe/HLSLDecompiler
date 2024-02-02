// Shaders.cpp : Defines the entry point for the console application.
//

#include "binary_decompiler.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <direct.h>

FILE *LogFile = NULL;
bool gLogDebug = false;

static std::vector<std::string> enumerateFiles(const std::string &pathName, const std::string &filter = "")
{
    std::vector<std::string> files;
    WIN32_FIND_DATAA FindFileData;
    HANDLE hFind;
    std::string sName = pathName;
    sName.append(filter);
    hFind = FindFirstFileA(sName.c_str(), &FindFileData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        std::string fName = pathName;
        fName.append(FindFileData.cFileName);
        files.push_back(fName);
        while (FindNextFileA(hFind, &FindFileData))
        {
            fName = pathName;
            fName.append(FindFileData.cFileName);
            files.push_back(fName);
        }
        FindClose(hFind);
    }
    return files;
}

static std::vector<byte> readFile(const std::string &fileName)
{
    std::vector<byte> buffer;
    FILE* f = nullptr;
    fopen_s(&f, fileName.c_str(), "rb");
    if (f != nullptr)
    {
        fseek(f, 0L, SEEK_END);
        int fileSize = ftell(f);
        buffer.resize(fileSize);
        fseek(f, 0L, SEEK_SET);
        size_t numRead = fread(buffer.data(), 1, buffer.size(), f);
        fclose(f);
    }
    return buffer;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int shaderNo = 1;
    std::vector<std::string> gameNames;
    std::string pathName;
    std::vector<std::string> files;
    FILE* file = nullptr;
    char cwd[MAX_PATH];
    char gamebuffer[10000];

    if (!_getcwd(cwd, MAX_PATH)) return 1;
    std::vector<std::string> lines;
    fopen_s(&file, "gamelist.txt", "rb");
    if (file)
    {
        size_t fr = ::fread(gamebuffer, 1, 10000, file);
        fclose(file);
        lines = stringToLines(gamebuffer, fr);
    }

	if (!lines.empty())
    {
		for (auto i = lines.begin(); i != lines.end(); i++)
        {
			gameNames.push_back(*i);
		}
	} else
    {
		gameNames.push_back(cwd);
	}
	for (DWORD i = 0; i < gameNames.size(); i++)
    {
		std::string gameName = gameNames[i];
		std::cout << gameName << ":" << '\n';

		int progress = 0;
		pathName = gameName;
		pathName.append("\\ShaderCache\\");
		files = enumerateFiles(pathName, "????????????????-??.bin");
		if (files.size() > 0)
        {
			std::cout << "bin->asm: ";
			for (DWORD i = 0; i < files.size(); i++)
            {
				std::string fileName = files[i];

				std::vector<byte> ASM;
                std::vector<byte> read_results = readFile(fileName);
				disassembler(&read_results, &ASM, NULL);

				fileName.erase(fileName.size() - 3, 3);
				fileName.append("txt");
				FILE* f = nullptr;
				fopen_s(&f, fileName.c_str(), "wb");
				fwrite(ASM.data(), 1, ASM.size(), f);
				fclose(f);
				
				int newProgress = (int)(50.0 * i / files.size());
				if (newProgress > progress) {
					std::cout << ".";
					progress++;
				}
			}
		}
		std::cout << '\n';

		progress = 0;
		pathName = gameName;
		pathName.append("\\ShaderCache\\");
		files = enumerateFiles(pathName, "????????????????-??.txt");
		if (!files.empty())
        {
			std::cout << "asm->cbo: ";
			for (DWORD i = 0; i < files.size(); i++)
            {
				std::string fileName = files[i];

				auto ASM = readFile(fileName);
				fileName.erase(fileName.size() - 3, 3);
				fileName.append("bin");
				auto BIN = readFile(fileName);
				
				auto CBO = assembler((std::vector<char>*)&ASM, BIN);

				fileName.erase(fileName.size() - 3, 3);
				fileName.append("cbo");
				FILE* f;
				fopen_s(&f, fileName.c_str(), "wb");
				if (f) {
					fwrite(CBO.data(), 1, CBO.size(), f);
					fclose(f);
				}

				int newProgress = (int)(50.0 * i / files.size());
				if (newProgress > progress) {
					std::cout << ".";
					progress++;
				}
			}
		}
		std::cout << '\n';

		progress = 0;
		pathName = gameNames[i];
		pathName.append("\\Mark\\");
		files = enumerateFiles(pathName, "*.bin");
		if (files.size() > 0) {
			std::cout << "bin->asm validate: ";
			for (DWORD i = 0; i < files.size(); i++) {
				std::string fileName = files[i];

				std::vector<byte> ASM;
                std::vector<byte> read_results = readFile(fileName);
				disassembler(&read_results, &ASM, NULL);

				fileName.erase(fileName.size() - 3, 3);
				fileName.append("txt");
				FILE* f;
				fopen_s(&f, fileName.c_str(), "wb");
				if (f) {
					fwrite(ASM.data(), 1, ASM.size(), f);
					fclose(f);
				}

				int newProgress = (int)(50.0 * i / files.size());
				if (newProgress > progress) {
					std::cout << ".";
					progress++;
				}
			}
		}
		std::cout << '\n';

		writeLUT();
	}
	return 0;
}
