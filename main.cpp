#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include "parsing.hpp"
#include "Hash_tab.cpp"
using namespace std;
using namespace aria::csv;
// Hash_tab tabela(1000); //cria tabela hash com tamanho tam_hash
// MUDAR FUNCAO HASH, MUITO CLUSTERING

void imprime_parte1(Hash_tab &tabela_hash, ofstream &arquivo_saida)
{
    arquivo_saida << "PARTE 1: ESTATÍSTICAS DA TABELA HASH\n";
    arquivo_saida << "NUMERO DE ENTRADAS DA TABELA USADAS: " << tabela_hash.num_listas_nvazias() << endl;
    arquivo_saida << "NUMERO DE ENTRADAS DA TABELA VAZIAS: " << tabela_hash.get_size() - tabela_hash.num_listas_nvazias() << endl;
    arquivo_saida << "TAXA DE OCUPAÇÃO DA TABELA: " << (float)tabela_hash.num_listas_nvazias() / tabela_hash.get_size() << endl;
    arquivo_saida << "MINIMO TAMANHO DE LISTA: " << tabela_hash.menor_lista() << endl;
    arquivo_saida << "MAXIMO TAMANHO DE LISTA: " << tabela_hash.maior_lista() << endl;
    arquivo_saida << "MEDIO TAMANHO DE LISTA: " << tabela_hash.tamanho_medio_listas() << endl;
}

void imprime_parte2(Hash_tab &tabela_hash, ofstream &arquivo_saida, ifstream &arquivo_consulta)
{
    string linha;
    PLAYER generico;
    int num_consultas = 0;
    int temp;
    int num_min_consultas = 1000000;
    int num_max_consultas = 0;
    float soma_consultas = 0;
    float media_consultas = 0;
    int cont1 = 0;
    int cont_total=0;
    float soma_consultas_total=0;
    float media_consultas_total=0;

    arquivo_saida << "\nPARTE 2: CONSULTAS\n";
    while (getline(arquivo_consulta, linha))
    {
        generico.id = stoi(linha);
        temp = generico.id;
        generico = tabela_hash.get_player(generico, num_consultas);
        if (generico.id != -1)
        {
            arquivo_saida << generico.id << " " << generico.name << " # " << num_consultas << endl;
            if (num_consultas < num_min_consultas)
            {
                num_min_consultas = num_consultas;
            }
            if (num_consultas > num_max_consultas)
            {
                num_max_consultas = num_consultas;
            }
            soma_consultas += num_consultas;
            cont1++;
        }
        else
        {
            arquivo_saida << temp << " MISS"<< " # " << num_consultas << endl;
        }
        cont_total++;
        soma_consultas_total+=num_consultas;
        num_consultas = 0;
    }
    media_consultas = soma_consultas / cont1;
    media_consultas_total=soma_consultas_total/cont_total;

    arquivo_saida<<"MINIMO NUMERO DE CONSULTAS POR NOME ENCONTRADO "<<num_min_consultas<<endl;
    arquivo_saida<<"MAXIMO NUMERO DE CONSULTAS POR NOME ENCONTRADO "<<num_max_consultas<<endl;
    arquivo_saida<<"MEDIA NUMERO DE CONSULTAS POR NOME ENCONTRADO "<<media_consultas<<endl;
    arquivo_saida<<"MEDIA "<<media_consultas_total<<endl;

}

int main()
{
    ifstream arquivo_players("players.csv");
    string nome_arq_saida;
    ifstream arquivo_consulta("consultas-fifa.txt");
    string linha;
    string generica;
    PLAYER generico;
    string res;
    CsvParser parser(arquivo_players);
    int tam_hash = 0;
    int limite = 0;
    int num_testes = 0;

    cout << "digite o tamanho da tabela: ";
    cin >> tam_hash;

    nome_arq_saida = "experimento" + to_string(tam_hash) + ".txt";
    ofstream arquivo_saida(nome_arq_saida);

    Hash_tab *tabela2 = new Hash_tab(tam_hash); // cria tabela hash com tamanho tam_hash
    parser.next_field();
    parser.next_field();
    parser.next_field();
    parser.next_field();
    for (auto row : parser) // row é um vector<string>
    {
        generico.id = stoi(row[0]);
        generico.name = row[1];
        generico.position = row[2];
        // cout<<generico.id<<" "<<generico.name<<" "<<generico.position<<endl;
        (*tabela2).add(generico);
        limite++;

        // system("pause");
    }
    cout << "Tabela carregada" << endl;
    system("pause");
    imprime_parte1(*tabela2, arquivo_saida);
    cout << "Parte 1 impressa" << endl;
    system("pause");
    imprime_parte2(*tabela2, arquivo_saida, arquivo_consulta);
    cout << "Parte 2 impressa" << endl;
    arquivo_saida.close();

    delete tabela2;
    return 0;
}