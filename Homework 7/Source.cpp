#include <iostream>
#include <vector>
#include <fstream>
#include <map>


using namespace std;

//// #1
////creating the template
template<class T>
int pairCount(const vector<T>&);

////making the vector that holds the elements
int main() 
{
    vector<int> v = { 1, 3, 7, 10, 1, 1, 3, 5, 10, 5 };
    cout << pairCount(v) << endl;
    return 0;
}
//
////making a for loop to check if values are repeated
template<class T>
int pairCount(const vector<T>& v) 
{
    int count = 0;
    for (int i = 0; i < v.size(); ++i) 
    {
       int c = 0;
        for (int j = 0; j < v.size(); ++j) 
        {
            if (v[i] == v[j])
                ++c;
        }
        if (c == 2) 
        {
            ++count;
        }
    }
    return count / 2;
}


// #2
////writing the template header
template<class t>
vector<t> intersection(const vector<t>&, const vector<t>&);

//writing what values will be in each vector and what the answer should display
int main() 
{
    vector<int> v1 = { 1, 2, 8, 9 }, v2 = { 3, 4, 8, 10 };
    vector<int> result = intersection(v1, v2);
    for (int i = 0; i < result.size(); ++i) 
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
//
////writing the for loops that will determine what will happen when an element is repeated in both vectors
template<class T>
vector<T> intersection(const vector<T>& v1, const vector<T>& v2) 
{
    vector<T> result;
    for (int i = 0; i < v1.size(); ++i) 
    {
        bool found = false;
        for (int j = 0; j < v2.size(); ++j) 
        {
            if (v1[i] == v2[j])
                found = true;
        }
        if (found) 
        {
            result.push_back(v1[i]);
        }
    }
    return result;
}

// program 3
map<char, int> charFreq(string file);   //function prototype

int main()
{
    map<char, int> m;   //created a map m
    m = charFreq("input.txt");  //calls the function charFreq with parameter as file name
    cout << "Character" << " " << "Frequency" << endl;   //displays the heading
    for (auto i : m)    //iterates through map m
        //displays key and value with proper spacing between them
        cout << "    " << i.first << "        " << i.second << endl;
    return 0;
}
map<char, int> charFreq(string file)   //function definition
{
    map<char, int> m;   //created a map of char key and int value with name m
    ifstream in_file(file);     //opens the file in read mode
    char c;     //variable of type char is declared
    while (in_file >> c)     //reads each character in the file
    {
        m[c]++;         //increments the count of character in map m
    }
    return m;   //m is returned to the main
}

