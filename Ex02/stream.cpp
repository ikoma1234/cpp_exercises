#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

    int i,j;
    string s = "data.txt";
    ifstream fin(s);

    for(i=0; i<3; i++){
        cout << setfill('-') << setw(20);
        if(i == 0 || i == 1){
            cout << "+";
        }
        else if(i>1) cout << "";
    }

    cout << endl;

    j=1;
    while (!fin.eof()) {
        string  bun= "";
        cout << setfill(' ') << setw(19) << j++ << "|";
        for(int i=0; i<2; i++){

            cout << setfill(' ') << setw(19-bun.size()+(i&1));
            fin >> bun;
            cout << bun;

            if(i == 0){
                cout << "|";
            }
            bun = "";
        }

        cout << endl;
    }
    
    return 0;
}