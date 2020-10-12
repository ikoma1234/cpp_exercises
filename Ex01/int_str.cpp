#include <cstdlib> // for free
#include <iostream> // for std::cout, std::endl and <<
#include "int_str.h"

char* intToStr(int x){

    int minusflag=0;

    if(x<0){
        x=-x;
        minusflag=1;
    }

    int i, j, pow10;
    char* c;
    char* c2;

    c=(char*)malloc(sizeof(char));
    c2=(char*)malloc(sizeof(char));

    for(i=0; x > 0; i++){
        c[i]=x-(x/10)*10+'0';
        x/=10;
    }

    if(minusflag==0){
        for(j=0; j<i; j++){
            c2[j]=c[i-j-1];
        }
    }
    else if(minusflag==1){
        c2[0]='-';
        for(j=1; j<i+1; j++){
            c2[j]=c[i-j];
        }
    }

    free(c);

    return c2;
}

int strToInt(char* c){

    int i=0, x=0;

    if(c[0]=='-'){
        i++;
        while ((c[i]>='0') && (c[i]<='9')){
            x=x*10;
            x+=c[i]-'0';
            i++;
        }
        x=-x;
    }
    else{
        while ((c[i]>='0') && (c[i]<='9')){
            x=x*10;
            x+=c[i]-'0';
            i++;
        }
    }

    return x;
}