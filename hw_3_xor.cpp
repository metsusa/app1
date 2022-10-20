#include <stdlib.h>
#include <iostream>
#include <random>
#include <math.h>
using namespace std;

vector<int> Trans(int );
int transBack(vector<int> );
int decode(int ,int );

int main(){

    int key=114;
    int message=514;
    int cipher=message^key;
    message=decode(cipher,key);
    cout<<"the cipher is:"<<cipher<<endl;
    cout<<"the real message is:"<<message<<endl;

}
vector<int> Trans(int n){
    vector<int > bn;
    for(int i=31;i>=0;i--){     //将整型转化为32位的二进制容器
        bn.push_back((n>>i)&1);
    }
    return bn;
}
int transBack(vector<int > bn){
    int n=0;
    for(int i=0;i<32;i++){      //整型32位，将32位的二进制容器转化为十进制整型
        n+=pow(2,i)*bn.back();
        bn.pop_back();
    }
    return n;
}
int decode(int cipher,int key){     //解密函数
    vector<int > m,k,c;     //三个存放二进制表示形式的容器
    c=Trans(cipher);    //转为二进制
    k=Trans(key);       
    for(int i=0;i<32;i++){      //逆异或运算
        if(c[i]==1){
            m[i]=!k[i];
        }
        else{
            m[i]=k[i];
        }
    }
    return transBack(m);        //转化为int类型再输出结果
}