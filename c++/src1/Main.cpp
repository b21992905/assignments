#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;
stack<string> last;
string printstack(stack<string> s);
bool controlstr(vector<vector<string>> t , string q,string str,int *a);
bool controlemptystack(stack<string> s);
bool controlexcept(vector<vector<string>> t,string a,string z,string q);
int main(int argc,char *argv[]) {
    ifstream dpda;
    dpda.open(argv[1]);
    ifstream dpda2;
    dpda2.open(argv[2]);
    ofstream output(argv[3]);
    string  line;string line2;
    string q;string a;string z;
    string finals;
    string first;
    vector<vector<string>> t;
    if(dpda.is_open()){
        while(getline(dpda,line)){
            if(line.rfind("Q:",0)==0){
                q=line.substr(2,line.find("=>")-3);
                first=line.substr(line.rfind(" (")+2,line.rfind("),")-line.rfind(" (")-2);
                finals=line.substr(line.rfind("),")+2);
            }else if(line.rfind("A:",0)==0){
                string l=line.substr(2);
                a=l;
            }else if(line.rfind("Z:",0)==0){
                string l=line.substr(2);
                z=l;
            }else if(line.rfind("T:",0)==0) {
                string l=line.substr(2);
                istringstream is(l);
                string string1;
                vector<string> ek;
                while(getline(is,string1,',')) {
                    ek.push_back(string1);
                    }
                t.push_back(ek);
            }
        }
    }
    dpda.close();
    if(!controlexcept(t,a,z,q)){
        output<<"Error [1]:DPDA description is invalid!";
        output.close();
        exit(0);
    }
    while (getline(dpda2, line2))
    {
        last=stack<string>();
        if(line2.empty()){
            output<<"\nACCEPT\n\n";
            continue;
        }
        istringstream iss(line2);
        string str;
        string whichq=first;int a=-1;
        while (getline(iss, str, ','))
        {
            for(int i=0; i < t.size(); i++){
                //$ işareti sonradan eklenmiyor. hiçbir şey uymuyorsa reject
                if(whichq==first and controlstr(t,whichq,str,&a)){//qo 1  3 q e
                    output << t[a][0]+"," +t[a][1]+","+t[a][2] +" => "+t[a][3]+","+t[a][4];
                    whichq=t[a][3];
                    if((t[a][4]!="e" and t[a][4]!="$" and !last.empty()) || (last.empty() and t[a][4]!="e")){last.push(t[a][4]);}
                    output<<" [STACK]:"+ printstack(last)+"\n";
                    break;
                }else if(whichq==first and t[i][0] == whichq and t[i][2]=="e" and t[i][1]=="e"){
                    output << t[i][0]+"," +t[i][1]+","+t[i][2] +" => "+t[i][3]+","+t[i][4];
                    whichq=t[i][3];
                    if((t[i][4]!="e" and t[i][4]!="$" and !last.empty()) || (last.empty() and t[i][4]!="e")){last.push(t[i][4]);}
                    output<<" [STACK]:"+ printstack(last)+"\n";
                    continue;
                }else if(t[i][0] == whichq and t[i][1]==str and (last.top()==t[i][2] || t[i][2]=="e")){
                    if(t[i][2]==last.top()){last.pop();}
                    output << t[i][0]+"," +t[i][1]+","+t[i][2] +" => "+t[i][3]+","+t[i][4];
                    whichq=t[i][3];
                    if((t[i][4]!="e" and t[i][4]!="$" and !last.empty()) || (last.empty() and t[i][4]!="e")){last.push(t[i][4]);}
                    output<<" [STACK]:"+ printstack(last)+"\n";
                    break;
                }else if(t[i][0] == whichq and t[i][1]=="e" and (last.top()==t[i][2] || t[i][2]=="e")){
                    if(t[i][2]==last.top()){last.pop();}
                    output << t[i][0]+"," +t[i][1]+","+t[i][2] +" => "+t[i][3]+","+t[i][4];
                    whichq=t[i][3];
                    if((t[i][4]!="e" and t[i][4]!="$" and !last.empty()) || (last.empty() and t[i][4]!="e")){last.push(t[i][4]);}
                    output<<" [STACK]:"+ printstack(last)+"\n";
                    continue;
                }
            }
        }
        for(int i=0; i < t.size(); i++){
            if(t[i][0] == whichq and t[i][1]=="e" and ((!last.empty() and last.top()==t[i][2]) || t[i][2]=="e")){
                if(!last.empty() and t[i][2]==last.top()){last.pop();}
                output << t[i][0]+"," +t[i][1]+","+t[i][2] +" => "+t[i][3]+","+t[i][4];
                whichq=t[i][3];
                if((t[i][4]!="e" and t[i][4]!="$" and !last.empty()) || (last.empty() and t[i][4]!="e")){last.push(t[i][4]);}
                output<<" [STACK]:"+ printstack(last)+"\n";
                break;
            }
        }
        if(controlemptystack(last) and finals.find(whichq)!=-1){
            output<<"ACCEPT\n\n";
        }else{output<<"REJECT\n\n";}
    }
    output.close();
    dpda2.close();
    return 0;
}
bool controlstr(vector<vector<string>> t , string q,string str,int *a){
    for(int i=0; i < t.size(); i++){
        if(t[i][0] == q and t[i][2]=="e" and t[i][1]==str){
            *a=i;
            return true;
        }
    }
    return false;
}
string printstack(stack<string > s){
    string show;
    stack<string> stack1=s;
    while (!stack1.empty()) {
        show.insert(0,stack1.top());
        show.insert(0,",");
        stack1.pop();
    }
    if(show.empty()){
        return show;
    }
    return show.substr(1);
}
bool controlemptystack(stack<string> s){
    if(s.empty() || (s.size()==1 and s.top()=="$")){
        return true;
    }
    return false;
}
bool controlexcept(vector<vector<string>> t,string a,string z,string q){
    for(int i=0;i<t.size();i++){
        if(q.find(t[i][0])==-1 || q.find(t[i][3])==-1){
            return false;
        }else if((t[i][2]!="e" and z.find(t[i][2])==-1) || (t[i][4]!="e" and z.find(t[i][4])==-1)){
            return false;
        }else if(a.find(t[i][1])==-1 and t[i][1]!="e"){
            return false;
        }
    }
    return true;
}