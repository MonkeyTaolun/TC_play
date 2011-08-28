#include <iostream>
#include <vector>

using namespace std;

class FortunateNumbers {
public:
int isFortunate(int num){
  int save = 0;
  while(num != 0){
    if(num % 10 != 5 && num % 10 != 8) return -1;
    if(num % 10 == 8) save += 1;
    else save += 2;
    save *= 3;
    
    num /= 10;
  }
  return save;
}
int getFortunate(vector<int> a, vector<int> b, vector<int> c) {
  int save[729];
  for(int i = 0; i < 729; ++i) {
    save[i] = 0;
  }
  for(int i = 0; i < a.size(); ++i){
    for(int j = 0; j < b.size(); ++j){
      for(int k = 0; k < c.size(); ++k){
        int result  = isFortunate(a[i] + b[j] + c[k]);
        if(result > -1) save[result] = 1;
      }
    }
  }
  int total = 0;
  for(int i = 0; i < 729; i++) {
    if(save[i]) total++;
  }
  return total;
}
};
