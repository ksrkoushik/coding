//class with an explicit constructor

#include <iostream>
#include <string>
using namespace std;
class Vehicle{
   private:
      string name;
      int cost;
      float mileage;
   public:
      Vehicle(string n, int c, float m){
         name = n;
         cost = c;
         mileage = m;
      }

      void display_Info(){
         cout << "Name: " << name << "\n";
         cout << "cost: " << cost << "\n";
         cout << "mileage: " << mileage << "\n";
      }

      void update_Info(string newname, int c, float m){
         name = newname;
         cost = c;
         mileage = m;
      }
      
};


int main(int argc, char *argv[])
{
   Vehicle veh1("Toyota", 1000000, 20.5);
   veh1.display_Info();
   veh1.update_Info("Tata", 1200000, 26.3);
   veh1.display_Info();
   Vehicle veh2("Honda", 2100000, 19.5);
   veh2.display_Info();
   veh2.update_Info("Hyundai", 2200000, 21.2);
   veh2.display_Info();
   return 0;
}

