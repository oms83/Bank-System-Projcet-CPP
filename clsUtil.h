#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
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
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
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

    static string TextNumber(int Number)
    {
        string Numbers[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine", "ten", "eleven", "twelve", "thirteen",
                            "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        string Tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

        if (Number < 20)
            return Numbers[Number] + " ";
        else if (Number < 100)
            return Tens[Number / 10] + " " + Numbers[Number % 10] + " ";
        else if (Number < 1000)
            return TextNumber(Number / 100) + " " + "hundred" + " " + TextNumber(Number % 100);
        else if (Number < 1000000)
            return TextNumber(Number / 1000) + " " + "thousand" + " " + TextNumber(Number % 1000);
        else if (Number < 1000000000)
            return TextNumber(Number / 1000000) + " " + "million" + " " + TextNumber(Number % 1000000);
        else if (Number < 1000000000000)
            return TextNumber(Number / 1000000000) + " " + "billion" + " " + TextNumber(Number % 1000000000);

    }

};







//#pragma once
//
//#include <iostream>
//#include <vector>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<time.h>
//#include "clsDate.h"
//#include "clsString.h"
//
//using namespace std;
//
//class clsUtil
//{
//private:
//    
//    int _Number;
//
//
//public:
//	
//
//    int GetNumber()
//    {
//        return _Number;
//    }
//    
//    void SetNumber(int Number)
//    {
//        _Number = Number;
//    }
//
//    __declspec(property(get = GetNumber, put = SetNumber)) int Number;
//
//    static int ReadPositiveNumber(string Message)
//    {
//        int Number = 0;
//        do
//        {
//            cout << Message;
//            cin >> Number;
//        } while (Number <= 0);
//        return Number;
//    }
//
//    static bool isPerfectNumber(int Number)
//    {
//        int Sum = 0;
//        for (int i = 1; i < Number; i++)
//        {
//            if (Number % i == 0)
//                Sum += i;
//        }
//        return Sum == Number;
//    }
//
//    static int RevesedNumber(int Number)
//    {
//        int mod, digit = 0;
//        for (; Number != 0;)
//        {
//            mod = Number % 10;
//            digit = digit * 10 + mod;
//            Number /= 10;
//        }
//        return digit;
//    }
//
//    static int SumOfDigits(int Number)
//    {
//        int sum = 0;
//        while (Number > 0)
//        {
//            sum += Number % 10;
//            Number /= 10;
//        }
//        
//        return sum;
//    }
//
//    static int CountDigitFrequency(short DigitToCheck, int Number)
//    {
//        int Remainder = 0, FreCount = 0;
//        while (Number > 0)
//        {
//            Remainder = Number % 10;
//            Number /= 10;
//            if (Remainder == DigitToCheck)
//                FreCount++;
//        }
//        return FreCount;
//    }
//
//    static int RevesedDigit(int Number)
//    {
//        int Remainder = 0, Number2 = 0;
//        while (Number > 0)
//        {
//            Remainder = Number % 10;
//            Number2 = Number2 * 10 + Remainder;
//            Number /= 10;
//        }
//        return Number2;
//    }
//
//    static void PrintDigits(int Number)
//    {
//        int Remainder = 0, Number2 = 0;
//        while (Number > 0)
//        {
//            Remainder = Number % 10;
//            Number /= 10;
//            cout << Remainder << endl;
//        }
//    }
//
//    static bool IsItPalindromeNumber(int Number)
//    {
//        return Number == RevesedDigit(Number);
//    }
//
//    static void PrintInvertedPattern(int Number)
//    {
//        for (int i = Number; i > 0; i--)
//        {
//            for (int j = 1; j <= i; j++)
//            {
//                cout << i << char(32);
//            }
//            cout << endl;
//        }
//    }
//
//    static void PrintWordsFromAAAtoZZZ()
//    {
//        for (int i = 65; i <= 90; i++)
//        {
//            for (int j = 65; j <= 90; j++)
//            {
//                for (int k = 65; k <= 90; k++)
//                {
//                    cout << char(i) << char(j) << char(k);
//                    cout << endl;
//                }
//            }
//        }
//    }
//
//    static string Encrypt(string Name, short EncryptionKey)
//    {
//        for (int i = 0; Name[i] != '\0'; i++)
//        {
//            Name[i] = char((int)Name[i] + EncryptionKey);
//        }
//        return Name;
//    }
//
//    static string Decrypt(string Name, short EncryptionKey)
//    {
//        for (int i = 0; Name[i] != '\0'; i++)
//        {
//            Name[i] = char((int)Name[i] - EncryptionKey);
//        }
//        return Name;
//    }
//
//    static int RondomNumber(int From, int To)
//    {
//        return rand() % (To - From + 1) + From;
//    }
//
//    enum enCharType { SmallCharacter = 1, CapitalCharacter = 2, SpcialCharacter = 3, Digit = 4 };
//    
//    static char GetCharType(enCharType CharType)
//    {
//        switch (CharType)
//        {
//        case enCharType::SmallCharacter:
//        {
//            return char(RondomNumber(97, 122));
//            break;
//        }
//        case enCharType::CapitalCharacter:
//        {
//            return char(RondomNumber(65, 90));
//            break;
//        }
//        case enCharType::SpcialCharacter:
//        {
//            return char(RondomNumber(33, 47));
//            break;
//        }
//        case enCharType::Digit:
//        {
//            return char(RondomNumber(48, 57));
//            break;
//        }
//        }
//    }
//
//    static void GetArrayRandom(int arr[], int arrLength, short ElementsFrom, short ElementsTo)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            arr[i] = RondomNumber(ElementsFrom, ElementsTo);
//        }
//    }
//
//    static void GetArrayRandom(int arr[], int arrLength, short ElementsFrom, short ElementsTo)
//    {
//        short Element;
//      
//        for (int i = 0; i < arrLength; i++)
//        {
//            cout << "Enter " << i + 1 << ". Element: ";
//            cin >> Element;
//
//            arr[i] = Element;
//        }
//    }
//
//    static void PrintArray(int arr[], int arrLength)
//    {
//        cout << "\n";
//        for (int i = 0; i < arrLength; i++)
//        {
//            cout << arr[i] << " ";
//        }
//        cout << "\n";
//    }
//
//    static void Srand()
//    {
//        srand((unsigned)time(NULL));
//    }
//
//    static int MaxElementOfArray(int arr[], int arrLength)
//    {
//        int Max = arr[0];
//        for (int i = 0; i < arrLength; i++)
//        {
//            if (Max < arr[i])
//                Max = arr[i];
//        }
//        return Max;
//    }
//
//    static int MinElementOfArray(int arr[], int arrLength)
//    {
//        int Min = arr[0];
//        for (int i = 0; i < arrLength; i++)
//        {
//            if (Min > arr[i])
//                Min = arr[i];
//        }
//        return Min;
//    }
//
//    static int SumElementOfArray(int arr[], int arrLength)
//    {
//        int Sum = 0;
//        for (int i = 0; i < arrLength; i++)
//        {
//            Sum += arr[i];
//        }
//        return Sum;
//    }
//
//    static void CopyArray(int OrginalArr[], int CopyArr[], int arrLength)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            CopyArr[i] = OrginalArr[i];
//        }
//    }
//
//    enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
//
//    static enPrimeNotPrime CheckPrime(int Number)
//    {
//        int M = round(Number / 2);
//        for (int Counter = 2; Counter <= M; Counter++)
//        {
//            if (Number % Counter == 0)
//                return enPrimeNotPrime::NotPrime;
//        }
//
//        return enPrimeNotPrime::Prime;
//    }
//
//    static int CopyInArrayOnlyPrimeValue(int OrginalArr[], int CopyArr[], int arrLength)
//    {
//        int len = 0;
//        for (int i = 0; i < arrLength; i++)
//        {
//            if (CheckPrime(OrginalArr[i]) == enPrimeNotPrime::Prime)
//            {
//                CopyArr[len++] = OrginalArr[i];
//            }
//        }
//        return len;
//    }
//
//    static void SumTwoArrayInArray(int arr1[], int arr2[], int sumArr[], int arrLength)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            sumArr[i] = arr1[i] + arr2[i];
//        }
//    }
//    
//    static int SumOfTwoArray(int arr1[], int arr2[], int arrLength)
//    {
//        int Sum = 0;
//        for (int i = 0; i < arrLength; i++)
//        {
//            Sum = arr1[i] + arr2[i];
//        }
//        return Sum;
//    }
//
//
//    static void Swap(int& A, int& B)
//    {
//        int Temp = A;
//        A = B;
//        B = Temp;
//    }
//    
//    static void FillElementInArray(int arr[], int arrLength)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            arr[i] = i + 1;
//        }
//    }
//
//    static void SuffleArray(int arr[], int arrLength)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            Swap(arr[RondomNumber(1, arrLength - 1)], arr[RondomNumber(1, arrLength - 1)]);
//        }
//    }
//
//    static void CopyReveresArray(int OrginalArr[], int CopyArr[], int arrLength)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            CopyArr[i] = OrginalArr[arrLength - i - 1];
//        }
//    }
//
//    static string GeneraterWord(enCharType CharType, short length)
//    {
//        string word = "";
//        for (int i = 0; i < length; i++)
//        {
//            word = word + GetCharType(CharType);
//        }
//        return word;
//    }
//
//    static string GeneraterKey()
//    {
//        string Key = "";
//        Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6) + "-";
//        Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6) + "-";
//        Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6) + "-";
//        Key = Key + GeneraterWord(enCharType::CapitalCharacter, 6);
//        return Key;
//    }
//
//    static void PrintArray(string arr[], int arrLength)
//    {
//        cout << endl;
//        for (int i = 0; i < arrLength; i++)
//        {
//            cout << arr[i] << endl;
//        }
//    }
//
//    static void FillArrayWithKeys(string arr[], int arrLength)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            arr[i] = GeneraterKey();
//        }
//    }
//
//    int FoundTheIndexElement(int arr[], int arrLength, int ElementToCheck)
//    {
//        for (int i = 0; i < arrLength; i++)
//        {
//            if (ElementToCheck == arr[i])
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//    bool IsNumberInArray(int arr[], int arrLength, int ElementToCheck)
//    {
//        return FoundTheIndexElement(arr, arrLength, ElementToCheck) != -1;
//    }
//
//};