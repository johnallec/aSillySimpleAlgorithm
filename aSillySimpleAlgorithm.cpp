#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    std::string s = "";
    std::string show;
    
    if(argc<=1){
        while(std::cin.good()){
            std::string str;
            std::getline(std::cin,str);
            show.append(str);
        }
    }
    else show.append(argv[1]);
    
    std::string alph= "";
    alph.append(" ");
    for(int i=33; i<256; ++i){
        std::string k=std::string(1,(char)i);
        alph.append(k);
    }
    srand(time(NULL));
    int i=0;
    while(s.compare(show)!=0){
        while(s[i]!=show[i]){
            int r = rand()%(256-33);
            std::string c= std::string(1,alph[r]);
            s.append(c);
            std::cout << "\r" << s << std::flush;
            if(s[i]!=show[i] && !s.empty())
                s.pop_back();
            usleep(800);    
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}