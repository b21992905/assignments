#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int x=0;
struct TrieNode{
    bool endofword= false;
    TrieNode *childrens[26];
};
bool search(TrieNode *root,string word);//it searches that whether if word is in trie
TrieNode *getNode();
bool insert(TrieNode* root,string word);//it inserts word in to trie
TrieNode* remove(TrieNode* root, string key, int depth = 0);//it removes word from trie
bool search(TrieNode *root,string word){
    x=27;
    TrieNode *curr=root;
    for(int i=0;i<word.length();i++){
        char c=word[i];
        if(!curr->childrens[c-'a']){
            x=i;
            return false;
        }
        curr=curr->childrens[c-'a'];
    }
    return curr->endofword;
}
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i<26; i++)
        if (root->childrens[i])
            return false;
    return true;
}//checks trie is empty or not
TrieNode* remove(TrieNode* root, string key, int depth)
{
    if (!root)
        return nullptr;
    if (depth == key.size()) {
        if (root->endofword)
            root->endofword= false;
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->childrens[index] =
            remove(root->childrens[index], key, depth + 1);
    if (isEmpty(root) && root->endofword == false) {
        delete (root);
        root = nullptr;
    }
    return root;
}
bool insert(TrieNode* root,string word){
    if(search(root,word)){
        return false;
    }
    TrieNode *curr=root;
    for(int i=0;i<word.length();i++){
        char c=word[i];
        if(!curr->childrens[c-'a']){
            curr->childrens[c-'a'] = getNode();
        }
        curr=curr->childrens[c-'a'];
    }
    curr->endofword= true;
    return true;
}
TrieNode *getNode()
{
    TrieNode *pNode =  new TrieNode;
    pNode->endofword = false;
    for (int i = 0; i <26; i++){
        pNode->childrens[i] = nullptr;}
    return pNode;
}
int main(int argc,char *argv[]){
    TrieNode *root= getNode();
    ifstream inputfile;
    inputfile.open(argv[1]);//input file
    ofstream out(argv[2]);
    string line;
    map<string,string> dict;
    if(inputfile.is_open()){
        while (getline(inputfile,line)){//reads input file line by line
            if(line=="list"){
                out<<"\nlisteleniyor..\n"<<endl;
            }else{
                if(line.rfind("search",0)==0){
                    if(search(root,line.substr(7,line.size()-8))){
                        out<<"\"The English equivalent is "<<dict[line.substr(7,line.length()-8)]<<'"'<<endl;
                    }else if(!search(root,line.substr(7,line.size()-8)) and x==27){
                        out<<"\"not enough Dothraki word\""<<endl;
                    }else if(!search(root,line.substr(7,line.size()-8)) and x==0){
                        out<<"\"no record\""<<endl;
                    }else{
                        out<<"\"incorrect Dothraki word\""<<endl;
                    }
                }
                else if(line.rfind("insert",0)==0){
                    if(insert(root,line.substr(7,line.rfind(',')-7))){
                        dict[line.substr(7,line.rfind(',')-7)]=line.substr(line.rfind(',')+1,line.length()-line.rfind(',')-2);
                        out<<'"'<<line.substr(7,line.rfind(',')-7)<<'"'<<" was added"<<endl;
                    }else if(search(root,line.substr(7,line.rfind(',')-7)) and
                    dict.at(line.substr(7,line.rfind(',')-7))!=line.substr(line.rfind(',')+1,line.length()-line.rfind(',')-2)){
                        dict[line.substr(7,line.rfind(',')-7)]=line.substr(line.rfind(',')+1,line.length()-line.rfind(',')-2);
                        out<<'"'<<line.substr(7,line.rfind(',')-7)<<'"'<<" was updated"<<endl;
                    }else{
                        out<<'"'<<line.substr(7,line.rfind(',')-7)<<'"'<<" already exist"<<endl;
                    }
                }
                else if(line.rfind("delete",0)==0){
                    if(search(root,line.substr(7,line.size()-8))){int depth=0;
                        remove(root,line.substr(7,line.size()-8),depth);
                        dict.erase(line.substr(7,line.size()-8));
                        out<<"\""<<line.substr(7,line.size()-8)<<"\" deletion is successful"<<endl;
                    }else if(!search(root,line.substr(7,line.size()-8)) and x==27){
                        out<<"\"not enough Dothraki word\""<<endl;
                    }else if(!search(root,line.substr(7,line.size()-8)) and x==0){
                        out<<"\"no record\""<<endl;
                    }else{
                        out<<"\"incorrect Dothraki word\""<<endl;
                    }
                }
            }
        }
    }
    inputfile.close();
    out.close();
    return 0;
}
