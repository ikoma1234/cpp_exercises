#include <iostream>
#include <iterator>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    istream_iterator<int> itr_i(cin);
    istream_iterator<int> 
    
    ostream_iterator<int> itr_o("numbers.txt");
    for(int i = 0; i < 2; i++){
        if( (*itr_i)%3 == 0 && (*itr_i)%5 != 0 ) {
            itr_o = *itr_i;
        }
        ++itr_i;
    }
    return 0;
}