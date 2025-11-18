#include<bits/stdc++.h>
#include<filesystem>
using namespace std;
namespace fs= std::filesystem;

class Info_Template
{
    public:
        class About
        {
            public:
            string name, father_name, mother_name, date_of_birth, call_me;
            
        }About;
        class Institutional_info
        {
            public:
            string department, faculty_name, department_address, department_head_name, course_teacher_name;
            int  studentID, department_phone_number, department_head_phone_number, course_teacher_phone_number;
        }Institutional_info;

        class Contact_info
        {
            public:
            int phone_number;
            string email_address;
        }Contact_info;
        class Address
        {
            public:
            string house_number, road_number, area_name, postal_code, district_name, division_name;  
        }Address;


};

string generate_filename(const string& basename)
{
    string folder = "students data\\";

    fs::create_directories(folder);  // Ensures the folder exists. If it doesn’t, it creates it.

    
    string filename = folder + basename + ".txt";
    int counter = 1;

    while (fs::exists(filename))  // Checks if the file already exists. If it does, it appends a counter (John1.txt, John2.txt, etc.) until it finds a free name
    {
        filename = folder + basename + to_string(counter);
        counter++;
    }
    return filename;
}

void get_intro()
{
    Info_Template student;

    cout << "What is your name? \n ->";
    getline(cin, student.About.name); 
    cout << "What is your Father's name? \n ->";
    getline(cin, student.About.father_name); 
    cout << "What is your Mother's name? \n ->";
    getline(cin, student.About.mother_name); 
    cout << "What is your Date of Birth? \n ->";
    getline(cin, student.About.date_of_birth);
    cout << "What name we call you? \n ->";
    getline(cin, student.About.call_me);

    cout << "What your department name? \n->";
    getline(cin , student.Institutional_info.department);
    cout << "What is your Faculty name? \n->";
    getline(cin , student.Institutional_info.faculty_name);
    cout << "What is your Department Address? \n->";
    getline(cin, student.Institutional_info.department_address);
    cout << "What is your Department Head's name? \n->";
    getline(cin, student.Institutional_info.department_head_name);
    cout << "What is your course teacher's name? \n->";
    getline(cin, student.Institutional_info.course_teacher_name);
    cout << "What is your Student ID? \n->";
    cin >> student.Institutional_info.studentID;
    cout << "What is your Department's Phone Number? \n->";
    cin >> student.Institutional_info.department_phone_number;
    cout << "What is your Department's Head Phone Number? \n->";
    cin >> student.Institutional_info.department_head_phone_number;
    cout << "What is your Course Teacher's Phone Number? \n->";
    cin >> student.Institutional_info.course_teacher_phone_number;

    cout << "What is your Phone Number? \n->";
    cin >> student.Contact_info.phone_number;
    cout << "What is your Email address? \n->";
    getline(cin, student.Contact_info.email_address);

    cout << "What is your House Number? \n->";
    getline(cin, student.Address.house_number);
    cout << "What is your Road Number? \n->";
    getline(cin, student.Address.road_number);
    cout << "What is your Area Name? \n->";
    getline(cin, student.Address.area_name);
    cout << "What is your Postal code? \n->";
    getline(cin, student.Address.postal_code);
    cout << "What is your District Name? \n->";
    getline(cin, student.Address.district_name);
    cout << "What is your Division Name? \n->";
    getline(cin, student.Address.division_name);
    

    string filename = generate_filename(student.About.name);
    ofstream file(filename);
    cout << "Current working directory: " << fs::current_path() << endl;

    if (file.is_open())
    {
        file << "Student Introduction\n";
        file << "----------------------\n\n";

        file << "About\n";
        file << "  Name: " << student.About.name << "\n";
        file << "  Father: " << student.About.father_name << "\n";
        file << "  Mother: " << student.About.mother_name << "\n";
        file << "  Date of Birth: " << student.About.date_of_birth << "\n";
        file << "  Preferred name: " << student.About.call_me << "\n\n";

        file << "Institutional Information\n";
        file << "  Department: " << student.Institutional_info.department << "\n";
        file << "  Faculty: " << student.Institutional_info.faculty_name << "\n";
        file << "  Department Address: " << student.Institutional_info.department_address << "\n";
        file << "  Department Head: " << student.Institutional_info.department_head_name << "\n";
        file << "  Course Teacher: " << student.Institutional_info.course_teacher_name << "\n";
        file << "  Student ID: " << student.Institutional_info.studentID << "\n";
        file << "  Department Phone: " << student.Institutional_info.department_phone_number << "\n";
        file << "  Dept. Head Phone: " << student.Institutional_info.department_head_phone_number << "\n";
        file << "  Course Teacher Phone: " << student.Institutional_info.course_teacher_phone_number << "\n\n";

        file << "Contact\n";
        file << "  Phone: " << student.Contact_info.phone_number << "\n";
        file << "  Email: " << student.Contact_info.email_address << "\n\n";

        file << "Address\n";
        file << "  House: " << student.Address.house_number << "\n";
        file << "  Road: " << student.Address.road_number << "\n";
        file << "  Area: " << student.Address.area_name << "\n";
        file << "  Postal Code: " << student.Address.postal_code << "\n";
        file << "  District: " << student.Address.district_name << "\n";
        file << "  Division: " << student.Address.division_name << "\n";
        file.close();
        cout << "\n information saved to " << filename << endl;

    }
    else
        cout << "❌ Could not open file for writing!" << '\n';

}

int main()
{
    get_intro();
    
    return 0;
}