#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class students {
  string fname;
  string lname;
  float mark;
  public :
    students(string a,string b,float c){
      fname=a;
      lname=b;
      mark=c;
    }
    students(){}
    void show(){
      cout<<"[ "<<setw(10)<<fname<<" "<<setw(15)<<lname<<"    : "<<setw(10)<<mark<<" ]"<<endl;
    }
    float getmark(){
      return mark;
    }
};
int main(){
  int n;
  string a,b;
  float c;
  cout<<"Number of students : ";
  cin>>n;
  students *student=new students[n];
  for (int i=0;i<n;i++){
    cout<<"Enter the student number "<<i+1<<" information : ";
    cin>>a>>b>>c;
    student[i]=students(a,b,c);
    student[i].show();
  }
  float x,y;
  students temp;
  for (int i=0;i<n-1;i++){
    x=student[i].getmark();
    y=student[i+1].getmark();
    if (x<y){
      cout<<endl<<x<<" *** "<<y<<" *** "<<i<<endl;
      temp=student[i];
      student[i]=student[i+1];
      student[i+1]=temp;
      if (i>0){
        i--;
        i--;
      }
    }
  }
  for (int i=0;i<n;i++){
    student[i].show();
  }
  return 0;
}
