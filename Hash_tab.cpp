#include<iostream>
#include<cstdio>
#include"Linked_list.cpp"
#include<string>
#include<vector>
#include<cmath>
#define P 59
using namespace std;
class Hash_tab
{
private:
    int size;
    vector<Linked_list> table;
    int primo; //maior primo menor que o tamanho da tabela
public:
    Hash_tab(int size);
    int hash_function(PLAYER player,int primo); //função de hash
    void add(PLAYER player); //adiciona um jogador na tabela
    PLAYER get_player(PLAYER player); //retorna um jogador da tabela
    PLAYER get_player(PLAYER player,int &num_testes); //retorna um jogador da tabela e conta o numero de testes
    void print_tab(); //imprime a tabela
    int maior_lista(); //retorna o tamanho da maior lista
    int menor_lista(); //retorna o tamanho da menor lista
    int num_listas_nvazias(); //retorna o numero de listas não vazias
    int tamanho_medio_listas(); //retorna o tamanho medio das listas
    int get_size(){return size;} //retorna o tamanho da tabela
    ~Hash_tab();
};

PLAYER Hash_tab::get_player(PLAYER player)
{
    int hash=hash_function(player,primo);
    return table[hash].get_player(player.id);
}
PLAYER Hash_tab::get_player(PLAYER player,int &num_testes)
{
    int hash=hash_function(player,primo);
    return table[hash].get_player(player.id,num_testes);
}
void Hash_tab::print_tab()
{
    for(int i=0;i<size;i++)
    {
        cout<<i<<": ";
        table[i].print_list();
        cout<<endl;
    }
}

void Hash_tab::add(PLAYER player)
{
    int hash=hash_function(player,primo);
    table[hash].add(player);
}

int Hash_tab::hash_function(PLAYER player,int primo) //funcao de hash para strings USANDO O ID transformado em string
{
    //joao id 5
    //hash= 53*p^0 (53=5 em asc2)
   return player.id%primo;
}

bool eh_primo(int numero) //verifica se um numero é primo
{
    for(int i=2;i<numero;i++)
    {
        if(numero%i==0)
        {
            return false;
        }
    }
    return true;
}

int acha_primo(int numero) //acha o maior primo menor que o numero
{ 
    int primo=numero;

    for(int i=numero;i>=0;i--)
    {
        if(eh_primo(i))
        {
            return i;
        }
    }

}

int Hash_tab::maior_lista()
{
    int maior=0;
    for(int i=0;i<size;i++)
    {
        if(table[i].get_size()>maior)
        {
            maior=table[i].get_size();
        }
    }
    return maior;
}

int Hash_tab::menor_lista()
{
    int menor=INT32_MAX;
    for(int i=0;i<size;i++)
    {
        if(table[i].get_size()<menor)
        {
            menor=table[i].get_size();
        }
    }
    return menor;
}

int Hash_tab::num_listas_nvazias()//retorna o numero de listas não vazias
{
    int num=0;
    for(int i=0;i<size;i++)
    {
        if(table[i].get_size()>0)
        {
            num++;
        }
    }
    return num;
}

int Hash_tab::tamanho_medio_listas() //retorna o tamanho medio das listas
{
    int soma=0;
    for(int i=0;i<size;i++)
    {
        if(table[i].get_size()>0)
        {
            soma+=table[i].get_size();
        }
    }
    return soma/num_listas_nvazias();
}

Hash_tab::Hash_tab(int size)
{
    this->size = size;
    table.resize(size, Linked_list()); //reserva espaço para a tabela
    this->primo=acha_primo(size);
}

Hash_tab::~Hash_tab()
{
    table.clear();
}

// int main()
// {
//     cout<< acha_primo(1000);
//     return 0;

// }
