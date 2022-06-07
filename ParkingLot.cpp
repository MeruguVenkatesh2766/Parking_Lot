#include <bits/stdc++.h>
#include "ParkingLot.h"

using namespace std;

void ParkingLot :: createParkingLot(int n)
{
	//edge case - if n is less than or equal to 0
	if (n <= 0)
	{
		cout << "Invalid total slots count" << endl;
	}
	else
	{
		this -> MAX_SIZE = n;
		slots.assign(n + 1, 0); //each slot will have initial value 0 i.e all slots empty
		for(int i=1;i<=n;i++)
		{
			q.push(i);
		}	
		cout << "Created parking of " << n << " slots" << endl;
	}

}

void ParkingLot :: park(string regNo , string colour)
{
	//Edge Case 1: if park command gets executed before creating a parking lot
	if (this -> MAX_SIZE == 0)
	{
		cout << "Sorry, parking lot is not created" << endl;
	}

	//Edge Case 2: if parking lot is already full
	else if (isFull())
	{
		cout << "Sorry, parking lot is full" << endl;
	}

	else
	{
		//find first vacant slot nearest to the entry point
		int vacantSlot = q.top();
		q.pop();

		//mark that slot as occupied
		slots[vacantSlot] = 1;
		currentCars++; //increase no of cars parked in the lot

		//map car & colour details with the slot no.
		slotDetails.insert(make_pair(vacantSlot , make_pair(regNo , colour)));
		cout << "Car with vehicle registration number \"" << regNo << "\" has been parked at slot number " << vacantSlot << endl;
	}
}

void ParkingLot :: getSlotNumbersFromcolour(string colour)
{
	//Edge case: if parking lot is not created
	if (this -> MAX_SIZE == 0)
	{
		cout << "Sorry, parking lot is not created" << endl;
		return;
	}

	int flag = 0; //flag to check if there's a slot found or not

	//print all slot numbers with car parked by colour(if present)
	for (auto p : slotDetails)
	{
		if (p.second.second == colour)
		{
			flag = 1;
			cout << p.first << ", ";
		}
	}

	//Edge Case: if there's no slot, print no slot found
	if (flag == 0)
		cout << "No slot found";

	cout << endl;
}

void ParkingLot :: getSlotNumberFromRegNo(string regNo)
{
	if (this -> MAX_SIZE == 0)
	{
		cout << "Sorry, parking lot is not created" << endl;
		return;
	}
	int flag = 0;

	for (auto p : slotDetails)
	{
		if (p.second.first == regNo)
		{
			flag = 1;
			cout << p.first << endl;
			break;
		}
	}

	if (flag == 0)
		cout << "No slot found" << endl;
}

void ParkingLot :: getRegistrationNumbersFromcolour(string colour)
{
	if (this -> MAX_SIZE == 0)
	{
		cout << "Sorry, parking lot is not created" << endl;
		return;
	}

	int flag = 0;
	for (auto p : slotDetails)
	{
		if (p.second.second == colour)
		{
			flag = 1;
			cout << p.second.first << ", ";
		}
	}
	//Edge Case: if there's no car with given reg no., print not found
	if (flag == 0)
		cout << "Not found";

	cout << endl;
}

void ParkingLot :: leave(int slotNo)
{
	if (this -> MAX_SIZE == 0) {
		cout << "Sorry, parking lot is not created" << endl;
	}
	//edge case: if their is no car parked in the lot
	else if (isEmpty()) {
		cout << "Parking lot is empty" << endl;
	}
	else if (slots[slotNo] == 1)
	{
		slots[slotNo] = 0; //mark the slot as vacant
		string regNo = slotDetails[slotNo].first;
		string colour = slotDetails[slotNo].second;
		slotDetails.erase(slotNo); //erase car details from the map
		q.push(slotNo);

		cout << "Slot number " << slotNo << " vacated, the car with vehicle registration number \"" << regNo << "\" left the space, the colour " << colour << endl;
	}

	//Edge Case: if given slot no. is already empty
	else
	{
		cout << "Slot number " << slotNo << " is already empty" << endl;
	}
void ParkingLot :: display()
        {  
	        for(auto p : slotDetails)
		{
			cout<<"Slot No : "<<p.first<<", Reg No : "<<p.second.first<<", Colour of the Vehicle : "<<p.second.second<<endl;
		}
        }
	
}
