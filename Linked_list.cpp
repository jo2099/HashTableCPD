#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

typedef struct player //estrutura do jogador
{
    int id;
    string name;
    string position;
}PLAYER;


class Linked_list
{
private:
    struct Node //estrutura do nó
    {
        PLAYER player;
        Node *next;
    };
    Node *head; //cabeça da lista
    Node *tail; //cauda da lista
    int size; //tamanho da lista
public:
    Linked_list();
    void add(PLAYER player);
    void remove(PLAYER player);
    PLAYER get_player(int id);
    PLAYER get_player(int id,int &num_testes);
    void print_list();
    ~Linked_list();
};

void Linked_list::print_list()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->player.id << " " << current->player.name << " " << current->player.position<<" -> ";
        current = current->next;
    }
}


PLAYER Linked_list::get_player(int id)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->player.id == id)
        {
            return current->player;
        }
        current = current->next;
    }
    // cout << "Player not found" << endl;
    PLAYER player;
    player.id = -1;
    player.name = "Player not found";
    return player;
}

PLAYER Linked_list::get_player(int id,int &num_testes)
{
    Node *current = head;
    while (current != NULL)
    {
        num_testes++;
        if (current->player.id == id)
        {
            return current->player;
        }
        current = current->next;
    }
    // cout << "Player not found" << endl;
    PLAYER player;
    player.id = -1;
    player.name = "Player not found";
    return player;
}

void Linked_list::remove(PLAYER player)
{
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL)
    {
        if (current->player.id == player.id)
        {
            if (previous == NULL)
            {
                head = current->next;
            }else
            {
                previous->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Player not found" << endl;
}



void Linked_list::add(PLAYER player)
{
    Node *newNode = new Node;
    newNode->player = player;
    newNode->next = NULL;
    if (head == NULL) //se a lista estiver vazia
    {
        head = newNode; //a cabeça e a cauda apontam para o novo nó
        tail = newNode;
    }else //se a lista não estiver vazia
    {
        tail->next = newNode; //a cauda aponta para o novo nó
        tail = newNode; //a cauda aponta para o novo nó como sendo a nova cauda
    }
    size++;
}

Linked_list::Linked_list(/* args */)
{
    head = NULL;
    tail = NULL;
    size = 0;
}

Linked_list::~Linked_list()
{
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
}


// int main()
// {
//     Linked_list teste;

//     teste.add({1, "Ronaldo", "Atacante"});
//     teste.add({2, "Rivaldo", "Meio-campo"});
//     teste.add({3, "Cafu", "Lateral"});
//     teste.add({4, "Roberto Carlos", "Lateral"});
//     teste.print_list();
// }
