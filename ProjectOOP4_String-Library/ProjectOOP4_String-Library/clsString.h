#pragma once
#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;
class clsString
{
private:
	string _Value;

public:
	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}
	void setValue(string Value) {
		_Value = Value;
	}
	string getValue() {
		return _Value;
	}
	_declspec(property(get = getValue, put = setValue)) string Value;

	static int CountWords(string S1) {
		int pos;
		string temp;
		int counter=0;
		string Delim = " ";
		while ((pos = S1.find(Delim)) != string::npos)
		{
			temp = S1.substr(0, pos+1);
			if (temp != " ") {
				counter++;
			}
			S1.erase(0, pos+Delim.length());
		}
		if (S1 != "")
		return ++counter;

		return counter;
	}
	int CountWords() {
		return CountWords(_Value);
	}

	static void PrintFirstLetterInEachWord(string S1) {
		bool IsFisrtLetter = true;
		for (int i = 0; i < S1.length(); i++) {
			if (IsFisrtLetter && S1[i] != ' ')
			cout << S1[i] << endl;
			IsFisrtLetter = (S1[i] == ' ') ? true : false;
		}
	}
	void PrintFirstLetterInEachWord() {
		PrintFirstLetterInEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1) {
		bool IsFisrtLetter = true;
		for (int i = 0; i < S1.length(); i++) {
			if (IsFisrtLetter && S1[i] != ' ')
				S1[i] = toupper(S1[i]);
			IsFisrtLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord() {
		_Value=UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterInEachWord(string S1) {
		bool IsFisrtLetter = true;
		for (int i = 0; i < S1.length(); i++) {
			if (IsFisrtLetter && S1[i] != ' ')
				S1[i] = tolower(S1[i]);
			IsFisrtLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}
	void LowerFirstLetterInEachWord() {
		_Value= LowerFirstLetterInEachWord(_Value);
	}

	static string UpperAllString(string S1) {
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ');
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void UpperAllString() {
		_Value= UpperAllString(_Value);
	}

	static string LowerAllString(string S1) {
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ');
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}

	static char InvertLetter(char C1) {
		if (islower(C1))
			return toupper(C1);
		else
			return tolower(C1);
	}
	static string InvertAllLetters(string S1) {
		for (int i = 0; i < S1.length(); i++) {
			S1[i]=InvertLetter(S1[i]);
		}
		return S1;
	}
	void InvertAllLetters() {
		_Value=InvertAllLetters(_Value);
	}
	
	enum enWhatToCount { All = 0, Lowercase = 1, Uppercase = 2 };
	static int CountLetters(string S1, enWhatToCount whattocount = All) {
		int count=0;
		if (whattocount == All) {
			for (int i = 0; i < S1.length(); i++) {
				if (S1[i] != ' ')
					count++;
			}
		}
		else
		{
			if (whattocount == Lowercase) {
				for (int i = 0; i < S1.length(); i++) {
					if (islower(S1[i])&&S1[i]!=' ')
						count++;
				}
			}
			else
				for (int i = 0; i < S1.length(); i++) {
					if (!islower(S1[i]) && S1[i] != ' ')
						count++;
				}
		}
		return count;
	}
	int CountLetters(enWhatToCount whattocount = All) {
		return CountLetters(_Value, whattocount);
	}

	static int CountSpecificLetter(string S1,char C1,bool MatchCase=true) {
		int count = 0;
		for (int i = 0; i <= S1.length(); i++) {
			if (MatchCase) {
				if (S1[i] == tolower(C1))
					count++;
			}
			else if 
				(tolower(S1[i]) == tolower(C1))
				count++;
		}
		return count;
	}
	int CountSpecificLetter(char C1, bool MatchCase = true) {
		return CountSpecificLetter(_Value,C1,MatchCase);
	}

	static bool IsVowel(char C1) {
		string Vowels = "aouie";
		return (Vowels.find(tolower(C1)) != string::npos) ? true : false;
	}
	 
	static int CountVowels(string S1) {
		int count = 0;
		for (int i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				count++;
		}
	}
	int CountVowels() {
		return CountVowels(_Value);
	}
	
	static void PrintVowels(string S1) {
		for (int i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				cout << left << setw(3) << S1[i];
		}
	}
	void PrintVowels() {
		PrintVowels(_Value);
	}

	static void PrintEachWord(string S1) {
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ')
				cout << S1[i];
			else
				cout << endl;
		}
	}
	void PrintEachWord() {
		PrintEachWord(_Value);
	}

	static vector<string>Split(string S1,string Delim) {
		int pos;
		string temp;
		vector<string>Split;
		while ((pos = S1.find(Delim)) != string::npos) {
			temp = S1.substr(0, pos);
			if (temp != "") {
				Split.push_back(temp);
			}
			S1 = S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
			Split.push_back(S1);
		return Split;
	}
	vector<string>Split(string Delim) {
		return Split(_Value,Delim);
	}

	static string TrimLeft(string S1) {
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ') {
				S1 = S1.substr(i, S1.length() - 1);
				break;
			}
		}
		return S1;
	}
	void TrimLeft() {
		_Value=TrimLeft(_Value);
	}
	static string TrimRight(string S1) {
		for (int i = S1.length()-1; i >= 0; i--) {
			if (S1[i] != ' ') {
				S1 = S1.substr(0, i+1);
				break;
			}
		}
		return S1;
	}
	void TrimRight() {
		_Value= TrimRight(_Value);
	}

	static string Join(vector<string>Vstring, string Delim) {
		string NewWord="";
		for (string v : Vstring) {
			NewWord +=Delim+v;
		}
		return(NewWord = NewWord.substr(Delim.length(), NewWord.length() - 1));
	}
	static string Join(string arr[],int Length, string Delim) {
		string NewWord = "";
		for (int i = 0; i < Length;i++) {
			NewWord += Delim + arr[i];
		}
		return(NewWord = NewWord.substr(Delim.length(), NewWord.length() - 1));
	}

	static string ReverseString(string S1) {
		vector<string>Vstring = Split(S1," ");
		int Last = Vstring.size() - 1;
		string temp;
		for (int i = 0; i < Last; i++, Last--) {
			temp= Vstring[Last];
			Vstring[Last] = Vstring[i];
			Vstring[i] = temp;
		}
	}
	void ReverseString() {
		_Value = ReverseString(_Value);
	}

	static string ReableaceWord(string S1, string OldPart,string NewPart) {
		int pos;
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] == OldPart[0]) {
				pos = i;
				int j = 1;
				int temp = i;
				for (j; j < OldPart.length(); j++) {
					if (S1[++temp] != OldPart[j])
						break;
					else
						continue;

				}
				if (j == OldPart.length()) {
				S1.erase(pos, OldPart.length());
				S1.insert(pos,NewPart);
				}
			}
		}
		return S1;
	}
	void ReableaceWord(string OldPart, string NewPart) {
		_Value=ReableaceWord(_Value, OldPart, NewPart);
	}

	static string RemovePunctuations(string S1) {
		string result="";
		for (int i = 0; i < S1.length(); i++) {
			if (!ispunct(S1[i]))
				result += S1[i];
		}
		return result;
	}
	void RemovePunctuations() {
		_Value= RemovePunctuations(_Value);
	}
};

