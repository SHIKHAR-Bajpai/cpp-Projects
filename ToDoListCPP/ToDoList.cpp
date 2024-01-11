#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
using namespace std;


struct Task{
    string Title ;
    string status ;

    Task(string &desc) : Title(desc), status("Pending") {}
};

class ToDoList{

    private: 
        map <string , string > tasks;
    public :
        void addtask(){
            string temp;
            cout<<"\nEnter task Title: ";
            cin>>temp;            
            tasks[temp] = "Pending";
            cout<<"\nTask added successfully\n";
            return ;
        }

        void markAsCompleted(string &s){
            if(tasks.find(s) != tasks.end()){
                tasks[s] = "Completed";
            }
            else{
                cout<<"\nTask not Present\n\nInvalid Task !!"<<endl;
            }
            return ;
        }

        void showtask(){
            cout<<"\nYour Tasks :\n";
            for(auto it: tasks ){
                cout<<it.first<<" : "<<it.second;
                cout<<endl;
            }
            cout<<endl;
        }

        void showpending(){
            cout<<"\nTasks to be done: \n"<<endl;
            for(auto it : tasks){
                if(it.second == "Pending"){
                    cout<<it.first<<" : "<<it.second;
                    cout<<endl;
                }
            }
            cout<<endl;
        }

        void showcompleted(){
            cout<<"\nCompleted Tasks: \n"<<endl;
            for(auto it : tasks){
                if(it.second == "Completed"){
                    cout<<it.first<<" : "<<it.second;
                    cout<<endl;
                }
            }
            cout<<endl;
        }
};

int main(){
    ToDoList obj;
    cout<<"\n !!Welcome!!\n\n";
    int choice;

    while(true){
        sleep(1);
        cout<<"Available Options :\n";
        cout<<"1. Display all Tasks\n";
        cout<<"2. Display pending Tasks\n";
        cout<<"3. Add Task\n";
        cout<<"4. Mark as Completed\n";
        cout<<"5. Display Completed Tasks\n";
        cout<<"6. Exit\n";

        cout<<"\nEnter your choice: ";
        cin>>choice;

        string temp ;
        int flag = 0;

        switch(choice)
        {
        case 1:
            obj.showtask();
            break;

        case 2:
            obj.showpending();
            break;
        
        case 3:
            obj.addtask();
            cout<<"\nDo you want to add more task ?\nIf Yes enter 1 else 0:";
            cin >> flag;
            while(flag){
                obj.addtask();
                cout<<"\nDo you want to add more task ?\nIf Yes enter 1 else 0 :";
                cin >> flag;
            }
            cout<<endl;
            break;

        case 4:
            cout<<"\nEnter the task to be mark completed: ";
            cin>>temp;
            obj.markAsCompleted(temp);
            cout<<"\nMarked as Completed...\n\n";
            break;

        case 5:
            obj.showcompleted();
            break;

        case 6:
            cout<<"\nThankyou !! ";
            cout<<"\U0001F604";
            cout<<endl;
            sleep(3);
            exit(0);

        default:
            cout<<"\nInvalid Choice\n";
            cout<<"\nThankyou !! ";
            cout<<"\U0001F604";
            cout<<endl;
            sleep(3);
            exit(0);
        }
    }

return 0;
}