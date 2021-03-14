#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
   ifstream testFile("../../testFile.cpp");
   string code = "start reading";
   string toReplace = "word";
   if(testFile){
        cout << "--------------------------------------\n" << code << endl << "--------------------------------------" << endl;
        while(!testFile.eof()){
            getline(testFile,code);
            if(code.find(toReplace) != string::npos){
                code.replace(code.find(toReplace),toReplace.length(),"slowo");
            }
            cout << code << endl;
        }
   }
   else{
       cout << "Cannot open file!" << endl;
   }
    testFile.close();
    return 0;
}