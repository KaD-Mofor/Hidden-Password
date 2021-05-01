#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

//Function prototypes
bool testPasswd(char []);
bool passwdStrength(char[]);

int main() {

//START:
	//system("cls");

	char Password[45], ch;
	string Username[10] = { "Rita", "Miya", "Emile", "Lum", "Dimitri", "Daniel", "Femi", "Cyprain", "Donat", "Kelly" };
	string name;
	int i = 0;            //Number of times to re-enter wrong password
	bool isCorrect = 0;   //check if password is correct
	while ((isCorrect == 0) && (i < 5))
	{
		cout << "Enter username: " << endl;
		cin >> name;
		//Search for user name in array
		for (int n = 0; n < 10; n++) 
		{ 
			if (Username[n] == name)
			{
				isCorrect = 1;      //set bool to true
				cout << "Enter Password:\n "<<endl;
				for (int y = 0; ; ) {
					ch = _getch();   //Hides keyboard input
					Password[y] = ch;
					cout << '*';        //Display * on the console
					y++;

					if (ch == '\b' && n >= 1)     //8 is ASCII for BACKSPACE
					{
						cout << "\b \b";  //rub the character behind the cursor
						--y;
					}
					else if (ch == '\r')   //13 is ASCII for ENTER
					{
						Password[y] = '\0';   //End string
						break;
					}
					//_getch();
				}
					if (!testPasswd(Password))
					{
						cout << "\nOOppssss";
					}
					else
					{
						cout << "\n Login successful!"<<endl;
						cout << " Password: "<<Password<<endl;
						if (passwdStrength(Password))
							cout << "Password Strength: Very Secure" << endl;
						else
						{
							cout<< "Password Strength: Strong" << endl;
						}
					}
			}
			
		}

		if (!isCorrect)
		{
			cout << "\n User name not found!\n";
		}
		
		//goto START;
	}

	return 0;
}

bool testPasswd(char pwd[])
{
	int i;   //loop counter

	for (i = 0; i < sizeof(pwd); i++)
	{
		if (!isdigit(pwd[i]))
			return true;
	}
	for (i = 0; i < sizeof(pwd); i++)
	{
		if (!ispunct(pwd[i]))
			return false;
	}
	for (i = 0; i < sizeof(pwd); i++)
	{
		if (!isupper(pwd[i]))
			return false;
	}
	for (i = 0; i < sizeof(pwd); i++)
	{
		if (!islower(pwd[i]))
			return false;
	}

	if (!sizeof(pwd) >= 6)
		return false;

	return false;
}

//password strength
bool passwdStrength(char pwd[])
{
	int i;
	int y = 0;    //loop counter

	for (i = 0; i < strlen(pwd); i++)
	{
		if (isdigit(pwd[i])) {
			y++;
		}if (y >= 2)
			return true;
	}
	for (i = 0; i < strlen(pwd); i++)
	{
		if (ispunct(pwd[i])) {
			y++;
		}if (y >= 2)
			return false;
	}
	for (i = 0; i < strlen(pwd); i++)
	{
		if (isupper(pwd[i]))
			return false;
	}
	for (i = 0; i < strlen(pwd); i++)
	{
		if (islower(pwd[i]))
			return false;
	}
	for (i = 0; i < strlen(pwd); i++)

		if (sizeof(pwd) >= 8)
			return false;

	return false;
}