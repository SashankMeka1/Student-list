#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Student{
	char name[20];
	int id;//student struct
	float gpa;
};
int add(char * response, vector<Student*>*list){
	Student *student = new Student;
	strcpy(student->name, strtok(response, ","));
	student->id = atoi(strtok(NULL, " ,"));
	student->gpa = strtof(strtok(NULL, " ,"), NULL);
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
			return main();
		}
	}
	cout << "Student not found"<<endl;
	return main();
}
int print(char * response, vector<Student*>*list){
	for(auto i = list->begin(); i !=list->end();++i){
		cout<<"Name, "<<(*i)->name<<" ID, "<<(*i)->id<<" GPA, "<<(*i)->gpa<<endl;
	}//loop through and print
	return main();	
}
int main(){
	static char response[100];//static for memory conservation
	static vector<Student*>*list = new vector<Student*>;//static so list is same
	cout << "ADD DELETE PRINT or QUIT. Caps lock only"<<endl;
	cin.getline(response,100);//get input
	if(strcmp(response, "ADD")==0){
		cout<< "Give student information in format:name,id,gpa.NO SPACES except in name."<<endl;
		cin.getline(response,100);//get student data
		if(strchr(strchr(response, ' ')+1, ' ')){
			cout << "NO SPACES except in name"<<endl;
			return main();
		}
		else{//take token of data and add to list
			add(response, list);
		}
	}
	else if(strcmp(response, "DELETE")==0){
		del(response, list);
	}
	else if(strcmp(response, "PRINT")==0){
		print(response, list);
	}
	else if(strcmp(response, "QUIT")==0){
		delete list;//dynamic so delete and end
		return 0;
	}
	cout << "Enter a valid command"<<endl;
	return main();//recurse
}
