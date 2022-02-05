#include <bits/stdc++.h>
#include "ParkingLot.h"  //this header file contains all the classes needed
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin); //input commands are read from input.txt file
	//and ouptput gets print on console

	string command;
	ParkingLot parkinglot; //creating object of class ParkingLot
	while (cin >> command)
	{
		//do as directed for each command
		if (command == "Create_parking_lot")
		{
			int n;
			cin >> n;
			parkinglot.createParkingLot(n);
		}

		else if (command == "Park")
		{
			string regno , colour;
			int colour;
			cin >> regno >> colour >> colour;
			parkinglot.park(regno , colour);
		}

		else if (command == "Slot_numbers_for_colour")
		{
			string colour;
			cin >> colour;
			parkinglot.getSlotNumbersFromcolour(colour);
		}

		else if (command == "Slot_number_for_car_with_number")
		{
			string regno;
			cin >> regno;
			parkinglot.getSlotNumberFromRegNo(regno);
		}

		else if (command == "Leave")
		{
			int slotNo;
			cin >> slotNo;
			parkinglot.leave(slotNo);
		}

		else if (command == "Vehicle_registration_number_for_colour")
		{
			string colour;
			cin >> colour;
			parkinglot.getRegistrationNumbersFromcolour(colour);
		}
	}

	return 0;
}