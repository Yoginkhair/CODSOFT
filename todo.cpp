    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    void displayMenu();
    void addTask(vector<string>& tasks);
    void viewTasks(const vector<string>& tasks);
    void deleteTask(vector<string>& tasks);

    int main(){
        vector<string> tasks;
        int choice;
        do{
            displayMenu();
            cout<<"Enter your choice:";
            cin>>choice;
            switch(choice){
                case 1:
                    addTask(tasks);
                    break;
                case 2:
                    viewTasks(tasks);
                    break;
                case 3:
                    deleteTask(tasks);
                    break;
                case 4:
                    cout<<"Exiting the program. Goodbye!"<< endl;
                    break;
                default:
                    cout <<"Invalid choice. Please try again."<< endl;
                    break;
            }

        }while(choice != 4);
        return 0;
    }

    void displayMenu(){
        cout<<"\nTo-Do List Manager"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Delete Task"<<endl;
        cout<<"4. Exit"<<endl;
    }

    void addTask(vector<string>& tasks){
        cin.ignore();
        string task;
        cout<<"Enter the task: ";
        getline(cin, task);
        tasks.push_back(task);
        cout<<"Task added successfully!"<<endl;
    }

    void viewTasks(const vector<string>& tasks){
        if(tasks.empty()){
            cout<<"No tasks in the list."<<endl;
            return;
        }
        cout <<"\nYour Tasks:"<<endl;
        for(size_t i=0;i<tasks.size();++i){
            cout<<i+1<<". "<<tasks[i]<<endl;
        }
    }

    void deleteTask(vector<string>& tasks){
        if(tasks.empty()){
            cout<<"No tasks to delete."<<endl;
            return;
        }

        int taskNumber;
        viewTasks(tasks);
        cout<<"Enter the task number to delete: ";
        cin>>taskNumber;

        if(taskNumber<1||taskNumber>tasks.size()){
            cout<<"Invalid task number. Please try again."<<endl;
        }else{
            tasks.erase(tasks.begin()+taskNumber-1);
            cout<<"Task deleted successfully!"<<endl;
        }
    }