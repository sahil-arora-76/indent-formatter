#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
#include <sstream>
#include <stdio.h>
//4 space default indent

struct Config
{
    int space;
    int start_line; 
    int end_line;  
}; 
struct Config c; 

std::string read_file_content(char *);  
std::string format_file(char *);
void write_file(char *, std::string content);

int main(int argc, char **argv) 
{

    std::string content; 
    int line_length = 0; 
    int line = 1; 
    printf("How much space of indent u want\n"); 
    scanf("%d", &(c.space));

    if (argc <= 3) 
    {
        printf("./format [file] [start-line] [end-line]\n");
        return -1; 
    }
    try
    {
        c.start_line = std::stoi(argv[2]); 
        c.end_line = std::stoi(argv[3]); 
    } catch(...) 
    {
        printf("error occured\n"); 
        return -1;
    }
    content = read_file_content(argv[1]); 
    bool flag = false; 
    int s = -1;
    for (int i = 0; i < (int) content.length(); i++) 
    {
        if (line >= c.start_line && line <= c.end_line) 
        {
            int a = content[i];
            if (a == 32) 
            {
                line_length++; 
            }
            if (a != 32 && (line_length < c.space)) 
            {
                content.insert(i, " ");
                line_length++; 
            }
    
            // this line of code that removes extra indent than specified 
            //bug
            
            // if (line_length > c.space && flag == false) 
            // {
            //     if (s == -1) 
            //     {
            //         content.erase( 0, (line_length - c.space)  );
            //         flag = true; 
            //     } else 
            //     {
            //         content.erase( s + 1, line_length - c.space);
            //         flag = true; 
            //     }
            //     line_length = c.space; 
            // }

            if (content[i] == '\n')
            {
                line_length = 0;
                flag = false;  
                s = i; 
            }
        } else if (line > c.end_line) 
        {
            break;
        }
        if (content[i] == '\n') 
        {
            line++; 
        }
    }
    write_file(argv[1], content); 
    return 0; 
}

void write_file(char *name, std::string content) 
{
    std::ofstream file(name, std::ios::out);
    
    file << content; 
    file.close(); 
    return; 
}

std::string read_file_content(char *name) 
{
    std::string content; 
    std::ostringstream ss;

    std::ifstream file(name, std::ios::in); 
    if (!file) 
    {
        printf("no file with found\n"); 
        exit(1);
    }
    ss <<  file.rdbuf();
    content = ss.str();
    file.close();
    return content; 
}