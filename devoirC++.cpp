#include<iostream> //input output lib
#include<fstream>  
#include<vector>   
#include<string>   
#include<math.h>   

using namespace std;

//function
vector<string> readfile(string name_f){
    ifstream file(name_f);
    //insert words file to a vector
    string word;
    vector <string> vf;
    while (file>>word)
    {
        vf.push_back(word);
    }
        file.close();
    return(vf);
};

void frequency_fun(vector<string>vfile1,vector<string>vfile2,vector<int>&vecfreq1,vector<int>&vecfreq2){

};

int dotproduct(vector<int>v1,vector<int>v2){
    int s(0);
    for(int i=0,n=v1.size();i<n;i++){
        s+=v1[i]+v2[i];
    }
    return s;
}
double cosimilarity(vector<int>v1,vector<int>v2){
    int dp;
    dp=dotproduct(v1,v2);

    return dp/(sqrt(v1.size())*sqrt(v2.size()));
}

int main(){ 
   
//read files and generate vectors
    string name_f1; //1st file
    string name_f2; //2nd file
    cout<<"Enter files names\n"; 
    cin>>name_f1>>name_f2; 
    vector <string> vf1; //vector of 1st/2nd file words
    vector <string> vf2; 
    vf1=readfile(name_f1); 
    vf2=readfile(name_f2);
  
    //calculate the frequency of all words
    vector<int>vecfreq1;
    vector<int>vecfreq2; 
    frequency_fun(vf1,vf2,vecfreq1,vecfreq2);
    //calculate the similarity 
    double sim; //similarity value btwn 2 vectors
    sim=cosimilarity(vecfreq1,vecfreq2);
    cout<<" The similarity ="<<""<<sim*100<<"%";
}

