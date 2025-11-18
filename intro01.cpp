#include<bits/stdc++.h>
#include<filesystem>
using namespace std;
namespace fs= std::filesystem;

class Info_Template
{
    public:
       string name, department, institution_name, faculty_name, city;
       int studentID;

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
    cin >> student.name; 
    cout << "Where do you live in? \n->";
    cin >> student.city;
    cout << "What your department name? \n->";
    cin >> student.department;
    cout << "What is your institution name? \n->";
    cin >> student.institution_name;
    cout << "What is your faculty name? \n->";
    cin >> student.faculty_name;
    cout << "What is your student ID? \n->";
    cin >> student.studentID;

    string filename = generate_filename(student.name);
    ofstream file(filename);
    cout << "Current working directory: " << fs::current_path() << endl;

    if (file.is_open())
    {
        file << "Student Intoduction\n";
        file << "----------------------\n";
        file << "Name: " << student.name << '\n';
        file << "Department: " << student.department << "\n";
        file << "Institution: " << student.institution_name << "\n";
        file << "Faculty: " << student.faculty_name << "\n";
        file << "City: " << student.city << "\n";
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