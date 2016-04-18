/* Problem statement
Given a string of alphabets (lowercase) we need to first sort the string by frequency of each alphabets . And if two alphabets have same frequent 
the alphabet with lower ascii values gets the priority.
*/

#include <iostream>
#include <string>
#include<vector> 
#include <algorithm>
#include <iterator>

using namespace std;




bool cmp1(const pair<char , int>  &p1, const pair<char, int> &p2)
{
    if(p1.second == p2.second)
         return p1.first > p2.first; //If two aplhabet have same frequency
    return p1.second < p2.second;    // Alphabet with lower ascii value gets priority
}

int main()
{
   std:: string str = "oomar";
   vector<pair<char,int> > v;

    int counts[26] = {0};
   
    
    
int i;
int len = str.length();

for( i = 0; i < len; i++) {
   
    char c = str[i];
    if (!isalpha(c)) continue;

    counts[c-'a']++;
}

for(i =0;i<26;i++)
{
    char ch = i+'a';
    v.push_back(std::make_pair(ch,counts[i]));
}

sort(v.begin(), v.end(), cmp1);


for(i = 0; i < 26; i++) {
    //char ch = i+'a';
    cout<<v[i].first<<":"<<v[i].second<<"\n";
}
return 0;
}
