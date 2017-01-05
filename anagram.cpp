//import libraries
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//declaring anagram function, single argument of the phrase put into a vector
string anagram(vector<char>& string_num);

//defining the function
string anagram(vector<char>& string_num){
	int letter;
	//gets the vector of the line then converts each letter into a int(ascii)
	//and puts it into a new vector called letter_to_num
	vector<int> letter_to_num;
	for(int i = 0; i < string_num.size(); i++){
		letter = (int) (string_num[i]);
		letter_to_num.push_back(letter);
	}
	
	//sorts the numbers in order
	int temp;
	for(int j = 0; j < letter_to_num.size(); j++){
		for(int i = 0; i < letter_to_num.size(); i++){
			if(letter_to_num[i] > letter_to_num[j]){
				temp = letter_to_num[i];
				letter_to_num[i] = letter_to_num[j]; 
				letter_to_num[j] = temp;
			}
		}
	}

    //combines the numbers of letter_to_num into characters and puts it into a
    //string to create a long string of numbers. We are not adding them but
    //just adding onto so 1+41=141 
	string numbers, array_position;
	for(int i =0 ; i < letter_to_num.size(); i ++){
		array_position = (char) letter_to_num[i];
		numbers=numbers+array_position;
	}
	//returns the new string
	return numbers;
}

int main(){
	//initializing variables
	string first_input;
	string second_input;

	char get_letter_from_string1;
	char get_letter_from_string2;

	vector<char> string1_letters;
	vector<char> string2_letters;

	//ask user for strings and uses the get line to put it into a variable
	cout << "Enter first string:" << endl;
	//cin >> skipws;
	getline(cin, first_input);
	cout << "Enter second string:" << endl;
	//cin >> skipws;
	getline(cin, second_input);

	/*loops through each character and make them lower case and checks if
	the character is a number or alphabet and finally pushes it back into
	a vector that only has numbers/alphabet characters */
	for (int i  = 0; i < first_input.length(); i++){
		get_letter_from_string1 = tolower(first_input[i]);
		if(isalnum(get_letter_from_string1)>0){
			string1_letters.push_back(get_letter_from_string1);
		}
	}

	for (int i  = 0; i < second_input.length(); i++){
		get_letter_from_string2 = tolower(second_input[i]);
		if(isalnum(get_letter_from_string2)>0){
			string2_letters.push_back(get_letter_from_string2);
		}
	}
	
	//calls the function anagram and puts it into a new variable
	string first = anagram(string1_letters);
	string second = anagram(string2_letters);
	
	//compares if each string are the same. If they are it is an anagram if it's
	//not then it isn't a anagram.
	if(first == second){
		cout << "The strings are anagrams." << endl;
		} 
	else {
		cout << "The strings are not anagrams." << endl; 

		}
	
	

return 0;

}