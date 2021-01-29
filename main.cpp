// Main
#include <iostream>
#include <fstream>
#include <thread>
#include <filesystem>
#include <regex>

using namespace std;

class Node {
	public:
	int listenport = 1;
	int writeport = 1;
	
	int start(string filename);
	void test();
	Node();
	Node(string filename);
	

};
/*### 	Function: start(filename)
# 	Purpose: To declare a new network node with parameters specified in a configuration file. 
# 		
#	Strategy:  Reads the specified file, line by line. Each parameter is separated by newline. 
		
		Line 1: Port this node listens to for incoming traffic. Use 'null' if value not set
		Line 2: Port this node sends traffic to. Use 'null' if value not set. 
		Lines 3-N: ASCII data that is read by the node & sent to it's sending node. Every 
			line in this file is guaranteed to be 100 characters or less
		
#		 
#		 
###*/
int Node::start(string filename){
	cout << "starting: " << filename << endl;

	std:ifstream nodeFile{filename};
	if (!nodeFile){
		std::cerr<< filename <<": could not be read. Check the filename please"<<endl;
		return -1;
	}
	std::string strInput;
	nodeFile >> strInput;
	cout<< strInput << endl;
	
	return 0;
}

Node::Node(string filename){
	//std::thread t(&Node::test, this);
	
	
}
void Node::test(){
	cout<<"tatas"<<endl;
}

Node::Node(){

}

string getConfigFileList(){
/*
string files[3] = {"confA.txt", "confB.txt", "confC.txt"};
*/
	regex r ("./conf[A-Z].txt");
	std::string path = "./";
	string result = "";

	bool firstLoop = true;
	for (const auto & entry : std::filesystem::directory_iterator(path)){
		//Debug line
		std::cout << "Found File: " << entry.path() << std::endl;
		
		string l = entry.path(); 
		if(regex_match(l,r)){
			if(firstLoop == true){
			//Do cool string concat/append 
				result = l;
				firstLoop = false;
			} else {
				result = result + "," + l;
			}
		}
	}
	return result;
}

/************************************************
nodeA : listens @ NULL, sends to B
nodeB : listens @ 5000, sends to C
nodeC : listens @ 5005, sends to NULL

Each node receives their port congigurations from it's configuration file. The file should be located in the root of the startup directory. 
*************************************************/
int main(){
	cout << getConfigFileList() <<endl;

	Node nodeA;
	nodeA.listenport = 8080;
	cout << nodeA.listenport << endl;
	nodeA.start("./yeet.txt");
	
	Node nodeB("./yeet.txt");

	//for(int i = 0; i<){}

	std::thread th1(&Node::test, Node());
	//std::thread th2()
	th1.join();
	
	return 0;
}


