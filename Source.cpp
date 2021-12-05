#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

template <typename T>
T proverka(T min, T max , string n)
T Checking(T min, T max, string n)
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

void viewpipe(const pipe& p)
{
	cout << "ID:" << p.id << endl;
	cout << "Length:" << p.lenght << endl;
	cout << "Diametr:" << p.diametr << endl;
	cout << "repair status:" << p.repair_status << endl;
}

void viewStation(const Station& s)
{
	cout << "ID:" << s.id << endl;
	cout << "Name:" << s.name << endl;
	cout << "Workshop:" << s.workshop << endl;
	cout << "Busy Workshops:" << s.busy_workshop << endl;
	cout << "Effection:" << s.effection << endl;
}

void viewall(int q, const pipe& pi, const Station& st)
{
	switch (q)
	{
	case 1:
		viewpipe(pi);
		break;
	case 2:
		viewStation(st);
		break;
	}
}

void editpipe(pipe& p)
{
	if (p.repair_status == 0)
	{
		p.repair_status = 0;
		cout << "\n Pipe isn't repairing now";
	}
	else
	{
		p.repair_status = 1;
		cout << "\n Pipe is repairing now";
	}

	p.repair_status = Checking (0, 1, "\n'Change repair_status: 1 - repairng ; 0 - isn't repairing");

};

void editStation(Station& s)
{
	cout << "\n 3_ All workshops count:" << s.workshop;
	cout << "\n 2_ Busy workshops count:" << s.busy_workshop;
	int choise;
	choise = Checking (0, 1, "\n'Input 1 for count+ or 0 for changing workshops count: ");
	do
	{
		if (choise == 1 && s.busy_workshop < s.workshop)
		{
			s.busy_workshop += 1;
		}
		else if (choise == 0 && s.busy_workshop > 0)
		{
			cout << " Busy workshop count (-) \n";
			s.busy_workshop -= 1;
		}
		else
		{
			cout << "impossible" << endl;
		}


	} while (cin.fail() || Number(int(choise)));
};

void savepipe(const pipe& p, ofstream& fout)
{
	if (fout.is_open())
	{
		fout << p.id << endl
			<< p.lenght << endl
			<< p.diametr << endl
			<< p.repair_status << endl;
	}
}

void saveStation(const Station& s, ofstream&fout)
{
	if (fout.is_open())
	{
		fout << s.id << endl
			<< s.name << endl
			<< s.workshop << endl
			<< s.busy_workshop << endl
			<< s.effection << endl;
	}
}

pipe browsepipe(ifstream& fin)
{
	if (fin.is_open())
	{
		pipe p;
		fin >> p.id;
		fin >> p.lenght;
		fin >> p.diametr;
		fin >> p.repair_status;
		return p;
	}
	return {};
};

Station browseStation(ifstream& fin)
{
	if (fin.is_open())
	{
		Station s;
		fin >> s.id;
		fin >> s.name;
		fin >> s.workshop;
		fin >> s.busy_workshop;
		fin >> s.effection;
		return s;
	}
	return {};
}


int main()
{
	main_menu();
	system("Pause");

}
