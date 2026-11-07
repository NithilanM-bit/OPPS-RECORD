
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Student
{
public:
string name;
int mark;
char grade;
};

int main()
{
vector<Student> students = {
{"Nithilan", 99, ' '},
{"Nikhilesh", 68, ' '},
{"Aakash", 77, ' '},
{"Mridhulaa", 96, ' '}
};

// Sort students based on marks
sort(students.begin(), students.end(),
[](Student a, Student b)
{
return a.mark > b.mark;
});

// Assign grades using transform
transform(students.begin(), students.end(),
students.begin(),
[](Student s)
{
if (s.mark >= 90)
s.grade = 'A';
else if (s.mark >= 75)
s.grade = 'B';
else if (s.mark >= 50)
s.grade = 'C';
else
s.grade = 'F';

return s;
});

// Find first student scoring above 80
auto it = find_if(students.begin(), students.end(),
[](Student s)
{
return s.mark > 80;
});

// Calculate total marks using accumulate
int total = accumulate(students.begin(), students.end(), 0,
[](int sum, Student s)
{
return sum + s.mark;
});

float average = (float)total / students.size();

// Display results
cout << "Student Grade Analyzer\n";

cout << "---------------------\n";

cout << "Name\tMark\tGrade\n";

for (Student s : students)
{
cout << s.name << "\t"
<< s.mark << "\t"
<< s.grade << endl;
}

if (it != students.end())
{
cout << "\nFirst student scoring above 80: "
<< it->name << endl;
}

cout << "Total Marks: " << total << endl;
cout << "Average Mark: " << average << endl;


// ADDITIONAL FEATURE 1: HIGHEST AND LOWEST SCORER

auto highest = max_element(students.begin(), students.end(),
[](Student a, Student b)
{
return a.mark < b.mark;
});

auto lowest = min_element(students.begin(), students.end(),
[](Student a, Student b)
{
return a.mark < b.mark;
});

cout << "\n========== PERFORMANCE HIGHLIGHTS ==========" << endl;

cout << "Highest Scorer: " << highest->name
<< " (" << highest->mark << ")" << endl;

cout << "Lowest Scorer: " << lowest->name
<< " (" << lowest->mark << ")" << endl;


// ADDITIONAL FEATURE 2: GRADE-WISE COUNT

int gradeA = count_if(students.begin(), students.end(),
[](Student s)
{
return s.grade == 'A';
});

int gradeB = count_if(students.begin(), students.end(),
[](Student s)
{
return s.grade == 'B';
});

int gradeC = count_if(students.begin(), students.end(),
[](Student s)
{
return s.grade == 'C';
});

int gradeF = count_if(students.begin(), students.end(),
[](Student s)
{
return s.grade == 'F';
});

cout << "\n========== GRADE DISTRIBUTION ==========" << endl;

cout << "Grade A: " << gradeA << " students" << endl;
cout << "Grade B: " << gradeB << " students" << endl;
cout << "Grade C: " << gradeC << " students" << endl;
cout << "Grade F: " << gradeF << " students" << endl;

return 0;
}
