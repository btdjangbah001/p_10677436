#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

template <class var>

void display(var textline){
    cout << textline;
}



struct course {
    int level;
    string subjects[10];
};

struct record{
    int semester;
    int credit_hr;
    string course_name;
    int mark;
    string grade;
};


class person
{
    public:
        person()
        {
            status = "null";
        }
        void setName(string val){
            name = val;
        }

        void setStatus(string val){
            status = val;
        }

        void setAge(int val){
            age = val;
        }

        void setID(int val){
            object_id = val;
        }

        void setIndex(int val){
            index = val;
        }

        void setResidence(string val){
            residence = val;
        }

        void listItems(vector <string> arrayVar){
            int len = arrayVar.size();
            for (int i=0;i<len;i++){
                display(arrayVar[i]);
                if ((i+1)%3 == 0){
                    display("\n");
                }else{
                    display("\t\t");
                }
            }
        }


        string getName(){
            return name;
        }

        string getStatus(){
            return status;
        }

        int getAge(){
            return age;
        }

        string getResidence(){
            return residence;
        }

        string getType(){
            return "person";
        }

        int getID(){
            return object_id;
        }

        int getIndex(){
            return index;
        }

        void getInfo(){
            cout << "\nname       : " << getName() << "\nage        : " << getAge() << "\nperson ID    : " << getID() <<endl;
        }

    private:
        string name;
        int age;
        int index;
        int object_id;
        string status;
        string residence;
};


struct student{
    person details;
    float schoolfees;
    int level;
    string course;
    string department;
    vector<string> subjects;
    vector<record> academic_records;
};

struct staff{
    person details;
    string job;
    string department;
    vector<string> subjects;
};


//###  functions prototypes  ##########
void addStudent(),editStudent(),manageStudent(),GpaCalc(student obj);
void addStaff(),editStaff(),manageStaff(),GpaCalc(student obj);
string lower(string line),gradeCalc(double score);
void stuinfo(student obj);
void stainfo(staff obj);

student Stu_database[10000];
staff Sta_database[10000];


int stu_base_id=10000000;
int sta_base_id=11000000;
int stu_count = 0;
int sta_count = 0;
string str;int number;



int main()
{
    display("		#############################################################################################################");
    display("\n		#############################################################################################################");
    display("\n		###                                                                                        ### BUILT BY:  ###");
    display("\n		###   ***         *** *****     *** ***             **********   **********                ### BERNARD    ###");
    display("\n		###   ***         *** ******    *** ***            ************  **********                ### TETTEH     ###");
    display("\n		###   ***         *** *******   *** ***           ***        *** ***                       ### DJANGBAH   ###");
    display("\n		###   ***         *** ***  ***  *** ***           ***        *** **********                ###            ###");
    display("\n		###    ***       ***  ***   *** *** ***           ***        *** **********                ##################");
    display("\n		###     ***** *****   ***    ****** ***           ***        *** ***                       ###            ###");
    display("\n		###      *********    ***     ***** *** ***        ************  ***                       ### ID NUMBER: ###");
    display("\n		###        *****      ***      **** *** ***         **********   ***                       ### 10677436   ###");
    display("\n		###                                                                                        ###            ###");
	display("\n		###     ***********  ***     ***        *****        *****     ***        *****            ##################");
	display("\n		###    ************  ***     ***       *******       ******    ***       *******           ##################");
	display("\n		###   ***            ***     ***      ***   ***      *******   ***      ***   ***          ##################");
	display("\n		###   ***     ****** ***********     ***     ***     ***  ***  ***     ***     ***         ##################");
	display("\n		###   ***     ****** ***********    *************    ***   *** ***    *************        ##################");
	display("\n		###   ***        *** ***     ***   ***************   ***    ******   ***************       ##################");
	display("\n		###    ************  ***     ***  ***           ***  ***     *****  ***           ***      ##################");
	display("\n		###     **********   ***     *** ***             *** ***      **** ***             ***     ##################");
	display("\n		###                                                                                        ##################");
	display("\n		#############################################################################################################");
    display("\n		#############################################################################################################\n");
    
    display("\n\n WELCOME TO THE SCHOOL MANAGEMENT SYSTEM. PLEASE ENTER THE NUMBER 1, 2 OR 0 TO EDIT STUDENT, STAFF OR TO EXIT RESPECTIVELY\n");
    string option;

    while (true){
       display("\n1. STUDENT \n2. STAFF \n0. EXIT\n");
       display("\nselect person : ");
       cin >> str;
       if (str == "1"){
            display("\nEDIT STUDENT");
            while (true){
                display("\n\n1. ADD - Add a new student");
				display("\n2. EDIT - Search and edit a student(name, age, level, course, department, student subjects, residence)"); 
				display("\n3. MANAGE - (Enter student's score, show academic records, remove student"); 
				display("\n0. EXIT");
                display("\n\nselect an option : ");
                cin >> option;
                if (option == "1"){
                    addStudent();
                }
                else if (option == "2"){
                    editStudent();
                }
                else if (option == "3"){
                    manageStudent();
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "2"){
            display("\nEDIT STAFF");
            while (true){
                display("\n\n1. ADD \n2. EDIT \n3. MANAGE \n0. EXIT");
                display("\n\nselect an option : ");
                cin >> option;
                if (option == "1"){
                    addStaff();
                }
                else if (option == "2"){
                    editStaff();
                }
                else if (option == "3"){
                    manageStaff();
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "0"){
            break;
        }
    }
    return 0;
}


void addStudent(){
    cin.clear();
    display("\n**************ADDING NEW STUDENT*****************");
    student temp;
    display("\nAssigned student ID : ");display(stu_base_id+stu_count);
    temp.details.setID(stu_base_id+stu_count);temp.details.setIndex(stu_count);stu_count++;
    string str;int number;
    display("\nEnter student's name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    display("\nEnter student's age : ");
    cin >> number;
    while (cin.fail()){
        display("\n( Invalid, age must be a number ) Try Again : ");
        cin.clear();cin.ignore();cin >> number;
    }
    temp.details.setAge(number);
    display("\nEnter department name : ");
    cin >> str;
    temp.department = str;
    display("\nEnter student's course : ");
    cin >> str;
    temp.course = str;
    display("\nEnter student's level : ");
    cin >> number;
    while (cin.fail()){
        display("\n( Invalid, level must be a number ) Try Again : ");
        cin.clear();cin.ignore();cin >> number;
    }
    while (number != 100 && number != 200 && number != 300 && number != 400){
        display("( Invalid, level must be 100, 200, 300 or 400 ) Enter Level  : ");
        cin >> number;
        while (cin.fail()){
            display("\n( invalid ) Try Again : ");
            cin.clear();cin.ignore();cin >> number;
        }
    }
    temp.level = number;
    display("\nEnter student's school fees : ");
    cin >> number;
    while (cin.fail()){
        display("\n( Invalid, school fees must be a number ) Try Again  : ");
        cin.clear();cin.ignore();cin >> number;
    }
    temp.schoolfees = number;

    Stu_database[temp.details.getIndex()] = temp;

    display("\nDo you want to add another student? (y/n) : ");
    cin >> str;
    if (str == "y"){
        addStudent();
    }
    else{
        
    }

};

void editStudent(){
int pass = 1;
display("\n( edit ) Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    display("\n( Invalid, student ID must be an eight (8) digit number assigned to the student when adding) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){

    stu_id -= stu_base_id;
    while (stu_id < 0 || stu_id >= stu_count){
        display("\n( Invalid, Student ID does not exist (make sure a student has been added first) ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            display("\n( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        display("\nStudent Found\n");
        student obj = Stu_database[stu_id];
        	stuinfo(obj);
        while (true){
            display("\n\n1. NAME \n2. AGE \n3. LEVEL \n4. COURSE \n5. DEPARTMENT \n6. STUDENT SUBJECTS \n7. RESIDENCE \n0. EXIT\n");
            display("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                display("\nStudents name : ");display(obj.details.getName());
                display("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.details.setName(str);
            }
            else if (edit == "2"){
                display("\nStudents age : ");display(obj.details.getAge());
                display("\n\nChange to : ");
                cin >> number;
                while (cin.fail()){
                    display("\n( Invalid, age must be a numer ) Try Again : ");
                    cin.clear();cin.ignore();cin >> number;
                }
                obj.details.setAge(number);
            }
            else if (edit == "3"){
                display("\nStudents level : ");display(obj.level);
                display("\n\nChange to : ");
                cin >> number;
                while (cin.fail()){
                    display("\n( Invalid, level must be a number ) Try Again : ");
                    cin.clear();cin.ignore();cin >> number;
                }
                while (number != 100 && number != 200 && number != 300 && number != 400){
                    display("\n\nChange to 100,200,300 or 400 : ");
                    cin >> number;
                    while (cin.fail()){
                        display("\n( invalid, level must be 100, 200, 300 or 400 ) Try Again : ");
                        cin.clear();cin.ignore();cin >> number;
                    }
                }
                obj.level = number;
            }
            else if (edit == "4"){
                display("\nStudents course : ");display(obj.course);
                cin.ignore();getline(cin, str);cin.clear();
                obj.course = str;
            }
            else if (edit == "5"){
                display("\nStudents Department : ");display(obj.department);
                display("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "6"){
                display("\n\n\nStudents subject : \n");
                while (true){
                    display("1. ADD SUBJECT(S) \n2. REMOVE SUBJECT(S) \n0. EXIT\n");
                    display("select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            display("\nEnter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                               record _new;
                               _new.course_name = str;
                               _new.mark = -1;
                               obj.academic_records.push_back(_new);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            display("\nEnter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        obj.academic_records.erase(obj.academic_records.begin()+i);
                                        display("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        display("\nCan't find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }

            }
            else if (edit == "7"){
                display("\nStudent's Residence : ");display(obj.details.getResidence());
                display("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                Stu_database[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStudent(){
int pass = 1;
display("\n( manage )Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    display("\n( Invalid, student ID must be an eight (8) digit number assigned to the student when adding ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){

    stu_id -= stu_base_id;
    while (stu_id < 0 || stu_id >= stu_count){
        display("\n( Invalid, Student ID does not exist (make sure a student has been added first) ) Enter Students ID or 0 to leave : : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            display("\n( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        
        display("\nStudent Found\n\n");
        	student obj = Stu_database[stu_id];
        	stuinfo(obj);
        
        while (true){
            display("\n\n1. Enter Student's Score (Student subject must be added first in EDIT)");
			display("\n2. Show Academic Records");
			display("\n3. Remove Student"); 
			display("\n0. Exit\n");
            display("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                int len = obj.subjects.size();
                display("Enter the semester? (1,2) : ");
                cin >> number;
                while (number != 1 && number != 2){
                    display("Enter the semester? (1,2) : ");
                    cin >> number;
                }
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark == -1){
                        display("\n\nSubject :\t");display(obj.academic_records[i].course_name);
                        display("\nDo you want to record marks for this subject : ");
                        cin >> str;str = lower(str);
                        while (str != "y" && str != "n"){
                            display("\nplease choose 'y' or 'n'");
                            cin >> str;
                            str = lower(str);
                        }
                        if (str == "y"){
                            int credit_h;
                            display("\nCredit Hour(s)\t:\t");
                            cin >> credit_h;
                            while (0 > credit_h || credit_h > 3){
                                display("(invalid) Credit Hour(s)\t:\t");
                                cin >> credit_h;
                            }
                            int score;
                            display("Enter Mark\t:\t");
                            cin >> score;
                            while (0 > score || score >100){
                                display("(invalid) Enter Mark\t:\t");
                                cin >> score;
                            }
                            obj.academic_records[i].mark = score;
                            obj.academic_records[i].credit_hr = score;
                            obj.academic_records[i].semester = number;
                            obj.academic_records[i].grade = gradeCalc(score);
                        }
                    }
                }
                Stu_database[obj.details.getIndex()] = obj;
            }
            else if (manage == "2"){
                int len = obj.subjects.size();
                display("\n\n############################################################################################");
                display("\n********************************************************************************************");
                display("\nName : ");display(obj.details.getName());display("\tDepartment : ");display(obj.department);
                display("\tCourse : ");display(obj.course);display("\tLevel : ");display(obj.level);display("\tGPA :\t");GpaCalc(obj);
                display("\n********************************************************************************************");
                display("\n============================================================================================");
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark != -1){
                        display("\n\nSubject :\t");display(obj.academic_records[i].course_name);
                        display("\t\tMark :\t");display(obj.academic_records[i].mark);
                        display("\t\tGrade :\t");display(obj.academic_records[i].grade);
                    }
                    else{
                        display("\n\nSubject :\t");display(obj.academic_records[i].course_name);
                        display("\t\tMark :\t");display("**N/A**");
                        display("\t\tGrade :\t");display("**N/A**");
                    }
                }
                display("\n\n============================================================================================");
                display("\n############################################################################################");
            }
            else if (manage == "3"){
                display("\nAre you sure you want to remove student? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    display("\nplease choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Stu_database[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                Stu_database[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};

void addStaff(){
    cin.clear();
    display("\n**************ADDING NEW STAFF*****************");
    staff temp;
    display("\n\nAssigned Staff ID : ");display(sta_base_id+sta_count);
    temp.details.setID(sta_base_id+sta_count);temp.details.setIndex(sta_count);sta_count++;
    string str;int number;
    display("\nEnter Staff Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    display("\nEnter Staff Age : ");
    cin >> number;
    while (cin.fail()){
        display("\n( invalid, age must be a number ) Try Again : ");
        cin.clear();cin.ignore();cin >> number;
    }
    temp.details.setAge(number);
    display("\nEnter Department Name : ");
    cin >> str;
    temp.department = str;

    display("\nEnter Staffs Job : ");
    cin >> str;
    temp.job = str;

    Sta_database[temp.details.getIndex()] = temp;

    display("\nDo you want to add another staff? (y/n) : ");
    cin >> str;
    if (str == "y"){
        addStaff();
    }
    else{
    }
};

void editStaff(){
int pass = 1;
display("\nEnter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    display("\n( Invalid, staff ID must be an eight (8) digit number assigned to the staff when adding) Try Again : ");
    cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    while (sta_id < 0 || sta_id >= sta_count){
        display("\n( invalid, staff ID does not exist (make sure a staff has been added first) ) Enter Staffs ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            display("\n( invalid ) Enter valid Staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        display("\nStaff Found\n");
        staff obj = Sta_database[sta_id];
        stainfo(obj);
        while (true){
            display("\n\n1. NAME \n2. AGE \n3. DEPARTMENT \n4. STAFF SUBJECTS \n5. RESIDENCE \n0. EXIT\n");
            display("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                display("\nStaffs name : ");display(obj.details.getName());
                display("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.details.setName(str);
            }
            else if (edit == "2"){
                display("\n\nChange to : ");
                cin >> number;
                while (cin.fail()){
                    display("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> number;
                }
                obj.details.setAge(number);
            }
            else if (edit == "3"){
                display("\nStaffs Department : ");display(obj.department);
                display("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "4"){
                display("\n\n\nStaffs subject : \n");
                while (true){
                    display("1. ADD SUBJECT");
					display("\n2. REMOVE SUBJECT");
					display("\n0. EXIT\n");
                    display("select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            display("\nenter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            display("\nenter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        display("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        display("\ncant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }
            }
            else if (edit == "5"){
                display("\nStaffs Residence : ");display(obj.details.getResidence());
                display("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                Sta_database[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStaff(){
int pass = 1;
display("\nEnter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    display("\n( Invalid, staff ID must be an eight (8) digit number assigned to the staff when adding ) Try Again : ");
    cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    while (sta_id < 0 || sta_id >= sta_count){
        display("\n( Invalid, make sure a staff has been added first ) Enter Staff ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            display("\n( Invalid, make sure ID is valid ) Enter valid staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        display("\nStaff Found\n");
        staff obj = Sta_database[sta_id];
        stainfo(obj);
        while (true){
            display("\n\n1. Remove Staff \n0. exit\n");
            display("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                display("\nAre you sure you want to remove staff? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    display("\nplease choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Sta_database[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                Sta_database[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};


string lower(string line){
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++){
        for (int j=0;j<26;j++){
            if (line[i] == UPPER[j]){
                ret_lower += LOWER[j];
                break;
            }
            else if (j == 25){
                ret_lower += line[i];
            }
        }

    }
    return ret_lower;
}


string gradeCalc(double score){
    if (79 < score && score <= 100){
        return "A";
    }
    else if(74 < score && score <= 79){
        return "B+";
    }
    else if(69 < score && score <= 74){
        return "B";
    }
    else if(64 < score && score <= 69){
        return "C+";
    }
    else if(59 < score && score <= 64){
        return "C";
    }
    else if(54 < score && score <= 59){
        return "D+";
    }
    else if(49 < score && score <= 54){
        return "D";
    }
    else if(44 < score && score <= 49){
        return "E";
    }
    else if(-1 < score && score <= 44){
        return "F";
    }
    else{
        return "invalid mark";
    }
}


float getGpaScore(string grade){
    if (grade == "A"){
        return 4.0;
    }
    else if (grade == "B+"){
        return 3.5;
    }
    else if (grade == "B"){
        return 3.0;
    }
    else if (grade == "C+"){
        return 2.5;
    }
    else if (grade == "C"){
        return 2.0;
    }
    else if (grade == "D+"){
        return 1.5;
    }
    else if (grade == "D"){
        return 1.0;
    }
    else if (grade == "E"){
        return 0.5;
    }
    else if (grade == "F"){
        return 0.0;
    }
    return -1;
}

void GpaCalc(student obj){
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> temp_record = obj.academic_records;
    for (int i=0;i<len;i++){
        if (temp_record[i].mark == -1){
            empty_score = true;
            cout << "**N/A**";
            break;
        }
        else{
            tch += temp_record[i].credit_hr;
            gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr;
        }
    }
    if (empty_score == false){
        if (len != 0){
            cout << gpa/tch;
        }
        else{
            cout << "**N/A**";
        }
    }
}

void stuinfo(student obj){
        display(obj.details.getID());
		display("\n");
		display(obj.details.getName()); 
		display("\n");
		display(obj.course);
		display("\n");
		display(obj.department);
		display("\n");
		display(obj.level);
		display("\n\n");
}

void stainfo(staff obj){
        display(obj.details.getID());
		display("\n");
		display(obj.details.getName()); 
		display("\n");
		display(obj.department);
		display("\n");
        display(obj.job);
        display("\n");
}
