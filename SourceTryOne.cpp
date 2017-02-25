#include<iostream>
#include<string>
#include<regex>

using namespace std;


string Algocheck(const string &data) {
	bool returnCheck = true;
	string MyExpression1 = "^(([0]{1}[1-9]{1}:)|([1]{1}[0-2]{1}:))([0-5][0-9]:)([0-5][0-9])(AM)$";
	string MyExpression2 = "^(([0]{1}[1-9]{1}:)|([1]{1}[0-2]{1}:))([0-5][0-9]:)([0-5][0-9])(PM)$";
	//Remove PM/AM from Data string
	string MainControl = data.substr(0, 8);
	//create a regex object to validate the data
	regex Validate = regex(MyExpression1, regex_constants::icase);
	regex Validate2 = regex(MyExpression2, regex_constants::icase);
	
	if (regex_match(data, Validate)) {
		returnCheck = false;
		
		//Break Data String first two digits into NEW String
		string brak = data.substr(0, 2);
		
		//for numeric string use stoi string to integer convert non-numeric are ignored
		//This Code for 12 AM Represent 00
		//This Code for 12 AM Represent 24
		int var1 = stoi(brak);
		int var2 = stoi(brak);
		
		if (var1 == 12) {
			//formats = false;
			//Format 1
			var1 = var1 - 12;
		
			//Integer to String Array
			string local = to_string(var1);
			local.push_back('0');
			size_t v = local.length();
			for (int j = 0; (size_t)j < v; j++) {
				//Replace Old Array
				MainControl[j] = local[j];

				
			}
			

		}//if End



	}
	
	else if (regex_match(data,Validate2)) {
		
		returnCheck = false;

		//Break Data String first two digits into NEW String
		string brak = data.substr(0, 2);
		//for numeric string use stoi string to integer convert non-numeric are ignored
		int var1 = stoi(brak);
		if (var1 <= 11) {
			var1 = var1 + 12;
				//Integer to String Array
				string local = to_string(var1);
				size_t v = local.length();
				for (int j = 0; (size_t)j < v; j++) {
					//Replace Old Array
					MainControl[j] = local[j];
				}

				
		}//if End

	}//Else if regex match end

	else {

		
	}


	if (!returnCheck) {

		return MainControl;
	}

	else {
	
		string s= "Sorry You Enter Incorrect Format.Format would be 12 Hour i.e : 07:05:45PM Hour:Minute:Second AM/PM\n";
		
	
	return s;
	
	}

	
}

int main() {

	string time;
    getline(cin,time);
	string printString = Algocheck(time);

	cout << printString << endl;

    return 0;
    
}