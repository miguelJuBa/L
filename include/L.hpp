#ifndef __H_LOGGER__
#define __H_LOGGER__

#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <exception>

namespace Logger
{
    class L
    {
        public:                                   
            //Trace
            template<typename... ArgTypes>
            void t(ArgTypes... args){say(0, (ArgTypes(args))...);} 
            //Info
            template<typename... ArgTypes>
            void i(ArgTypes... args){say(1, (ArgTypes(args))...);} 
            //Warning
            template<typename... ArgTypes>
            void w(ArgTypes... args){say(2, (ArgTypes(args))...);} 
            //Error
            template<typename... ArgTypes>
            void e(ArgTypes... args){say(3, (ArgTypes(args))...);} 
            //Fatal
            template<typename... ArgTypes>
            void f(ArgTypes... args){say(4, (ArgTypes(args))...);} 

            //Sets logging level threshold. 
            void setLevel(std::string level)     
            {   
                //Seach for threshold level.
                auto selectedLevel = levels.find(level);
                if(selectedLevel != levels.end())
                {
                    currentLevel = selectedLevel->second;
                }                
            }

            //Set channel for output.
            void setChannel(std::ostream * channel)
            {
                if(channel == nullptr)
                    throw std::runtime_error("Provided channel is a null pointer.");

                this->output = channel;
            }

        private:
            //Argument expand struct.
            struct expand_type 
            {
                template<typename... T>
                expand_type(T&&...) {}    
            };
            //General logger function.
            template<typename... ArgTypes>
            void say(const unsigned short level, ArgTypes... args)
            {
                //Compose log line from a tag based on level and a message.
                const char * tags[] = {"TRACE", "INFO", "WARN", "ERROR", "FATAL"};
                const char * tag = level > 5 ? tags[0]: tags[level];
                if(level >= currentLevel)
                {
                    //Get current UTC time.
                    std::time_t now= std::time(0);
                    std::tm* now_tm= std::gmtime(&now);
                    char buf[42];
                    std::strftime(buf, 42, "%Y-%m-%d %X", now_tm);
                    //Output log.
                    *(output) << "[" << buf << "][" << tag << "] ";
                    expand_type{0, (*(output) <<args, 0)... };
                    *(output) << std::endl;
                }
            }
            //Set default trace level to 0 or TRACE.
            unsigned short currentLevel = 0;
            //Seleted output stream. Default to standard output.
            std::ostream * output = &std::cout;
            //Log levels.
            const std::map<std::string, unsigned short> levels =  
            {{"TRACE", 0}, {"INFO",  1}, {"WARN",  2}, {"ERROR", 3}, {"FATAL", 4}};
    };   
}

#endif
