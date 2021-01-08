#ifndef INORD_LIST_H_INCLUDED
#define INORD_LIST_H_INCLUDED
#include <iostream>
using namespace std;
typedef string listelemtype;
class inord_list
{
    public :    inord_list();
                bool first(listelemtype &e,int &c, int li[]);
                bool insert1( listelemtype &e,int l);
                bool next(listelemtype &e, int &c,int li[]);

    private :   struct node;
                typedef node* link;
                struct node
                {
                    listelemtype elem;
                    int line[1000];
                    int acc=1;
                    link next;
                };
                link head,tail,current,pred;
};


#endif // INORD_LIST_H_INCLUDED
