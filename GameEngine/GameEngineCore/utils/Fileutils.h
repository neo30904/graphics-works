/****************************************************************************
Created By @ Ajay Singh Tanwar
-EngineDevelopment
****************************************************************************/

#ifndef FILEUTILS_H
#define FILEUTILS_H

#pragma once

#include <string>
namespace enginecore
{
    namespace utils
    {
        class Fileutils
        {
            public:
                Fileutils();
                virtual ~Fileutils();

                void GetStringFromFile(std::string filepath , std::string &file_content);
            protected:
            private:
        };
    }
}

#endif // FILEUTILS_H
