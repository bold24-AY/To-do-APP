#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Tasks{

    string name;
    bool completed;
    Tasks(string s){
        name = s;
        completed = false;

    }
};

void displayMenu(){
    cout << "                   ---------------------------------------------" << endl;
    cout << "                   ---------------- To-Do List ----------------" << endl;
    cout << "                   ---------------------------------------------" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;  
    cout << "3. Delete Tasks" <<endl;
    cout << "4. Change Complete Status of Task" <<endl;
    cout << "5. Exit" << endl;
    cout << "Enter the number "<<endl;          
}

void show(vector<Tasks> &tasks){

    int n = tasks.size();
    if (n == 0){
        cout << "No tasks available." << endl;
        return;
    }
    
    for(int i = 0 ; i < n ; i++){
        cout <<"    "<< i+1 << ". " << tasks[i].name <<"   status";
        if(tasks[i].completed){
            cout << " completed";
        }
        else{
            cout<< " incomplete ";
        }
        cout <<  endl;
    }

}

int main(){
    
    vector<Tasks> tasks;
    int user_choice;    // Here all of the tasks will be stored with its completed status
    while(true){
       
        displayMenu();
        cin>>user_choice;
        cin.ignore();

        if(user_choice == 1){
            string name_of_task;
            cout << "Enter Task Name"<<endl;
            getline(cin,name_of_task);
            tasks.push_back(Tasks(name_of_task));
            cout << "Task added "<<endl; 
        }


        else if(user_choice == 2){
            show(tasks);
        }



        else if(user_choice == 3){
            show(tasks);
            int task_to_be_deleted;
            cout << "Enter the task number to delete"<<endl;
            cin >> task_to_be_deleted;

            if(task_to_be_deleted > 0  && task_to_be_deleted <= tasks.size()){
            tasks.erase(tasks.begin() + task_to_be_deleted - 1);
            cout<<"Task Deleted" <<endl;}
            else {
                cout<<"No such Task number exist"<<endl;
            }
}




            else if(user_choice == 4){
            show(tasks);
            int task_to_be_changed;
            cout << "Enter the task number to mark it complete"<<endl;
            cin>>task_to_be_changed;

            if(task_to_be_changed > 0  && task_to_be_changed <= tasks.size()){
                tasks[task_to_be_changed - 1].completed = true;
            cout<<"Task marked as Completed" <<endl;}
            else {
                cout<<"No such Task number exist"<<endl;
            }


        }

        else if(user_choice == 5){
            cout <<"Exiting the To-Do List Application. Goodbye!"<<endl;
            break;
        }
        else {
            cout <<"Invalid Choice. Please try again."<<endl;
        }

    }

return 0;


}
