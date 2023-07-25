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
public:
    Hash_tab(int size);
    int hash_function(PLAYER player,int p); //função de hash
    void add(PLAYER player); //adiciona um jogador na tabela
    PLAYER get_player(PLAYER player); //retorna um jogador da tabela
    PLAYER get_player(PLAYER player,int &num_testes); //retorna um jogador da tabela e conta o numero de testes
    void print_tab(); //imprime a tabela
    ~Hash_tab();
};

PLAYER Hash_tab::get_player(PLAYER player)
{
    int hash=hash_function(player,P);
    return table[hash].get_player(player.id);
}
PLAYER Hash_tab::get_player(PLAYER player,int &num_testes)
{
    int hash=hash_function(player,P);
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
    int hash=hash_function(player,P);
    table[hash].add(player);
}

int Hash_tab::hash_function(PLAYER player,int p) //funcao de hash para strings USANDO O ID transformado em string
{
    //joao id 5
    //hash= 53*p^0 (53=5 em asc2)
   long long int hash=0;
    for(int i=0;i<to_string(player.id).size();i++)
    {
        hash+= (int)((int)to_string(player.id)[i]*pow(p,i)) % size;
    }
    return hash%size;
}


Hash_tab::Hash_tab(int size)
{
    this->size = size;
    table.resize(size, Linked_list()); //reserva espaço para a tabela
}

Hash_tab::~Hash_tab()
{
    table.clear();
}

// int main()
// {
//     Hash_tab hash(10);
//     vector<PLAYER> players;
//     PLAYER generico;
//     players.push_back({1,"joao","atacante"});
//     players.push_back({2,"maria","defesa"});
//     players.push_back({3,"jose","goleiro"});
//     players.push_back({4,"pedro","meio"});
//     players.push_back({5,"ana","atacante"});
//     players.push_back({6,"julia","defesa"});
//     players.push_back({7,"jorge","goleiro"});
//     players.push_back({8,"julio","meio"});
//     players.push_back({9,"juliana","atacante"});
//     players.push_back({10,"josefa","defesa"});
//     players.push_back({11,"josefina","goleiro"});
//     players.push_back({12,"josefino","meio"});
//     players.push_back({13,"josefina","atacante"});
//     players.push_back({14,"josefina","defesa"});
//     players.push_back({15,"josefina","goleiro"});
//     players.push_back({16,"josefina","meio"});
//     players.push_back({17,"cleber","atacante"});
//     players.push_back({18,"wilson","defesa"});


//     for(int i=0;i<players.size();i++)
//     {
//         hash.add(players[i]);
//     }
//     hash.print_tab();

//     return 0;
// }

