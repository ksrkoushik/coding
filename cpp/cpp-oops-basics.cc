//this line includes input-output stream library which is necessary for handling input and output operations
#include <iostream>

//this line includes string library which is used for string manipulation
#include <string>

//this line avoids std:: before the standard library functions and objects
using namespace std;

//Define a class Car

//this line defines a class named 'Car' which encapsulates the properties and behaviors of a car
class Car
{
	//Access specifier 'private' restricts access to these members to within the class
	//this keyword specifies that the members ('brand', 'model' and 'year') declared after 
	//it are accessible only within class.
	private:
		//these lines declare data members of the class 'Car' representing the brand, model and year of the car
		string brand;
		string model;
		int year;
	
	//Access specifier 'public' allows access to these members from outside the class
	//this keyword specifies that the members ('car()', 'displayInfo()', 'getBrand()' and 'setYear') declared after it
	//are accessible from outside the class.
	public:
		// Constructor to initialize object of class 'Car'
		// this is a constructor for the 'Car' class used to initialize objects of the class with 
		// given values for brand, model and year of the car
		Car(string b, string m, int y)
		{
			brand = b;
			model = m;
			year = y;
		}
	
		// Method to display Car information
		// this is a member function of the car class used to display infon about the car
		void displayInfo()
		{
			cout << "Brand: "<< brand <<"\n";
			cout << "Model: "<< model <<"\n";
			cout << "Year: "<< year <<"\n";
		}

		//Getter Method for Brand
		//this is a member function of the 'Car' class used to retrieve the brand of the car
		string getBrand()
		{
			return brand;
		}

		//Setter Method for Year
		//this is a member function of the 'Car' class used to set the year of the car 
		void setYear(int y)
		{
			year = y;
		}

};

//this is the main function where the program execution begins
int main()
{
	//Create an object "myCar" of class "Car" using parameterized constructor
	//this line creates an object named "myCar" of class "Car" using the constructor initializing with 
	//brand "Toyota", model "Camry" and year 2020.
	Car myCar("Toyota", "Camry", 2020);

	//Display Car Information
	cout << "Car Information: "<<"\n";
	//this line calls the "displayInfo()" member function of the "myCar" object displaying its information
	myCar.displayInfo();

	//Accessing and Modifying class members using getter and setter methods
	cout << "\nChanging the year..."<< "\n";
	//this line calls the "setYear()" member function of the "myCar" object to change its year to 2021
	myCar.setYear(2021);

	//Display updated Car information
	cout << "\nUpdated Car Information: "<< "\n";
	//this line calls the "displayInfo()" member function of the "myCar" object displaying teh updated information
	myCar.displayInfo();
	//this line indicates the successful termination of the program
	return 0;
}
	
