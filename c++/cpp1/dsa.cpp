#include <iostream>
using namespace std;
class human{
    private:
    int age;
    int height;
    int weight;
};
class child : public human{
    public: 
    string colour;

};

int main()
{
    child c;
    cout << c.colour << endl;
   
      return 0;
}
