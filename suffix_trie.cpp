#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root; 
  char endSymbol; //'*'

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
    for(int i=0; i<str.length();i++){
			this->insertSubstringStartingAt(i,str);
		}
  }
	
	
	void insertSubstringStartingAt(int i,string str){
		TrieNode *node = this->root;
		
		for(int j=i;j<str.length();j++){
			char letter = str[j];
			//check if there is a entry
			if(node->children.find(letter) == node->children.end()){
				//create a new node if not
				TrieNode *Newnode = new TrieNode();
				node->children.insert({letter , Newnode});
			}
			//change pointer
			node = node->children[letter];
		}
		
		node->children.insert({this->endSymbol , NULL});
	}

  bool contains(string str) {
    TrieNode *node = this->root;
		for(char letter : str){
			if(node->children.find(letter) == node->children.end()){
				return false;
			}
			node = node->children[letter];
		}
		
		return node->children.find(this->endSymbol) != node->children.end();
  }
};

int main(){
  //play here
  return 0;
}
