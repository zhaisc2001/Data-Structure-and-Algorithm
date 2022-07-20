#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

//Time complexity is O(n)
bool GetItem(LinkList *L, int i, int *e){
    LinkList p = *L;
    int j = 1;
    while(j<i && p){
        p = p->next;
        ++j;
    }
    if(j>i || !p){
        return false;
    }
    *e = p->data;
    return true;
}
//Time complexity of insert and delte is O(1)
bool ListInsert(LinkList *L, int i, int e){
    LinkList p = *L;
    int j = 1;
    LinkList s;
    while(j<i && p){
        p = p->next;
        ++j;
    }
    if(j>i || !p){
        return false;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->next = p->next;
    s->data = e;
    p->next = s;
    return true;
}

bool ListDelete(LinkList *L, int i, int *e){
    LinkList p = *L;
    int j = 1;
    while(j<(i-1) && p){
        p = p->next;
        ++j;
    }
    if(j>(i-1) || !(p->next->next)){
        return false;
    }
    LinkList d = p->next;
    *e = d->data;
    p->next = d->next;
    free(d);
    return true;

}


int main(){
    return 0;
}
