/****************************************************************************
Created By @ Ajay Singh Tanwar
-EngineDevelopment
****************************************************************************/

#include "Fileutils.h"
#include "include/macros.h"
#include <fstream>

namespace enginecore
{
    namespace utils
    {
        Fileutils::Fileutils()
        {
            //ctor
        }

        Fileutils::~Fileutils()
        {
            //dtor
        }

        void Fileutils::GetStringFromFile(std::string filepath , std::string &file_content)
        {
            std::fstream file(filepath.c_str());

            if(!file)
            {
                LOG("File could not be read : %s" , filepath.c_str());
                return ;
            }

            file_content.assign( (std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
        }
    }
}
