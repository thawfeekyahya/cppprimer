#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
   string word;
   map<string,int> word_count;
   
   while(cin>>word) {
       auto result = word_count.insert({word,1}); // result returned in pair // first -> iterator (which is a pair actually stored in map ) // second -> bool if the operation is sucessful
       if(!result.second) {
           ++result.first->second;
       }
   }
   
   for(auto element:word_count) {
       cout<<element.first<<"-->"<<element.second<<endl;
   }

    return 0;
}
