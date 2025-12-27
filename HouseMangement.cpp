#include <iostream>
using namespace std;
int main(){
    string task[20];
    int time[20];
    int taskCount =0;
    int choice;
    int totalTime =0;
    do
    {
        cout<<"\n----------------------";
        cout<<"\n  HOME MANAGEMENTS SYSTEM";
        cout<<"\n1. Add task";
        cout<<"\n2. View task";
        cout<<"\n3. View total Time";
        cout<<"\n4. Exit";
        cout<<"\n------------------------";
        cout<<"\nEnter you choice: ";
        cin>>choice;
        switch (choice)
        {
        case1:
            cout<<"\nEnter task name: ";
            cin>>task[taskCount];

            cout<<"Enter time required(in hours): ";
            cin>>time[taskCount];
            totalTime +=time[taskCount];
            tiem++;
            break;
        case 2:
        if (taskCount ==0)
        {
            cout<<"\nNo task availabe.";
        }else{
            cout<<"\n\n--------Task List-----------";
            for (int i = 0; i < taskCount; i++)
            {
                cout<<"\nTask" <<i +1 <<":"<< task[i]<<"| Time: "<<time[i]<<"hours";

            }
            
        }break;
        case 3:

    cout<<"\nTotal Time Required: "<<totalTime<<"hours";
    break;
    case 4:
    cout<<"\nExiting program...........";
    break;
        
        default:
        cout<<"\nInvalid choice! Please try again.";
            break;
        }
    } while (choice !=4);
    return 0;
}