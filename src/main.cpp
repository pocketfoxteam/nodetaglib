#include <iostream>
#include "taglib/taglib.h"
#include "taglib/tag.h"
#include "taglib/fileref.h"
#include "taglib/tstring.h"
#include <string>
#include "json.hpp"

using namespace std;
using namespace TagLib;
using JSON = nlohmann::json;


void GetMetadata(string fpath)
{
	TagLib::FileRef f(fpath.data());
	JSON j;
	j["title"] = f.tag()->title().to8Bit(true);
	j["artist"] = f.tag()->artist().to8Bit(true);
	j["album"] = f.tag()->album().to8Bit(true);
	j["comment"] = f.tag()->comment().to8Bit(true);
	j["genre"] = f.tag()->genre().to8Bit(true);
	j["year"] = f.tag()->year();
	j["track"] = f.tag()->track();
	cout << j;
}


int main(int argc, char *argv[])
{
	for(int i = 0; i < argc; i++)
	{
		string st = argv[i];
		int lof = st.find_last_of(".");
		if(lof >= 0){
			string ext = st.substr(lof);
			if(ext == ".mp3")
			{
				GetMetadata(st);
			}
		}
	}
}
