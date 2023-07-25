#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<chrono>
#include"parsing.hpp"
#include"Hash_tab.cpp"
using namespace std;
using namespace aria::csv;
Hash_tab tabela(1000);
int main()
{
    ifstream arquivo("players.csv");
    string linha;
    string generica;
    PLAYER generico;
    CsvParser parser(arquivo);
    int limite=0;
    int num_testes=0;
    parser.next_field();
    parser.next_field();
    parser.next_field();
    parser.next_field();
    for(auto row: parser) //row é um vector<string>
    {
        generico.id=stoi(row[0]);
        generico.name=row[1];
        generico.position=row[2];
        // cout<<generico.id<<" "<<generico.name<<" "<<generico.position<<endl;
        tabela.add(generico);
        limite++;
        // if(limite>=100) {break;}
    }
    cout<<"Tabela carregada"<<endl;
    system("pause");
    generico.id=0;
    auto chrono1=chrono::high_resolution_clock::now();
    cout<<tabela.get_player(generico,num_testes).name<<endl;
    auto chrono2=chrono::high_resolution_clock::now();
    cout<<"tempo em milisegundos: "<<chrono::duration_cast<chrono::milliseconds>(chrono2-chrono1).count()<<endl;
    cout<<"numero de testes: "<<num_testes<<endl;

    return 0;
}