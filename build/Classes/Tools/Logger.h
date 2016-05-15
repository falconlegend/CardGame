//
//  Logger.hpp
//  build
//
//  Created by Deflinhec on 2016/4/3.
//
//

#ifndef Logger_h
#define Logger_h

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define VIEWLOG(format, ...) Logger::DebugLog(__FILENAME__, __LINE__, "VIEWLOG", format, __VA_ARGS__ )

#define NETWORKLOG(format, ...) Logger::DebugLog(__FILENAME__, __LINE__, "NETWORKLOG", format, __VA_ARGS__ )

#define ERROR_LOG(format, ...) Logger::ErrorLog(__FILENAME__, __LINE__, format, __VA_ARGS__ )

#define LOG(...) Logger::Log(__VA_ARGS__ )

#define ERRORLOG()


class Logger {
public:
    
    static void ErrorLog(const char* _filename, const int _line, const char* _format, ...);
    static void DebugLog(const char* _filename, const int _line, const char* _prefix, const char* _format, ...);
    static void Log(const char* _format, ...);
    
private:    
    static std::string print_time();

};

#endif /* Logger_hpp */
