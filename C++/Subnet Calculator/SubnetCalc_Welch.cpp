#include <iostream>
using namespace std;

void classful(int ipe[], int slashe)
{

	if (ipe[0] < 127)
	{
		cout << "Class: A" << endl;
		cout << "Classful Net Address: " << ipe[0] << ".0.0.0"<<endl;
		cout << "Classful Broadcast Address: " << ipe[0] << ".255.255.255" << endl;
		cout << "Number of Subnets Given this mask: ";
		if ((8 - slashe)<0)
			cout << (8 - slashe)*-1<< endl;
		else
			cout << (8 - slashe)<< endl;
	}
	else if (ipe[0] >191)
	{
		cout << "Class: C" << endl;
		cout << "Classful Net Address: " << ipe[0] << "." << ipe[1] << "." << ipe[2] << ".0"<<endl;
		cout << "Classful Broadcast Address: " << ipe[0] << "." << ipe[1] << "." << ipe[2] << ".255"<<endl;
		cout << "Number of Subnets Given this mask: ";
		if ((24 - slashe)<0)
			cout << (24 - slashe)*-1 << endl;
		else
			cout << (24 - slashe) << endl;
	}
	else
	{
		cout << "Class: B" << endl;
		cout << "Classful Net Address: " << ipe[0] << "." << ipe[1] << ".0.0"<<endl;
		cout << "Classful Broadcast Address: " << ipe[0] << "." << ipe[1] << ".255.255"<<endl;
		cout << "Number of Subnets Given this mask: ";
		if ((16 - slashe)<0)
			cout << (16 - slashe)*-1 << endl;
		else
			cout << (16 - slashe) << endl;
	}

};

void subnetmask(int ipe[], int slashe)
{

	int subnetmsk[4];
	int subnet[4];
	int oct = 0;
	int bit = 128;
	int sl = slashe;
	while (slashe >= 8)
	{
		subnetmsk[oct] = 255;
		slashe -= 8;
		oct++;
	};
	subnetmsk[oct] = 0;
	while(slashe > 0)
	{
		subnetmsk[oct] += bit;
		bit /= 2;
		slashe--;
	}
	oct++;
	while (oct <= 3)
	{
		subnetmsk[oct] = 0;
		oct++;
	};

	cout << "Subnet Mask: ";
	for (int i = 0; i < 4; i++)
	{
		cout << subnetmsk[i];
		if (i != 3)cout << ".";
	};
	cout << endl;

	oct = 0;
	cout << "Subnet: ";
	while (subnetmsk[oct] == 255)
	{
		subnet[oct] = ipe[oct];
		cout << subnet[oct];
		if (oct != 3)cout << ".";
		oct++;
	}
	if (subnetmsk[oct] > 0)
	{
		subnet[oct] = ipe[oct] & subnetmsk[oct];
		cout << subnet[oct] << ".";
		oct++;
	}
	while (oct <= 3)
	{
		subnet[oct] = 0;
		cout << subnet[oct];
		if (oct != 3)cout << ".";
		oct++;
	}

	cout << endl;
	cout << "First Host: ";
	for (int i = 0; i < 4; i++)
	{
		if (i != 3)
			cout << subnet[i];
		else
			cout << (subnet[i] + 1);
		if (i != 3)cout << ".";
	};
	cout << endl;

	cout << "Last Host: ";
	int lasthost[4];
	oct = 0;
	while (subnetmsk[oct] == 255)
	{
		lasthost[oct] = subnet[oct];
		cout << lasthost[oct];
		if (oct != 3)cout << ".";
		oct++;
	}
	if (subnetmsk[oct] > 0)
	{
		if (oct != 3)
		{
			lasthost[oct] = (255 ^ subnetmsk[oct]);
			lasthost[oct] += subnet[oct];
			cout << lasthost[oct];
		}
		else
		{
			lasthost[oct] = (255 ^ subnetmsk[oct])-1;
			lasthost[oct] += subnet[oct];
			cout << lasthost[oct];
		}
		if (oct != 3)cout << ".";
		oct++;
	}

	while (oct <= 3)
	{
		if (oct != 3)
			lasthost[oct] = 255;
		else
			lasthost[oct] = (255 - 1);
		cout << lasthost[oct];
		if (oct != 3)cout << ".";
		oct++;
	}
	cout << endl;

	cout << "Subnet Broadcast: ";
	for (int i = 0; i < 4; i++)
	{
		if (i != 3)
			cout << lasthost[i];
		else
			cout << (lasthost[i] + 1);
		if (i != 3)cout << ".";
	};
	cout << endl;

	if ((ipe[0] != subnet[0] || ipe[1] != subnet[1] || ipe[2] != subnet[2] || ipe[3] != subnet[3]) && (ipe[0] != lasthost[0] || ipe[1] != lasthost[1] || ipe[2] != lasthost[2] || ipe[3] != lasthost[3] + 1))
	{
		cout << "This is a Valid Host" << endl;
	}
	else
	{
		cout << "This is not a Valid Host" << endl;
	}
	cout << endl;

	cout << "Number of usable hosts: (2^" << (32 - sl) <<")-2"<< endl;

};

int main()
{
	int ip[4];
	int slash;
	cout << "Enter the IP address you wish to find subnets for, hit enter after"<<endl<<"each octet." << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> ip[i];
	};

	cout << "Enter the slash notation number: ";
	cin >> slash;
	cout << endl;
	cout << "Your IP address: ";
	for (int i = 0; i < 4; i++)
	{
		cout << ip[i];
		if (i != 3)cout << ".";
	};
	cout << "/" << slash << endl<<endl;

	classful(ip,slash);
	cout << endl;
	subnetmask(ip,slash);



	return 0;
}