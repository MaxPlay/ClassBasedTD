#include "TextureAtlas.h"

#include <iostream>
#include <fstream>

using namespace CBTD;
using namespace Assets;

void TextureAtlas::Load(std::string file)
{
    if (file.length() <= 6)
        return;

    if (!file.find(".atlas", file.length() - 6))
        return;

    std::ifstream stream;
    stream.open(file, std::ios::out);
    std::string line;
    while (std::getline(stream, line))
    {

    }
}
