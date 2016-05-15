//
//  Logger.cpp
//  build
//
//  Created by Deflinhec on 2016/4/3.
//
//

#include "Logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
void Logger::ErrorLog(const char *_filename, const int _line, const char *_format, ...){
    
    printf("[%s] [%s] [Line: %d] [ *** ERROR *** ] ", print_time().c_str(), _filename, _line);
    
    va_list args;
    va_start(args, _format);
    vprintf(_format, args);
    va_end(args);

    printf("\n");
}

void Logger::DebugLog(const char* _filename, const int _line, const char* _prefix, const char* _format, ...){

    printf("[%s] [%s] [Line: %d] [ *** %s *** ] ", print_time().c_str(), _filename, _line, _prefix);
    
    va_list args;
    va_start(args, _format);
    vprintf(_format, args);
    va_end(args);
 
    printf("\n");
}

void Logger::Log(const char *_format, ...){
    
    va_list args;
    va_start(args, _format);
    vprintf(_format, args);
    va_end(args);
    
    printf("\n");
}

std::string Logger::print_time(){
    time_t t;
    struct tm *timeInfo;
    
    time(&t);
    timeInfo = localtime(&t);
    char buff[64];
    
    strftime(buff, sizeof(buff), "%c", timeInfo);
    return std::string(buff);
}

