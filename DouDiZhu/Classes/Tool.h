#pragma once
#include "cocos2d.h"
#include "iconv\iconv.h"
#include <iostream>
#include <string.h>
int code_convert(const char *from_charset, const char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen);
/*UTF8תΪGB2312*/  
std::string u2a(const char *inbuf);
/*GB2312תΪUTF8*/  
std::string a2u(const char *inbuf);