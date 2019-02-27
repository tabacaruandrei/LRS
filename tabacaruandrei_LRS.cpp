#include<fstream>
#include<iostream>
using namespace std;
int n;

typedef struct
{int info;
int stang;
int drept;} nod;

nod v[100];

fstream f("input.dat",ios::in);
fstream g("output.dat",ios::out);

int read_data()
{
f>>n;
for(int i=1;i<=n;i++)
{
    f>>v[i].info;
}
for(int i=1;i<=n;i++)
{
    f>>v[i].stang;
}
for(int i=1;i<=n;i++)
{
    f>>v[i].drept;
}
f.close();
return 0;}

void print_RSD(int node){
    g << v[node].info << " ";

    int left_child = v[node].stang;
    if(left_child != 0) print_RSD(left_child);

    int right_child = v[node].drept;
    if(right_child != 0) print_RSD(right_child);
}

void print_SRD(int node){


    int left_child = v[node].stang;
    if(left_child != 0) print_SRD(left_child);

    g << v[node].info << " ";

    int right_child = v[node].drept;
    if(right_child != 0) print_SRD(right_child);
}

void print_SDR(int node){

    int left_child = v[node].stang;
    if(left_child != 0) print_SDR(left_child);

    int right_child = v[node].drept;
    if(right_child != 0) print_SDR(right_child);

    g << v[node].info << " ";
}

int main()
{read_data();
 print_RSD(1); g<<endl;
 print_SRD(1); g<<endl;
 print_SDR(1);
 }
