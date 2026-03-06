#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    string currentClass;
    string fatherName;
    string fatherWork;
    string phone;
    string bloodGroup;
    int arrears;
    vector<int> feeHistory;
    int marks[3];
    int total;
    float percentage;

    Student() {}

    Student(string n,int r,string c,string fn,string fw,string ph,string bg,int ar,int m1,int m2,int m3)
    {
        name=n; roll=r; currentClass=c;
        fatherName=fn; fatherWork=fw; phone=ph; bloodGroup=bg;
        arrears=ar; marks[0]=m1; marks[1]=m2; marks[2]=m3;
        total = m1+m2+m3;
        percentage = total/3.0;
    }

    void display()
    {
        cout<<"\n------ Student Info ------\n";
        cout<<"Name: "<<name<<"\nRoll: "<<roll<<"\nClass: "<<currentClass;
        cout<<"\nFather: "<<fatherName<<"\nFather Work: "<<fatherWork;
        cout<<"\nPhone: "<<phone<<"\nBlood Group: "<<bloodGroup;
        cout<<"\nMarks: "<<marks[0]<<" "<<marks[1]<<" "<<marks[2]
            <<"\nTotal: "<<total<<"\nPercentage: "<<percentage<<"%"
            <<"\nArrears: "<<arrears<<"\nFee History: ";
        for(int f: feeHistory) cout<<f<<" ";
        cout<<endl;

        if(percentage>=90) cout<<"Grade: A+\n";
        else if(percentage>=80) cout<<"Grade: A\n";
        else if(percentage>=70) cout<<"Grade: B\n";
        else if(percentage>=60) cout<<"Grade: C\n";
        else cout<<"Grade: F\n";

        if(arrears>0) cout<<"**Warning: Student has arrears**\n";
    }

    void payFee(int amount)
    {
        feeHistory.push_back(amount);
        arrears -= amount;
        if(arrears<0) arrears=0;
        cout<<"Fee payment recorded!\n";
    }

    void updatePhone(string newPhone){ phone=newPhone; }
    void updateMarks(int m1,int m2,int m3)
    {
        marks[0]=m1; marks[1]=m2; marks[2]=m3;
        total = m1+m2+m3;
        percentage = total/3.0;
    }
    void updateClass(string cls){ currentClass = cls; }

    // Save to file
    void saveToFile(ofstream &out)
    {
        out<<name<<","<<roll<<","<<currentClass<<","<<fatherName<<","<<fatherWork
           <<","<<phone<<","<<bloodGroup<<","<<arrears<<","<<marks[0]<<","<<marks[1]<<","<<marks[2]<<",";
        for(int f:feeHistory) out<<f<<"|";
        out<<"\n";
    }

    void loadFromLine(string line)
    {
        stringstream ss(line);
        string item;
        getline(ss,name,',');
        getline(ss,item,','); roll=stoi(item);
        getline(ss,currentClass,',');
        getline(ss,fatherName,',');
        getline(ss,fatherWork,',');
        getline(ss,phone,',');
        getline(ss,bloodGroup,',');
        getline(ss,item,','); arrears=stoi(item);
        getline(ss,item,','); marks[0]=stoi(item);
        getline(ss,item,','); marks[1]=stoi(item);
        getline(ss,item,','); marks[2]=stoi(item);
        total=marks[0]+marks[1]+marks[2];
        percentage=total/3.0;
        getline(ss,item,',');
        feeHistory.clear();
        stringstream fs(item); string f;
        while(getline(fs,f,'|')) if(!f.empty()) feeHistory.push_back(stoi(f));
    }
};

// Utility functions
int searchStudent(vector<Student> &students,int roll)
{
    for(int i=0;i<students.size();i++)
        if(students[i].roll==roll) return i;
    return -1;
}

void loadStudents(vector<Student> &students)
{
    ifstream fin("students.txt");
    if(!fin) return;
    string line;
    while(getline(fin,line))
    {
        Student s;
        s.loadFromLine(line);
        students.push_back(s);
    }
    fin.close();
}

void saveStudents(vector<Student> &students)
{
    ofstream fout("students.txt");
    for(Student &s: students) s.saveToFile(fout);
    fout.close();
}

int main()
{
    vector<Student> students;
    loadStudents(students);

    int choice;
    do
    {
        cout<<"\n=== School Management Menu ===\n";
        cout<<"1 Add Student\n2 Display All\n3 Search\n4 Pay Fee\n5 Update Phone\n6 Update Marks/Class\n7 Delete Student\n8 Exit\nChoice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
        {
            string n,c,fn,fw,ph,bg;
            int r,ar,m1,m2,m3;
            cout<<"Name: "; cin>>n;
            cout<<"Roll: "; cin>>r;
            cout<<"Class: "; cin>>c;
            cout<<"Father Name: "; cin>>fn;
            cout<<"Father Work: "; cin>>fw;
            cout<<"Phone: "; cin>>ph;
            cout<<"Blood Group: "; cin>>bg;
            cout<<"Arrears: "; cin>>ar;
            cout<<"Marks (3): "; cin>>m1>>m2>>m3;

            students.push_back(Student(n,r,c,fn,fw,ph,bg,ar,m1,m2,m3));
            cout<<"Student Added!\n";
            break;
        }
        case 2:
            for(Student &s: students) s.display();
            break;
        case 3:
        {
            int r; cout<<"Roll to search: "; cin>>r;
            int idx = searchStudent(students,r);
            if(idx!=-1) students[idx].display();
            else cout<<"Not Found\n";
            break;
        }
        case 4:
        {
            int r,amt; cout<<"Roll: "; cin>>r; cout<<"Amount: "; cin>>amt;
            int idx = searchStudent(students,r);
            if(idx!=-1) students[idx].payFee(amt);
            else cout<<"Not Found\n";
            break;
        }
        case 5:
        {
            int r; string ph; cout<<"Roll: "; cin>>r; cout<<"New Phone: "; cin>>ph;
            int idx = searchStudent(students,r);
            if(idx!=-1) students[idx].updatePhone(ph);
            else cout<<"Not Found\n";
            break;
        }
        case 6:
        {
            int r; cout<<"Roll: "; cin>>r;
            int idx = searchStudent(students,r);
            if(idx!=-1)
            {
                int m1,m2,m3; string cls;
                cout<<"New Marks: "; cin>>m1>>m2>>m3;
                students[idx].updateMarks(m1,m2,m3);
                cout<<"New Class: "; cin>>cls;
                students[idx].updateClass(cls);
            }else cout<<"Not Found\n";
            break;
        }
        case 7:
        {
            int r; cout<<"Roll to delete: "; cin>>r;
            int idx = searchStudent(students,r);
            if(idx!=-1)
            {
                students.erase(students.begin()+idx);
                cout<<"Deleted!\n";
            }else cout<<"Not Found\n";
            break;
        }
        case 8:
            saveStudents(students);
            cout<<"Data saved. Exiting...\n";
            break;
        default:
            cout<<"Invalid choice\n";
        }

    }while(choice!=8);

    return 0;
}