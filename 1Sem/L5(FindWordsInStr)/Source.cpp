/*
9. —ловом в строке считаетс€ последовательность букв латинского
алфавита, остальные символы €вл€ютс€ разделител€ми между словами. «а
один просмотр символов строки найти все слова с максимальной долей
гласных букв (т.е. прописных и строчных символов ТaТ, ТeТ, ТiТ, ТoТ,
ТuТ, ТyТ) и занести их в новую строку. —лова в новой строке должны
раздел€тьс€ ровно одним пробелом.
*/
// символы лат алфавита 65-90 заглавные. 97-122 прописные
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <vector>
using std::cout;
using std::string;
using std::cin;
using std::getline;
using std::istringstream;
using std::vector;
void CheckString(string& str)
{
    if (str.empty())
    {
        throw "\nстрока пуста";
    }
}
void InPutEnglSymbols(string& str)
{
    for (size_t i = 64; i < 123; i++)
    {
        if ((i > 64 && i < 91) || (i > 96 && i < 123))
        {

            str += (char)i;

        }
        continue;
    }
}
bool CheckIndexBegin(string str, size_t& ind_begin, int& flag)
{
    
    if (ind_begin >= str.length()) 
    {
        if (flag == 0)
        {
            throw"строка состоит только из разделителей";
        }
        return false;
    }
}
int CounterOfVowel(string& str, size_t& ind_begin, size_t& ind_end, string vowel_symbols, int& vowel_counter)
{
    for (ind_begin; ind_begin <= ind_end; ind_begin++)
    {
        for (size_t j = 0; j < vowel_symbols.size(); j++) 
        {
            if (str[ind_begin] == vowel_symbols[j])
            {
                vowel_counter++;
            }
        }
    }
    return vowel_counter;
}
void CheckAllVowels(int max_vowels)
{
    if (max_vowels == 0)
    {
        throw "\nв строке нет слов с гласными буквами";
    }
}
void InPutWords(string str, string all_engl_symbols, string vowel_symbols, vector <string>& words, int& vowel_counter,int& max_vowels)
{
    int flag = 0;
    size_t ind_begin, ind_end;
    for (ind_begin = 0; ind_begin < str.size(); ind_begin++)
    {
        ind_begin = str.find_first_of(all_engl_symbols, ind_begin);

        if (!CheckIndexBegin(str, ind_begin, flag))
        {
            break;
        }
        flag++;

        ind_end = str.find_first_not_of(all_engl_symbols, ind_begin + 1);
        string word = str.substr(ind_begin, ind_end - ind_begin);
        words.push_back(word);

        if (max_vowels <= CounterOfVowel(str, ind_begin, ind_end, vowel_symbols, vowel_counter))
        {
            max_vowels = CounterOfVowel(str, ind_begin, ind_end, vowel_symbols, vowel_counter);
        }
        vowel_counter = 0;
        CheckAllVowels(max_vowels);
        ind_begin = ind_end;
 
    }
}
void OutPutVector(vector <string>& words)
{
    cout << "\nстрока без разделителей\n";
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
    cout << "\n";
}
string InPutInNewStr(string& newstr, int& vowel_counter, vector <string> words, string vowel_symbols, int& max_vowels)
{
    vowel_counter = 0;
    for (int i = 0; i < words.size(); i++)
    {
        string temp = words[i];
        for (size_t j = 0; j < temp.size(); j++)
        {
            for (size_t k = 0; k < vowel_symbols.size(); k++)
            {
                if (temp[j] == vowel_symbols[k])
                {
                    vowel_counter++;
                }
            }
        }
        if (vowel_counter == max_vowels)
        {
            newstr += temp + " ";
        }
        vowel_counter = 0;
    }
    return newstr;
}
int main()
{
    try
    {
        setlocale(LC_ALL, "ru");
        cout << "введите строку\n";
        string str;
        //getline(cin, str);
        str = "123hello_)world!@#$$my==name??>is}|matvey-=";
        cout << str << "\n";
        CheckString(str);
        string all_engl_symbols;
        InPutEnglSymbols(all_engl_symbols);
        cout << "\nсимволы не разделители\n" << all_engl_symbols << "\n";
        string vowel_symbols = "AEIOUYaeiouy";
        vector <string> words;
        int vowel_counter = 0, max_vowels = 0;
        InPutWords(str, all_engl_symbols, vowel_symbols, words, vowel_counter, max_vowels);
        OutPutVector(words);
        string newstr;
        cout << "\nполученные слова\n" << InPutInNewStr(newstr, vowel_counter, words, vowel_symbols, max_vowels) << "\n";
    }
    catch (const char* msg) { cout << msg; }
    return 0;
}