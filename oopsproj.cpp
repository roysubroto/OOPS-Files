#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <sstream>
using namespace std;
// changes done
class Employee
{
protected:
    int empID;
    string name;
    string position;
    string department;

public:
    Employee(int id = 0, string n = "", string pos = "", string dept = "")
        : empID(id), name(n), position(pos), department(dept) {}
    int getId() { return empID; }
    virtual void displayInfo() = 0;
    virtual void saveToFile(ofstream &outFile) = 0;
    virtual void updateInfo() = 0;
    string getName() { return name; }
};

class fullTime : public Employee
{
private:
    double salary;

public:
    fullTime(int id, string n, string pos, string dept, double sal)
        : Employee(id, n, pos, dept), salary(sal) {}

    void displayInfo() override
    {
        cout << "FullTime ID: " << empID << "\nName: " << name
             << "\nSalary: $" << salary << "\nPosition: " << position
             << "\nDepartment: " << department << endl;
    }

    void saveToFile(ofstream &outFile) override
    {
        outFile << "FullTime " << empID << " " << name << " " << position << " "
                << department << " " << salary << endl;
    }

    void updateInfo() override
    {
        cout << "Updating FullTime Employee (ID: " << empID << ")\n";
        cout << "Enter new name: ";
        cin >> name;
        cout << "Enter new position: ";
        cin >> position;
        cout << "Enter new department: ";
        cin >> department;
        cout << "Enter new salary: ";
        cin >> salary;
    }
};

class partTime : public Employee
{
private:
    double salary;

public:
    partTime(int id, string n, string pos, string dept, double sal)
        : Employee(id, n, pos, dept), salary(sal) {}

    void displayInfo() override
    {
        cout << "PartTime ID: " << empID << "\nName: " << name
             << "\nSalary: $" << salary << "\nPosition: " << position
             << "\nDepartment: " << department << endl;
    }

    void saveToFile(ofstream &outFile) override
    {
        outFile << "PartTime " << empID << " " << name << " " << position << " "
                << department << " " << salary << endl;
    }

    void updateInfo() override
    {
        cout << "Updating PartTime Employee (ID: " << empID << ")\n";
        cout << "Enter new name: ";
        cin >> name;
        cout << "Enter new position: ";
        cin >> position;
        cout << "Enter new department: ";
        cin >> department;
        cout << "Enter new salary: ";
        cin >> salary;
    }
};

class Project
{
protected:
    string projectName;
    string deadline;
    double budget;

public:
    Project(string name = "", string dl = "", double budg = 0.0)
        : projectName(name), deadline(dl), budget(budg) {}

    virtual void displayProjectInfo() = 0;
    virtual void saveToFile(ofstream &outFile) = 0;
    virtual void updateProject() = 0;
};

class ResearchProject : public Project
{
private:
    string researchTopic;

public:
    ResearchProject(string name, string dl, double budg, string topic)
        : Project(name, dl, budg), researchTopic(topic) {}

    void displayProjectInfo() override
    {
        cout << "Research Project: " << projectName << "\nDeadline: " << deadline
             << "\nBudget: $" << budget << "\nTopic: " << researchTopic << endl;
    }

    void saveToFile(ofstream &outFile) override
    {
        outFile << "ResearchProject " << projectName << " " << deadline << " "
                << budget << " " << researchTopic << endl;
    }

    void updateProject() override
    {
        cout << "Updating Research Project: " << projectName << endl;
        cout << "Enter new project name: ";
        cin >> projectName;
        cout << "Enter new deadline: ";
        cin >> deadline;
        cout << "Enter new budget: ";
        cin >> budget;
        cout << "Enter new research topic: ";
        cin >> researchTopic;
    }
};

class DevelopmentProject : public Project
{
private:
    string technologyname;

public:
    DevelopmentProject(string name, string dl, double budg, string tech)
        : Project(name, dl, budg), technologyname(tech) {}

    void displayProjectInfo() override
    {
        cout << "Development Project: " << projectName
             << "\nDeadline: " << deadline << "\nBudget: $" << budget
             << "\nTechnology Stack: " << technologyname << endl;
    }

    void saveToFile(ofstream &outFile) override
    {
        outFile << "DevelopmentProject " << projectName << " " << deadline
                << " " << budget << " " << technologyname << endl;
    }

    void updateProject() override
    {
        cout << "Updating Development Project: " << projectName << endl;
        cout << "Enter new project name: ";
        cin >> projectName;
        cout << "Enter new deadline: ";
        cin >> deadline;
        cout << "Enter new budget: ";
        cin >> budget;
        cout << "Enter new technology stack: ";
        cin >> technologyname;
    }
};

class Team
{
private:
    string teamName;
    unique_ptr<Project> project;
    vector<shared_ptr<Employee>> members;

public:
    Team(string name = "") : teamName(name) {}

    string getTeamName() const { return teamName; }

    void setProject(unique_ptr<Project> proj) { project = move(proj); }

    void addMember(shared_ptr<Employee> emp) { members.push_back(emp); }

    void displayTeamInfo()
    {
        cout << "Team Name: " << teamName << endl;
        if (project)
        {
            project->displayProjectInfo();
        }
        else
        {
            cout << "No project assigned." << endl;
        }
        cout << "Members: " << endl;
        for (const auto &member : members)
        {
            member->displayInfo();
        }
    }

    void saveToFile(ofstream &outFile)
    {
        outFile << "Team " << teamName << endl;
        if (project)
        {
            project->saveToFile(outFile);
        }
        for (const auto &member : members)
        {
            member->saveToFile(outFile);
        }
        outFile << "EndTeam" << endl;
    }

    void updateTeam()
    {
        cout << "Updating Team: " << teamName << endl;
        cout << "Enter new team name: ";
        cin >> teamName;
    }

    void deleteMemberById(int id)
    {
        auto it = remove_if(members.begin(), members.end(),
                            [id](shared_ptr<Employee> emp)
                            {
                                return emp->getId() == id;
                            });
        members.erase(it, members.end());
        cout << "Member with ID " << id << " deleted from team.\n";
    }

    vector<shared_ptr<Employee>> &getMembers() { return members; }

    unique_ptr<Project> &getProject() { return project; }
};

class Company
{
private:
    string companyName;
    string headquarters;
    double totalRevenue;
    vector<shared_ptr<Team>> teams;

public:
    Company(string name = "", string hq = "", double revenue = 0.0)
        : companyName(name), headquarters(hq), totalRevenue(revenue) {}

    string getCompanyName() const { return companyName; }

    void addTeam(shared_ptr<Team> team) { teams.push_back(team); }

    void displayCompanyInfo() const
    {
        cout << "\nCompany: " << companyName << "\nHeadquarters: " << headquarters
             << "\nTotal Revenue: $" << totalRevenue << "\nTeams:\n";
        for (size_t i = 0; i < teams.size(); ++i)
        {
            cout << i << ": ";
            teams[i]->displayTeamInfo();
        }
    }

    void saveToFile(ofstream &outFile) const
    {
        outFile << "Company " << companyName << " " << headquarters << " "
                << totalRevenue << endl;
        for (const auto &team : teams)
        {
            team->saveToFile(outFile);
        }
        outFile << "EndCompany" << endl;
    }

    vector<shared_ptr<Team>> &getTeams() { return teams; }

    void deleteTeamByName(const string &teamName)
    {
        auto it = remove_if(teams.begin(), teams.end(),
                            [&teamName](shared_ptr<Team> team)
                            {
                                return team->getTeamName() == teamName;
                            });
        teams.erase(it, teams.end());
        cout << "Team '" << teamName << "' deleted from company.\n";
    }
    
    void updateCompanyInfo()
    {
        cout << "Updating Company: " << companyName << endl;
        cout << "Enter new name: ";
        cin >> companyName;
        cout << "Enter new headquarters: ";
        cin >> headquarters;
        cout << "Enter new revenue: ";
        cin >> totalRevenue;
    }

    size_t getNumberOfTeams() const { return teams.size(); }

    shared_ptr<Team> getTeam(size_t index) const { return teams.at(index); }
};
vector<Company> companies;
void readFromFile()
{
    ifstream inFile("company_data.txt");
    if (!inFile.is_open())
    {
        cout << "Error: Unable to open the file.\n";
        return;
    }
    companies.clear();
    string line;
    while (getline(inFile, line))
    {
        if (line.rfind("Company", 0) == 0)
        {
            stringstream ss(line);
            string temp, companyName, headquarters;
            double revenue;
            ss >> temp >> companyName >> headquarters >> revenue;
            companies.emplace_back(companyName, headquarters, revenue);
            while (getline(inFile, line) && line.rfind("EndCompany", 0) != 0)
            {
                if (line.rfind("Team", 0) == 0)
                {
                    stringstream teamSS(line);
                    string tempTeam, teamName;
                    teamSS >> tempTeam >> teamName;
                    auto team = make_shared<Team>(teamName);
                    companies.back().addTeam(team);
                    while (getline(inFile, line) && line.rfind("EndTeam", 0) != 0)
                    {
                        if (line.rfind("ResearchProject", 0) == 0)
                        {
                            stringstream projSS(line);
                            string tempProj, projName, deadline, topic;
                            double budget;
                            projSS >> tempProj >> projName >> deadline >> budget >> topic;
                            team->setProject(make_unique<ResearchProject>(projName, deadline, budget, topic));
                        }
                        else if (line.rfind("DevelopmentProject", 0) == 0)
                        {
                            stringstream projSS(line);
                            string tempProj, projName, deadline, tech;
                            double budget;
                            projSS >> tempProj >> projName >> deadline >> budget >> tech;
                            team->setProject(make_unique<DevelopmentProject>(projName, deadline, budget, tech));
                        }
                        else if (line.rfind("FullTime", 0) == 0 || line.rfind("PartTime", 0) == 0)
                        {
                            stringstream empSS(line);
                            string type, name, position, department;
                            int id;
                            double salary;
                            empSS >> type >> id >> name >> position >> department >> salary;
                            if (type == "FullTime")
                            {
                                team->addMember(make_shared<fullTime>(id, name, position, department, salary));
                            }
                            else if (type == "PartTime")
                            {
                                team->addMember(make_shared<partTime>(id, name, position, department, salary));
                            }
                        }
                    }
                }
            }
        }
    }
    inFile.close();
}

int main()
{

    readFromFile();
    int choice;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add company\n";
        cout << "2. Add team to a company\n";
        cout << "3. Set project for a team\n";
        cout << "4. Add members to a team\n";
        cout << "5. Update company information\n";
        cout << "6. Update team information\n";
        cout << "7. Update project information\n";
        cout << "8. Update member information\n";
        cout << "9. Delete team\n";
        cout << "10. Delete member\n";
        cout << "11. Delete a company\n";
        cout << "12. Read from file\n";
        cout << "13. Save all data to file\n";
        cout << "14. Display all companies\n";
        cout << "15. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number between 1 and 15.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            string companyName, headquarters;
            double revenue;
            cout << "Enter company name: ";
            cin >> companyName;
            cout << "Enter headquarters: ";
            cin >> headquarters;
            cout << "Enter total revenue: ";
            cin >> revenue;
            companies.emplace_back(companyName, headquarters, revenue);
            break;
        }
        case 2:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            string teamName;
            cout << "Enter team name: ";
            cin >> teamName;
            auto team = make_shared<Team>(teamName);
            companies[companyIndex].addTeam(team);
            break;
        }
        case 3:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            int projectType;
            cout << "Select project type (1: Development, 2: Research): ";
            cin >> projectType;
            if (projectType == 1)
            {
                string name, deadline, tech;
                double budget;
                cout << "Enter project name: ";
                cin >> name;
                cout << "Enter deadline: ";
                cin >> deadline;
                cout << "Enter budget: ";
                cin >> budget;
                cout << "Enter technology stack: ";
                cin >> tech;
                auto devProject = make_unique<DevelopmentProject>(name, deadline, budget, tech);
                companies[companyIndex].getTeams()[teamIndex]->setProject(move(devProject));
            }
            else if (projectType == 2)
            {
                string name, deadline, topic;
                double budget;
                cout << "Enter project name: ";
                cin >> name;
                cout << "Enter deadline: ";
                cin >> deadline;
                cout << "Enter budget: ";
                cin >> budget;
                cout << "Enter research topic: ";
                cin >> topic;
                auto researchProject = make_unique<ResearchProject>(name, deadline, budget, topic);
                companies[companyIndex].getTeams()[teamIndex]->setProject(move(researchProject));
            }
            else
            {
                cout << "Invalid project type.\n";
            }
            break;
        }
        case 4:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            int empType;
            cout << "Select employee type (1: Full-time, 2: Part-time): ";
            cin >> empType;
            if (empType == 1)
            {
                int id;
                string name, position, department;
                double salary;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter department: ";
                cin >> department;
                cout << "Enter salary: ";
                cin >> salary;
                companies[companyIndex].getTeams()[teamIndex]->addMember(make_shared<fullTime>(id, name, position, department, salary));
            }
            else if (empType == 2)
            {
                int id;
                string name, position, department;
                double salary;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter department: ";
                cin >> department;
                cout << "Enter salary: ";
                cin >> salary;
                companies[companyIndex].getTeams()[teamIndex]->addMember(make_shared<partTime>(id, name, position, department, salary));
            }
            else
            {
                cout << "Invalid employee type.\n";
            }
            break;
        }
        case 5:
        {
            if (companies.empty())
            {
                cout << "No companies available to update.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index to update: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            companies[companyIndex].updateCompanyInfo();
            break;
        }
        case 6:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index to update: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            companies[companyIndex].getTeams()[teamIndex]->updateTeam();
            break;
        }
        case 7:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            auto &project = companies[companyIndex].getTeams()[teamIndex]->getProject();
            if (!project)
            {
                cout << "No project assigned to this team.\n";
                break;
            }
            project->updateProject();
            break;
        }
        case 8:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            auto &members = companies[companyIndex].getTeams()[teamIndex]->getMembers();
            if (members.empty())
            {
                cout << "No members in this team.\n";
                break;
            }
            cout << "Members in team " << companies[companyIndex].getTeams()[teamIndex]->getTeamName() << ":\n";
            for (size_t i = 0; i < members.size(); ++i)
            {
                cout << i << ": " << members[i]->getId() << " - " << members[i]->getName() << endl;
            }
            int memberIndex;
            cout << "Enter member index to update: ";
            cin >> memberIndex;
            if (memberIndex < 0 || memberIndex >= members.size())
            {
                cout << "Invalid member index.\n";
                break;
            }
            members[memberIndex]->updateInfo();
            break;
        }
        case 9:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index to delete: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            string teamName = companies[companyIndex].getTeams()[teamIndex]->getTeamName();
            companies[companyIndex].deleteTeamByName(teamName);
            break;
        }
        case 10:
        {
            if (companies.empty())
            {
                cout << "No companies available.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            cout << "Teams in " << companies[companyIndex].getCompanyName() << ":\n";
            for (size_t i = 0; i < companies[companyIndex].getTeams().size(); ++i)
            {
                cout << i << ": " << companies[companyIndex].getTeams()[i]->getTeamName() << endl;
            }
            int teamIndex;
            cout << "Enter team index: ";
            cin >> teamIndex;
            if (teamIndex < 0 || teamIndex >= companies[companyIndex].getTeams().size())
            {
                cout << "Invalid team index.\n";
                break;
            }
            auto &members = companies[companyIndex].getTeams()[teamIndex]->getMembers();
            if (members.empty())
            {
                cout << "No members in this team.\n";
                break;
            }
            cout << "Members in team " << companies[companyIndex].getTeams()[teamIndex]->getTeamName() << ":\n";
            for (size_t i = 0; i < members.size(); ++i)
            {
                cout << i << ": " << members[i]->getId() << " - " << members[i]->getName() << endl;
            }
            int memberIndex;
            cout << "Enter member index to delete: ";
            cin >> memberIndex;
            if (memberIndex < 0 || memberIndex >= members.size())
            {
                cout << "Invalid member index.\n";
                break;
            }
            int id = members[memberIndex]->getId();
            companies[companyIndex].getTeams()[teamIndex]->deleteMemberById(id);
            break;
        }
        case 11:
        {
            if (companies.empty())
            {
                cout << "No companies available to delete.\n";
                break;
            }
            cout << "Available Companies:\n";
            for (size_t i = 0; i < companies.size(); ++i)
            {
                cout << i << ": " << companies[i].getCompanyName() << endl;
            }
            int companyIndex;
            cout << "Enter company index to delete: ";
            cin >> companyIndex;
            if (companyIndex < 0 || companyIndex >= companies.size())
            {
                cout << "Invalid company index.\n";
                break;
            }
            string companyName = companies[companyIndex].getCompanyName();
            companies.erase(companies.begin() + companyIndex);
            break;
        }
        case 12:
        {
            readFromFile();
            break;
        }
        case 13:
        {
            ofstream outFile("company_data.txt");
            if (outFile.is_open())
            {
                for (const auto &company : companies)
                {
                    company.saveToFile(outFile);
                }
            }
            break;
        }
        case 14:
        {
            for (const auto &company : companies)
            {
                company.displayCompanyInfo();
            }
            break;
        }
        case 15:
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
