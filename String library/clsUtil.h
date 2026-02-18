#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class clsUtil
{
private:


public:
        enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChars=5};
        static void Srand()
	{
		srand((unsigned)time(NULL));
	}
    	static int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
        static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
            return char(RandomNumber(97, 122));
            break; 
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            // Generate a random special character (ASCII: 33 '!' to 47 '/').
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII: 48 '0' to 57 '9').
            return char(RandomNumber(48, 57));
            break;
        }

        }
        // If no valid type is provided, return a null character.
        return '\0';
    }
        static string GenerateWord(enCharType CharType, short Length)
   {
       string Word; 

    
       for (int i = 1; i <= Length; i++)
       {
           
           Word = Word + GetRandomCharacter(CharType);
       }
       return Word;
   }
        static  string GenerateKey(enCharType type)
    {
        string Key = "";  // Initialize an empty key string.

        // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

        return Key;
    }
        static void GenerateKeys(short NumberOfKeys, enCharType Chartype)
        {
            
            for (int i = 1; i <= NumberOfKeys; i++)
            {
               
                cout << "Key [" << i << "] : ";
                cout << GenerateKey(Chartype) << endl;
            }
        }
        static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
        {
            for (int i = 0; i < arrLength; i++)
                arr[i] = RandomNumber(From, To);
        }
        static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
        {
            for (int i = 0; i < arrLength; i++)
                arr[i] = GenerateWord(CharType, Wordlength);

        }
        static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
        {
            for (int i = 0; i < arrLength; i++)
                arr[i] = GenerateKey(CharType);
        }
        static  void Swap(int& A, int& B)
        {
            int Temp;

            Temp = A;
            A = B;
            B = Temp;
        }
        static  void Swap(double& A, double& B)
        {
            double Temp;

            Temp = A;
            A = B;
            B = Temp;
        }
        static  void Swap(bool& A, bool& B)
        {
            bool Temp;

            Temp = A;
            A = B;
            B = Temp;
        }
        static  void Swap(char& A, char& B)
        {
            char Temp;

            Temp = A;
            A = B;
            B = Temp;
        }
        static  void Swap(string& A, string& B)
        {
            string Temp;

            Temp = A;
            A = B;
            B = Temp;
        }
        static  void Swap(clsDate& A, clsDate& B)
        {
            clsDate::swapdates(A, B);

        }
        static  void ShuffleArray(int arr[100], int arrLength)
        {

            for (int i = 0; i < arrLength; i++)
            {
                Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
            }

        }
        static string  Tabs(short NumberOfTabs)
        {
            string t = "";

            for (int i = 1; i < NumberOfTabs; i++)
            {
                t = t + "\t";
                cout << t;
            }
            return t;

        }
        static string  EncryptText(string Text, short EncryptionKey)
        {

            for (int i = 0; i <= Text.length(); i++)
            {

                Text[i] = char((int)Text[i] + EncryptionKey);

            }

            return Text;

        }
        static string  DecryptText(string Text, short EncryptionKey)
        {

            for (int i = 0; i <= Text.length(); i++)
            {

                Text[i] = char((int)Text[i] - EncryptionKey);

            }
            return Text;

        }
        static string NumberToText(int Number)
        {

            if (Number == 0)
            {
                return "";
            }

            if (Number >= 1 && Number <= 19)
            {
                string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
              "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

                return  arr[Number] + " ";

            }

            if (Number >= 20 && Number <= 99)
            {
                string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
                return  arr[Number / 10] + " " + NumberToText(Number % 10);
            }

            if (Number >= 100 && Number <= 199)
            {
                return  "One Hundred " + NumberToText(Number % 100);
            }

            if (Number >= 200 && Number <= 999)
            {
                return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
            }

            if (Number >= 1000 && Number <= 1999)
            {
                return  "One Thousand " + NumberToText(Number % 1000);
            }

            if (Number >= 2000 && Number <= 999999)
            {
                return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
            }

            if (Number >= 1000000 && Number <= 1999999)
            {
                return  "One Million " + NumberToText(Number % 1000000);
            }

            if (Number >= 2000000 && Number <= 999999999)
            {
                return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
            }

            if (Number >= 1000000000 && Number <= 1999999999)
            {
                return  "One Billion " + NumberToText(Number % 1000000000);
            }
            else
            {
                return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
            }

        }

};
        
