#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  std::sort(pos.begin(),pos.end());
  int j=0,c=0;
  for(int i=pos[0]; i<mSize; i++){
    if(pos[j]==i){
      j++;
      c++;
    }
    else{
      mData[(i+mFront-c)%mCap]=mData[(i+mFront)%mCap];
      //std::cout<<i<<':'<<c<<' ';
    }
  }
  mSize-=pos.size();
}

#endif
