// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#pragma once
#include<iostream>
#include <vector>
class Tree
{
private:
struct list {
char value;
std::vector <list> dop_list;
};

list* root = nullptr;
std::vector<char> perestanovki;
int currentPerestanovka = 0;
int needPerestanovka = 0;

std::vector<char> deleteElem(std::vector<char> array, char value) {
std::vector<char>::iterator position = std::find(array.begin(), array.end(), value);
if (position != array.end())
array.erase(position);
return array;
}

std::vector<list> createlist(std::vector<char> vec, list* head) {
std::vector<list> tmp_v;
for (int i = 0; i < vec.size(); i++) {
list* tmp = new list;
tmp->value = vec[i];
tmp->dop_list = createlist(deleteElem(vec, vec[i]), tmp);
tmp_v.push_back(*tmp);
}
return tmp_v;
}

std::string getElem(list *current, std::string trace) {
if (current->value != '*'){
trace += current->value;
}
for (int i = 0; i < current->dop_list.size(); i++) {
getElem(&current->dop_list[i], trace);
}
if (trace.length() == root->dop_list.size() && currentPerestanovka == needPerestanovka-1 && perestanovki.empty())
{
for (int i = 0; i < trace.length(); i++) {
perestanovki.push_back(trace[i]);
}
}
else if(trace.length() == root->dop_list.size()){
currentPerestanovka++;
}
return trace;
}

public:
Tree(std::vector<char> vec) {
root = new list;
root->value = '*';
root->dop_list = createlist(vec, root);
}

std::vector<char> getPerm(int n){
needPerestanovka = n;
getElem(root, "");
std::vector<char> result = perestanovki;
perestanovki.clear();
currentPerestanovka = 0;
return result;
}
};
#endif  // INCLUDE_TREE_H_
