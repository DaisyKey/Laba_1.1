#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

template <typename T>
T Checking(T min, T max, string n)
{
	T x;
	cout << n;
	while ((cin >> x).fail() || x > max || x < min)
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
	system("cls");
	cout << "ADD PIPE'S DATA" << endl;
	pipe p;
	p.id = 1;
	p.lenght = Checking(0, 1000, "\n Input Length:");
	p.diametr = Checking(0, 1000, "\n Input diametr:");
	p.repair_status = Checking(0, 1, "\n Input repair status: (0 - isn't repairing ; 1 - is repairing): ");
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
	system("cls");
	cout << "ADD STAITION'S DATA" << endl;
	Station st;
	st.id = 1;
	cout << "\n Input station name:" << endl;
	cin.ignore(10000, '\n');
	getline(cin, st.name);
	st.workshop = Checking(1, 10000, "\n Input workshop's numbers :");
	st.busy_workshop = Checking(0, st.workshop, "\n Input busy workshop numbers :");
	st.effection = Checking(1, 100, "\n Input Effection:");
	return st;
};

bool Number(char Symbol)
{
	if (Symbol >= '0' && Symbol <= '9')
		return true;
	return false;
};


void main_menu()
{
	cout << "\n1_Pipe" << endl;
	cout << "2_Station" << endl;
	cout << "3_Look" << endl;
	cout << "4_Edit Pipe" << endl;
	cout << "5_Edit station(Numbers of workshops)" << endl;
	cout << "6_Save" << endl;
	cout << "7_Browse" << endl;
	cout << "0_exit" << endl;
}

void viewpipe(const pipe& p, bool is_pipe)
{   
	system("cls");
	if (is_pipe == true) {
		cout << "ID:" << p.id << endl;
		cout << "Length:" << p.lenght << endl;
		cout << "Diametr:" << p.diametr << endl;
		cout << "repair status:" << p.repair_status << endl;
		cout << "Input any symbol to return to main menu: ";
	}
	else {
		cout << "Pipes didn't create!" << endl << "Input any symbol to return to main menu: " << endl;
	}
}

void viewStation(const Station& st, bool is_staition)
{
	system("cls");
	if (is_staition == true) {
		cout << "ID:" << st.id << endl;
		cout << "Name:" << st.name << endl;
		cout << "Workshop:" << st.workshop << endl;
		cout << "Busy Workshops:" << st.busy_workshop << endl;
		cout << "Effection:" << st.effection << endl;
		cout << "Input any symbol to return to main menu: ";
	}
	else {
		cout << "Staitions didn't create!" << endl << "Input any symbol to returning to main menu: " << endl;
	}
}

void viewall(int q, const pipe& p, const Station& st, bool is_staition, bool is_pipe)
{
	string s;
	switch (q)
	{
	case 1:
		viewpipe(p, is_pipe);
		cin >> s;
		system("cls");
		break;
	case 2:
		viewStation(st, is_staition);
		cin >> s;
		system("cls");
		break;
	}
}

void editpipe(pipe& p)
{
	system("cls");
	if (p.repair_status == 0)
	{
		p.repair_status = 0;
		cout << "\n Pipe isn't repairing now"<< endl;
	}
	else
	{
		p.repair_status = 1;
		cout << "\n Pipe is repairing now"<< endl;
	}

	p.repair_status = Checking (0, 1, "\n Change repair_status: 1 - repairng ; 0 - isn't repairing: ");
	system("cls");
	cout << "Pipe's Repair status was changed!" << endl;

};

void editStation(Station& st)
{
	system("cls");
	cout << "\nAll workshops count:" << st.workshop << endl;
	cout << "\nBusy workshops count:" << st.busy_workshop << endl;
	int choise;
	choise = Checking (0, 1, "\nInput 1 for count+ or 0 for count- : ");
	do
	{
		if (choise == 1 && st.busy_workshop < st.workshop)
		{
			st.busy_workshop += 1;
		}
		else if (choise == 0 && st.busy_workshop > 0)
		{
			st.busy_workshop -= 1;
		}


	} while (cin.fail() || Number(int(choise)));
	system("cls");
	cout << "Staition's parameters were changed!" << endl;
};

void savepipe(const pipe& p, ofstream& fout)
{
	system("cls");
	if (fout.is_open())
	{
		fout << p.id << endl
			<< p.lenght << endl
			<< p.diametr << endl
			<< p.repair_status << endl;
	}
}

void saveStation(const Station& st, ofstream&fout)
{
	if (fout.is_open())
	{
		fout << st.id << endl
			<< st.name << endl
			<< st.workshop << endl
			<< st.busy_workshop << endl
			<< st.effection << endl;
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

	pipe p;
	Station st;
	bool is_pipe = false;
	bool is_staition = false;
	while (1)
	{
		main_menu();
		switch (Checking(0, 7, "MAIN MENU:"))
		{
		case 1:
		{ 
			p = createpipe();
			is_pipe = true;
			system("cls");
			cout << "Pipe was added!" << endl << "Returning to main menu..." << endl;
			break;
		}
		case 2:
		{
			st = createStation();
			is_staition = true;
			system("cls");
			cout << "Staition was added!" << endl << "Returning to main menu..." << endl;
			break;
		}
		case 3:
				{
					cout << "\n Choose 1 - pipe ; 2 - station "<< endl;
					int q = 0;
					cin >> q;
				    viewall(q, p, st, is_staition, is_pipe);
				}
				cout << "Returning to main menu..." << endl;
			break;
		case 4:
		{
			if (is_pipe == true)
			{
				editpipe(p);
		
			}
			else {
				system("cls");
				cout << "You didn't add any pipes!" << endl;
			
			}
			cout << "Returning to main menu..." << endl;
			break;
		}
		case 5:
		{
			if (is_staition == true)
			{
				editStation(st);
				
			}
			else {
				system("cls");
				cout << "You didn't add any staitions!" << endl;
			}
			cout << "Returning to main menu..." << endl;
			break;
		}
		case 6:
		{system("cls");
			if (!is_pipe && !is_staition)
			{
				cout << "No Data" << endl;
				cout << "Returning to the main menu..." << endl;
				break;
			}
			ofstream fout;
			fout.open("all.txt", ios::out);
			if (!fout.is_open())
			{
				cout << "Save failed" << endl << "Returning to the main menu..." << endl;
				break;
			}
			fout << is_pipe << endl;
			if (is_pipe)
				savepipe(p, fout);
			
			fout << is_staition << endl;
			if (is_staition)
				saveStation(st, fout);
			fout.close();

			cout << "Data was saved!" << endl << "Returning to the main menu..." << endl;
			break;

		}
		case 7:
		{
			system("cls");
			ifstream fin;
			fin.open("all.txt", ios::in);
			if (!fin.is_open())
			{
				cout << "Load failed!" << endl << "Returning to the main menu... " << endl;
				break;
			}
			fin >> is_pipe;
			if (is_pipe)
				p = browsepipe(fin);
			fin >> is_staition;
			if (is_staition)
				st = browseStation(fin);
			fin.close();
			cout << "Data was loaded!" << endl << "Returning to the main menu..." << endl;
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Error";
		}
		}
	}
	return 0;
}
