#include <iostream>
#include "inord_list.h"
using namespace std;
inord_list::inord_list()
{
    head=NULL;
    tail=NULL;
    current=NULL;
}
bool inord_list::first(listelemtype &e,int &c,int li[])
{
    if(head==NULL)return false;
    current=head;
    e=current->elem;
    c=current->acc;
    for(int i=0;i<c;i++)
        li[i]=current->line[i];
    return true;
}
bool inord_list::next(listelemtype &e,int &c,int li[])
{
    if(current==NULL||current->next==NULL) return false;
    current=current->next;
    e=current->elem;
    c=current->acc;
    for(int i=0;i<c;i++)
        li[i]=current->line[i];
    return true;
}
bool inord_list::insert1(listelemtype &e,int l)
{
    link addednode,pred;
    addednode=new node;
    if(addednode==NULL) return false;
    addednode->elem=e;
    if(head==NULL||e<head->elem)
      {
       addednode->next=head;
        head=addednode;
        head->line[(head->acc)-1]=l;
      }
      else if(e==head->elem)
      {
          (head->acc) ++;
          head->line[(head->acc)-1]=l;
      }
      else
      {
          pred=head;
          while(pred->next!=NULL&&pred->next->elem<e)
                pred=pred->next;
                if(pred->next!=NULL&&e==pred->next->elem)
                {
                    (pred->next->acc)++;
                    pred->next->line[(pred->next->acc)-1]=l;
                }
               else
               {
                    addednode->next=pred->next;
                    pred->next=addednode;
                    pred->next->line[(pred->next->acc)-1]=l;
               }
      }
      return true ;
}
