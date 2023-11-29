/**
 * @file wordLadder.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem statement :- A transformation sequence from word beginWord to word endWord using a dictionary wordList is 
 *                      a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 *                      Every adjacent pair of words differs by a single letter.
 *                      Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
                        sk == endWord
                        Given two words, beginWord and endWord, and a dictionary wordList, return the number of words 
                        in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 * 
             Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
             Output: 5
             Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
 */

#include<bits/stdc++.h>
using namespace std;
int solve(string beginWord,string endWord,vector<string>&wordList){
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    unordered_set<string>st(wordList.begin(),wordList.end());
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        string word=it.first;
        int steps=it.second;
        if(word == endWord){
            return steps;
        }
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,steps+1});
                    st.erase(word);
                }
                word[i]=original;
            }
        }
    }
    return 0;
}
int main(){
cout<<"Enter the starting word "<<endl;
string beginWord;
cin>>beginWord;
cout<<"Enter the ending word "<<endl;
string endWord;
cin>>endWord;
int n;
cout<<"Enter the size of the word list "<<endl;
cin>>n;
vector<string>wordList;
cout<<"Enter the wordList "<<endl;
for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    wordList.push_back(temp);
}
int ans=solve(beginWord,endWord,wordList);
cout<<"The total no of words need to be traversed to reach end word is "<<ans<<endl;
return 0;
}