#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class RotatedClock {
public:

string getEarliest(int hourHand, int minuteHand){
  int min     = 9999;
  int minute  = (hourHand % 30) * 2;
  //cout << minute << endl;
  if(minuteHand % 2) minute += 1;
  for(int start = 0; start < 360; start+=30){
    int temp = (start + minuteHand) % 360;
    
    if(temp % 6 == 0) {
      temp /= 6;
      if(temp == minute) {
        int temphour = (start + hourHand) % 360 / 30;
        if(temphour * 100 + minute < min)  min = temphour * 100 + minute;
      }
    }
  }
  stringstream ss;
  if(min < 9999){
    if (min < 1000) ss <<"0";
    ss << min/100;
    ss << ":";
    if(min % 100 < 10) {
      ss << 0;
      if(min % 10) ss << min % 10;
      else ss << 0;
    }
    else ss << min % 100;    
  }
  return ss.str();
}

};


int main(){
  RotatedClock rc;
	cout << rc.getEarliest(70, 300) << endl; 
}
