#include <iostream>
#include <string>
using namespace std;

class Component
{
protected:
	string model;
	double price;
public:
	Component() : model("empty"), price(NULL) {}
	Component(const char* userModel, double userPrice) : model(userModel), price(userPrice) {}

	void Input()
	{
		cout << "Enter model: ";
		cin >> model;
		cout << "Enter price: ";
		cin >> price;
		cin.ignore(255, '\n');
	}
	void Print()
	{
		cout << "Model: " << model << endl;
		cout << "Price: " << price << endl;
	}
};

class Display : public Component
{
private:
	string resolution;
	int refreshRate;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter resolution: ";
		cin >> resolution;
		cout << "Enter refresh rate: ";
		cin >> refreshRate;
	}
	void Print()
	{
		Component::Print();
		cout << "Resolution: " << resolution << endl;
		cout << "Refresh rate: " << refreshRate << endl;
	}
};
class Webcam : public Component
{
private:
	string resolution;
	bool withMicrophone;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter resolution: ";
		cin >> resolution;
		int temp;
		do
		{
			cout << "Has a microphone (1 - yes, 0 - no): ";
			cin >> temp;
			if (temp == 0)
			{
				withMicrophone = false;
				break;
			}
			else if (temp == 1)
			{
				withMicrophone = true;
				break;
			}
			cout << "Error. Try again" << endl;
		} while (true);
	}
	void Print()
	{
		Component::Print();
		cout << "Resolution: " << resolution << endl;
		cout << "With microphone: ";
		if (withMicrophone)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
};
class Microphone : public Component
{
private:
	string type;
	double weight;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter type: ";
		cin >> type;
		cout << "Enter weight: ";
		cin >> weight;
	}
	void Print()
	{
		Component::Print();
		cout << "Type: " << type << endl;
		cout << "Weight: " << weight << endl;
	}
};
class Touchpad : public Component
{
public:
	void Input()
	{
		Component::Input();
	}
	void Print()
	{
		Component::Print();
	}
};
class CPU : public Component
{
private:
	double power;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter the amount of power: ";
		cin >> power;
	}
	void Print()
	{
		cout << "Model: " << model << endl;
		cout << "Power: " << power << endl;
	}
};
class GPU : public Component
{
private:
	unsigned int memory;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter the amount of memory: ";
		cin >> memory;
	}
	void Print()
	{
		Component::Print();
		cout << "Memory: " << memory << endl;
	}
};
class RAM : public Component
{
private:
	unsigned int storage;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter the amount of storage: ";
		cin >> storage;
	}
	void Print()
	{
		Component::Print();
		cout << "Storage: " << storage << endl;
	}
};
class HardDrive : public Component
{
private:
	unsigned int storage;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter the amount of storage: ";
		cin >> storage;
	}
	void Print()
	{
		Component::Print();
		cout << "Storage: " << storage << endl;
	}
};
class Battery : public Component
{
private:
	double voltage;
	unsigned int capacity;
public:
	void Input()
	{
		Component::Input();
		cout << "Enter voltage: ";
		cin >> voltage;
		cout << "Enter capacity: ";
		cin >> capacity;
	}
	void Print()
	{
		Component::Print();
		cout << "Voltage: " << voltage << endl;
		cout << "Capacity: " << capacity << endl;
	}
};
class Speaker : public Component
{
public:
	void Input()
	{
		Component::Input();
	}
	void Print()
	{
		Component::Print();
	}
};
class Mouse : public Component
{
public:
	void Input()
	{
		Component::Input();
	}
	void Print()
	{
		Component::Print();
	}
};
class Headphones : public Component
{
public:
	void Input()
	{
		Component::Input();
	}
	void Print()
	{
		Component::Print();
	}
};

class Laptop : public Component
{
private:
	CPU cpu;
	GPU gpu;
	RAM ram;
	HardDrive hd;
	Battery battery;
	Speaker speaker;
	Display display;
	Touchpad touchpad;

	Webcam* webcam;
	Headphones* headphones;
	Microphone* microphone;
	Mouse* mouse;
public:
	void Input()
	{
		Component::Input();
		cout << "\tCPU: " << endl;
		cpu.Input();

		cout << "\tGPU: " << endl;
		gpu.Input();

		cout << "\tRAM: " << endl;
		ram.Input();

		cout << "\tHD: " << endl;
		hd.Input();

		cout << "\tBattery: " << endl;
		battery.Input();

		cout << "\tSpeaker: " << endl;
		speaker.Input();

		cout << "\tTouchpad: " << endl;
		touchpad.Input();
	}
	void Print() 
	{
		cout << "\tLaptop: " << endl;
		Component::Print();

		cout << "\tCPU:\n";
		cpu.Print();

		cout << "\tGPU:\n";
		gpu.Print();

		cout << "\tRAM:\n";
		ram.Print();

		cout << "\tHard Drive:\n";
		hd.Print();

		cout << "\tBattery:\n";
		battery.Print();

		cout << "\tSpeaker:\n";
		speaker.Print();

		cout << "\tDisplay:\n";
		display.Print();

		cout << "\tTouchpad:\n";
		touchpad.Print();

		if (webcam != nullptr)
		{
			cout << "\tWebcam:\n";
			webcam->Print();
		}
		if (headphones != nullptr)
		{
			cout << "\tHeadphones:\n";
			headphones->Print();
		}
		if (microphone != nullptr)
		{
			cout << "\tMicrophone:\n";
			microphone->Print();
		}
		if (mouse != nullptr)
		{
			cout << "\tMouse:\n";
			mouse->Print();
		}
	}

	void SetWebcam(Webcam* ptr)
	{
		webcam = ptr;
	}
	void SetHeadphones(Headphones* ptr)
	{
		headphones = ptr;
	}
	void SetMicrophone(Microphone* ptr)
	{
		microphone = ptr;
	}
	void SetMouse(Mouse* ptr)
	{
		mouse = ptr;
	}
};

int main()
{
	cout << "New empty laptop object:" << endl;
	Laptop* ptrLaptop = new Laptop();
	ptrLaptop->Print();
	system("pause");
	system("cls");

	cout << "Creatin aggregation objects:" << endl;
	cout << "\tWebcam:" << endl;
	Webcam ptrWebcam;
	ptrWebcam.Input();

	cout << "\n\tHeadphones:" << endl;
	Headphones ptrHeadphones;
	ptrHeadphones.Input();

	cout << "\n\tMicrophone:" << endl;
	Microphone ptrMicrophone;
	ptrMicrophone.Input();

	cout << "\n\tMouse:" << endl;
	Mouse ptrMouse;
	ptrMouse.Input();
	system("pause");
	system("cls");

	cout << "Set aggregation objects and print laptop:" << endl;
	ptrLaptop->SetWebcam(&ptrWebcam);
	ptrLaptop->SetHeadphones(&ptrHeadphones);
	ptrLaptop->SetMicrophone(&ptrMicrophone);
	ptrLaptop->SetMouse(&ptrMouse);
	ptrLaptop->Print();
	system("pause");
	system("cls");

	cout << "Input info about laptop:" << endl;
	ptrLaptop->Input();
	system("pause");
	system("cls");

	cout << "Print new info about laptop:" << endl;
	ptrLaptop->Print();
	system("pause");
	system("cls");

	cout << "Deleting laptop and print aggregation objects:" << endl;
	delete ptrLaptop;
	cout << "\tWebcam:" << endl;
	ptrWebcam.Print();
	cout << "\n\tHeadphones:" << endl;
	ptrHeadphones.Print();
	cout << "\n\tMicrophone:" << endl;
	ptrMicrophone.Print();
	cout << "\n\tMouse:" << endl;
	ptrMouse.Print();
}