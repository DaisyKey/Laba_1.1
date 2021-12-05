#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

template <typename T>
T proverka(T min, T max , string n)
{
	T x;
	cout << n;
	while ((cin > x).fail() || x > max || x < min)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << n;
	}
	return x;
}

struct pipe
{
	int id;
	int lenght;
	int diametr;
	bool repair_status;
};

pipe createpipe()
{
	pipe p;
	p.id = 1;
	p.lenght = Checking(0, 1000, "\n'Input Length:");
	p.diametr = Checking(0, 1000, "\n'Input diametr:");
	p.repair_status = Checking(0, 1, "\n'Input repair status:");
	return p;
};


struct Station
{
	int id;
	string name;
	int workshop;
	int busy_workshop;
	float effection;

};

Station createStation()
{
	Station s;
	//s.is_station == true;
	s.id = 1;
	cout << "Input station name:" << endl;
	cin.ignore(10000, '\n');
	getline(cin, s.name);
	s.workshop = Checking(1, 10000, "\n'Input workshop's numbers :");
	s.busy_workshop = Checking(0, s.workshop, "\n'Input busy workshop numbers :");
	s.effection = Checking(1, 100, "\n'Input Effection:");
	return s;
};

bool Number(char Symbol)
{
	if (Symbol >= '0' && Symbol <= '9')
		return true;
	return false;
};


void main_menu()
{
	cout << "1_Pipe" << endl;
	cout << "2_Station" << endl;
	cout << "3_Look" << endl;
	cout << "4_Edit Pipe" << endl;
	cout << "5_Edit station(Numbers of workshops)" << endl;
	cout << "6_Save" << endl;
	cout << "7_Browse" << endl;
	cout << "0_exit" << endl;
}


int main()
{
	main_menu();
	system("Pause");

}
