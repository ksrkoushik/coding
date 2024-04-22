//examples of classes
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
	int price, eng_cap;
	float mileage;
    public:
	Vehicle (int,int,float);
	void veh_data()
	{
		cout << "Vehicle price is: " << price << "\n";
		cout << "Vehicle engine capacity is: " << eng_cap << "\n";
		cout << "Vehicle Mileage is: " << mileage << "\n";
	}
};

Vehicle::Vehicle (int a, int b, float c)//Constructor
{
	price = a;
	eng_cap = b;
	mileage = c;
}

int main(int argc, char *argv[])
{
	Vehicle Car (500000, 1200, 17.5);
	Vehicle Truck (800000, 1600, 12.3);
	Car.veh_data();
	Truck.veh_data();
	return 0;
}
