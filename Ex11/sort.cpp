#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<class Ran>
bool operator<(Ran a, Ran b){
    if(a<b) return true;
    else return false;
}

template<class Ran>
void sort(Ran first, Ran end) {

    Ran iterator1, iterator2;
    Ran tmp;

    for(iterator1=first; iterator1!=end; ++iterator1){
        for(iterator2=first; iterator2<iterator1; ++iterator2){
            if(*(iterator2+1)<*(iterator2)) {
                swap(*iterator2, *(iterator2+1));
                //*tmp=*iterator2;
                //*iterator2=*(iterator2+1);
                //*(iterator2+1)=*tmp;
            }
        }
    }
}

int main() {

    vector<int> vt = {324,5,45,34,23,2,0,53,753,7,3543,1};

    sort(vt.begin(), vt.end());

    for(auto elem: vt){
        cout << elem << endl;
    }

    return 0;
}