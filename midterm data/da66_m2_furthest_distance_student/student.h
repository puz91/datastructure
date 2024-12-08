#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,typename MappedT,typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
    if(n==NULL)return -1;
    int left = my_recur(n->left,aux);
    int right = my_recur(n->right,aux);
    int current = left + 1 + right + 1;
    aux = std::max(aux,current);
    return 1 + std::max(left,right);
}

template <typename KeyT,typename MappedT,typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    int aux = -1;
    my_recur(mRoot,aux);
    return aux;
	
}

#endif
