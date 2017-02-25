#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int number(char a, char b){
    int num;
    num = 10*(int)(a-'0') + (int)(b-'0');
    return num;
}

int main() {
    int h, m;
    char s1[10];
    scanf("%s", s1);
    int i;

    h = number(s1[0], s1[1]);
    
    if(s1[8]=='P' && h != 12)
        h = h + 12;
    
    if(s1[0]=='1' && s1[1] == '2' && s1[8]=='A') printf("00");
    else if(h/10 == 0)
        printf("0%d",h);
    else printf("%d",h);
    
    for(i=2;i<8;i++)
        printf("%c", s1[i]);
    
    return 0;
}