// Main
#include <iostream>
#include <fstream>

using namespace std;

class Node {
	public:
	int listenport = 1;
	int writeport = 1;
	
	int start(string filename);
	

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

int main(){

/*
nodeA : listens @ NULL, sends to B
nodeB : listens @ 5000, sends to C
nodeC : listens @ 5005, sends to NULL

Each node receives their port congigurations from it's configuration file. The file should be located in the root of the startup directory. 


*/
	cout << "hello world\n";
	Node nodeA;
	nodeA.listenport = 8080;
	cout << nodeA.listenport << endl;
	nodeA.start("yeet.txt");
	
	Node nodeB;
	nodeB.start("foo.xyz");
	
	
	return 0;
}


