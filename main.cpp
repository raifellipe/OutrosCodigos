#include <iostream>
#include <string>
#include <vector>
#define N 5
using namespace std;
bool compara(int a, int b){
    return(a==b?true:false);
}
bool contido(vector<int> x, int y){
    for(int i=0;i<x.size(); i++)
        if(!compara(x[i],y))return false;
    return true;
}
int reseta(int x1, int x0){
    if(!compara(x1+1, x0))
        return(((x1+1)>(N-1))?0:x1+1);
    else
        return(((x1+2)>(N-1))?0:x1+2);
}
void combina (vector<string> &mat, int x){
    int f=mat.size();
   for(int i=0; i<N-1; i++){
        for(int j=x; j<f; j++)
        {
            if(i!=j)
                mat.push_back(mat[i]+mat[j]);
        }
   }
}
void combina2 (vector<string> &mat, int x){
    int f=mat.size();
   for(int i=0; i<N-1; i++){
        for(int j=x; j<f; j++)
        {
            if(i!=j)
                mat.push_back(mat[j]+mat[i]);
        }
   }
}
void imprime(vector<string> mat){
    for(int i=0; i<mat.size(); i++)
        cout<<mat[i]<<endl;
}
int main()
{
    vector<string> a;
    a.push_back("a");
    a.push_back("b");
    a.push_back("c");
    a.push_back("d");
    a.push_back("e");
    combina(a,0);
    combina2(a,N-1);
    imprime(a);
    return 0;
}
