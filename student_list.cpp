#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main();
struct Student{
	char name[20];
	int id;//student struct
	char* gpa;
};
int add(char * response, vector<Student*>*list){
	//cast add data to struct and push back on vector
	Student *student = new Student;
	strcpy(student->name, strtok(response, ","));
	student->id = atoi(strtok(NULL, " ,"));
	student->gpa = strtok(NULL, " ,");
	list->push_back(student);
	return main();
}
int del(char * response, vector<Student*>*list){
	cout<<"ID?"<<endl;//loop through and delete
	cin >> response;
	for(auto i = list->begin(); i != list->end();++i){
		if((*i)->id == atoi(response)){
			delete *i;
			list->erase(i);
			cout << "Deleted"<<endl;
			cin.ignore(100, '\n');
			return main();
		}
	}
	cout << "Student not found"<<endl;
	cin.ignore(100, '\n');
	return main();
}
int print(char * response, vector<Student*>*list){
	for(auto i = list->begin(); i !=list->end();++i){
		cout<<"Name, "<<(*i)->name<<" ID, "<<(*i)->id<<" GPA, "<<setprecision(3)<< (*i)->gpa<<endl;
	}//loop through and print
	return main();	
}
int main(){
	static char response[100];//static for memory conservation
	static vector<Student*>*list = new vector<Student*>;//static so list is same
	cout << "ADD DELETE PRINT or QUIT. Caps lock only"<<endl;
	cin >> response;//get input
	cin.ignore(100, '\n');
	cin.clear();
	if(strcmp(response, "ADD")==0){
		cout<< "Give student information in format:name,id,gpa.NO SPACES except in name."<<endl;
		cin.getline(response,100);//get student data
		if(strchr(strchr(response, ' ')+1, ' ')){//keep out the spaces
			cout << "NO SPACES except in name"<<endl;
			return main();
		}
		else{//take token of data and add to list
			return add(response, list);
		}
	}
	else if(strcmp(response, "DELETE")==0){
		return del(response, list);
	}
	else if(strcmp(response, "PRINT")==0){
		return print(response, list);
	}
	else if(strcmp(response, "QUIT")==0){
		return 0;
	}
	cout << "Enter a valid command"<<endl;
	return main();//recurse
}
