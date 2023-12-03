#include "Tire.hpp"
#include <bits/stdc++.h>

using namespace std;

void print_res(string word, bool exist, bool pre)
{
	if(!pre)
		cout << "Is " << word << " exist?" << endl;
	else
		cout << "Is prefix \"" << word << "\" exist?" << endl;
	if(exist)
		cout << "Yes, " << word << " exist!!!!" << endl;
	else
		cout << "No, " << word << " isn't exist!!!!" << endl;
}

int main()
{
	//insert: apple, search: apple, search: app, startsWith: app
	Trie *obj = new Trie();
	cout << "Insert word apple!" << endl;
	obj->insert("apple");
	print_res("apple", obj->search("apple"), false);
	print_res("app", obj->search("app"), false);
	print_res("app", obj->startsWith("app"), true);

	return 0;
}
