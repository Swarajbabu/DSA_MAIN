#include <iostream>
#include <cmath>
using namespace std;

int bintodec(int n){
    int cp = n;
    int dec = 0;
    
    int cnt = 0;
    while(n>0){
        int dig = n%10;
        dec = dec + dig*pow(2,cnt);
        cnt++;
        n=n/10;
    }
    return dec;
}

int main(){
    int dec = bintodec(101);
    std::cout << dec << std::endl;
}



#include <iostream>
#include <cmath>
using namespace std;

int dectobin(int n){
    
    int bin = 0;
    int place = 1;
    
    while(n > 0){
        int rem = n%2;
        bin = bin + rem*place;
        place = place * 10;
        n = n/2;
    }
    return 
    bin;
}

int main(){
    int bin = dectobin(5);
    cout<<bin;
}


