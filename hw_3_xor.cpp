#include <stdlib.h>
#include <iostream>
#include <random>
using namespace std;

vector<int> Trans(int );
int main(){

    int key=114;
    int message=rand()%514;

}
vector<int> Trans(int n){
    vector<int > bn;
    for(int i=31;i>=0;i--){
        bn.push_back((n>>i)&1);
    }
}