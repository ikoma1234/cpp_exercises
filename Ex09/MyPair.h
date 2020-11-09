template<class T1, class T2>

class MyPair {
    public:
        MyPair(T1 boo, T2 boo2):first(boo), second(boo2){}
        T1 first;
        T2 second;
};