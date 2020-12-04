#include <iostream>
#include<string>
class login
{
public:
    login(){std::cout<<"123"<<std::endl;}

};

class ssh_login:login {
public:
    ssh_login(int a,int b){
      std::cout<<"456"<<std::endl;
    }
};

int main(){
  ssh_login sl(1,1);
  return 0;
}