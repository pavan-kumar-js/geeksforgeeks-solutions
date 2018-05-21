#include<iostream>
#include <fstream>
#include <istream>

using namespace std;

int main(){

    fstream fp("C:/Users/KH2138/Desktop/temp.txt",ios::out);

    if(!fp){
        cout << "File not created";
    }
    else{
        char data[100];
        cin.getline(data,sizeof(data));
        cout << "Enter text to enter into file";

        for(int i=0;data[i];i++){
            fp.put(data[i]);
        }
    }

    cout << "Current position of write pointer is " << fp.tellp() << endl << endl;
    fp.close();
    fp.open("C:/Users/KH2138/Desktop/temp.txt",ios::in);
    cout << "Current position of read pointer is " << fp.tellg() << endl << endl;

    char label;

    while(!fp.eof()){

        fp >> label;
        cout << label;

    }
    cout << endl;
    fp.close();
}