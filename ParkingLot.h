#include <bits/stdc++.h>
using namespace std;

class ParkingLot
{
private:
	int MAX_SIZE = 0; //stores number of slots in the parking lot
	int currentCars = 0; //stores number of cars parked currently in the lot

	//method to check if the parking lot is full before parking a new car
	bool isFull()
	{
		if (currentCars == MAX_SIZE)
			return true;

		else
			return false;
	}

	//method to check if the parking lot is empty
	bool isEmpty()
	{
		if (currentCars == 0 and MAX_SIZE != 0)
			return true;
		else
			return false;
	}

public:

	vector<int> slots; //this will store whether a slot is empty or occupied.
	//If a slot is available for parking than slots[i] = 0 , else slots[i] = 1 (occupied)

	map <int, pair<string , string> > slotDetails; //we will map car's registeration number and colour with slot number

	/*
	Note : All the below methods are implemented in ParkingLot.cpp file
	*/
        priority_queue<int, vector<int>, greater<int> > q;
	
	void createParkingLot(int n); //method to create a parking lot with n slots

	void park(string regNo , string colour); //method to park a car with a given registration no and colour

	void getSlotNumbersFromcolour(string colour); //method to get all slot numbers in which car is parked by colour

	void getSlotNumberFromRegNo(string regNo); //method to get slot no where car with given number is parked

	void leave(int slotNo); //method to vacate a slot

	void getRegistrationNumbersFromcolour(string colour); //method to get registration no of all cars parked by colour
	void display();//method to display all the vehicles are parked 
};
