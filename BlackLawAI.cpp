#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <limits>

namespace BlackLawAI9 {

struct LegalIssue {
    std::string category;
    std::string description;
    std::string jurisdiction;
    std::string status;
};

struct Evidence {
    std::string title;
    std::string description;
    std::string date;
    std::string source;
};

struct CaseEvent {
    std::string date;
    std::string event;
};

struct CaseFile {
    std::string caseName;
    std::string jurisdiction;
    std::string caseNumber;
    std::vector<LegalIssue> issues;
    std::vector<Evidence> evidence;
    std::vector<CaseEvent> timeline;
};

class BlackLawAI9Engine {
private:
    std::string identity = "BlackLawAI9";
    std::string version = "9.0";
    std::string jurisdiction = "Michigan / United States";
    std::vector<CaseFile> cases;

    void line() const {
        std::cout << "\n----------------------------------------\n";
    }

public:

    void initialize() const {
        line();
        std::cout << " BLACKLAWAI9 LEGAL INTELLIGENCE ENGINE\n";
        std::cout << " Version: " << version << "\n";
        std::cout << " Jurisdiction: " << jurisdiction << "\n";
        std::cout << " Status: ONLINE\n";
        std::cout << "----------------------------------------\n";

        std::cout << "\nBlackLawAI9: ";
        std::cout << "Knowledge. Analysis. Accountability.\n";
        std::cout << "How may I assist you today?\n";
    }

    void introduce() const {
        std::cout
            << "\nI am BlackLawAI9, an independent "
            << "legal information and case-analysis engine.\n"
            << "My purpose is to organize information, "
            << "identify legal questions, and support "
            << "informed decision-making.\n";
    }

    void setJurisdiction() {
        std::cout << "\nEnter jurisdiction: ";
        std::getline(std::cin, jurisdiction);

        std::cout << "Jurisdiction updated to: "
                  << jurisdiction << "\n";
    }

    void createCase() {
        CaseFile file;

        std::cout << "\nCASE NAME: ";
        std::getline(std::cin, file.caseName);

        std::cout << "CASE NUMBER: ";
        std::getline(std::cin, file.caseNumber);

        std::cout << "JURISDICTION: ";
        std::getline(std::cin, file.jurisdiction);

        cases.push_back(file);

        std::cout << "\nCase created successfully.\n";
    }

    void addIssue() {
        if (cases.empty()) {
            std::cout << "Create a case first.\n";
            return;
        }

        LegalIssue issue;

        std::cout << "\nLEGAL ISSUE CATEGORY: ";
        std::getline(std::cin, issue.category);

        std::cout << "DESCRIPTION: ";
        std::getline(std::cin, issue.description);

        std::cout << "JURISDICTION: ";
        std::getline(std::cin, issue.jurisdiction);

        issue.status = "Under Review";

        cases.back().issues.push_back(issue);

        std::cout << "Legal issue added.\n";
    }

    void addEvidence() {
        if (cases.empty()) {
            std::cout << "Create a case first.\n";
            return;
        }

        Evidence item;

        std::cout << "\nEVIDENCE TITLE: ";
        std::getline(std::cin, item.title);

        std::cout << "DESCRIPTION: ";
        std::getline(std::cin, item.description);

        std::cout << "DATE: ";
        std::getline(std::cin, item.date);

        std::cout << "SOURCE: ";
        std::getline(std::cin, item.source);

        cases.back().evidence.push_back(item);

        std::cout << "Evidence recorded.\n";
    }

    void addTimelineEvent() {
        if (cases.empty()) {
            std::cout << "Create a case first.\n";
            return;
        }

        CaseEvent event;

        std::cout << "\nEVENT DATE: ";
        std::getline(std::cin, event.date);

        std::cout << "EVENT DESCRIPTION: ";
        std::getline(std::cin, event.event);

        cases.back().timeline.push_back(event);

        std::cout << "Timeline event recorded.\n";
    }

    void analyzeCase() const {
        if (cases.empty()) {
            std::cout << "No cases available.\n";
            return;
        }

        const CaseFile& file = cases.back();

        line();

        std::cout << "BLACKLAWAI9 CASE ANALYSIS\n";
        std::cout << "Case: " << file.caseName << "\n";
        std::cout << "Number: " << file.caseNumber << "\n";
        std::cout << "Jurisdiction: "
                  << file.jurisdiction << "\n";

        std::cout << "\nLEGAL ISSUES: "
                  << file.issues.size() << "\n";

        for (const auto& issue : file.issues) {
            std::cout << "\n- " << issue.category
                      << "\n  " << issue.description
                      << "\n  Status: " << issue.status
                      << "\n";
        }

        std::cout << "\nEVIDENCE ITEMS: "
                  << file.evidence.size() << "\n";

        for (const auto& item : file.evidence) {
            std::cout << "- " << item.title
                      << " | " << item.date << "\n";
        }

        std::cout << "\nTIMELINE EVENTS: "
                  << file.timeline.size() << "\n";

        for (const auto& event : file.timeline) {
            std::cout << "- " << event.date
                      << ": " << event.event << "\n";
        }

        line();

        std::cout
            << "ANALYSIS STATUS: ORGANIZED\n"
            << "LEGAL CONCLUSIONS: NOT ESTABLISHED\n"
            << "ATTORNEY REVIEW: RECOMMENDED\n";
    }

    void legalFramework() const {
        line();

        std::cout << "LEGAL RESEARCH FRAMEWORK\n";

        std::cout
            << "1. Identify the legal question.\n"
            << "2. Identify the applicable jurisdiction.\n"
            << "3. Locate relevant statutes.\n"
            << "4. Locate relevant court decisions.\n"
            << "5. Compare facts against legal elements.\n"
            << "6. Identify supporting evidence.\n"
            << "7. Identify contrary evidence.\n"
            << "8. Record uncertainties and missing facts.\n"
            << "9. Prepare findings for human review.\n";

        line();
    }

    void assistant() const {
        std::string question;

        std::cout << "\nYOU: ";
        std::getline(std::cin, question);

        std::cout << "\nBLACKLAWAI9: ";

        if (question.empty()) {
            std::cout << "Please enter a question.\n";
            return;
        }

        std::string lower = question;

        std::transform(
            lower.begin(),
            lower.end(),
            lower.begin(),
            [](unsigned char c) {
                return static_cast<char>(std::tolower(c));
            }
        );

        if (lower.find("rights") != std::string::npos) {
            std::cout
                << "Let's identify the applicable rights, "
                << "jurisdiction, relevant facts, and "
                << "potential legal protections.\n";
        }
        else if (lower.find("evidence") != std::string::npos) {
            std::cout
                << "Evidence should be documented with "
                << "its source, date, authenticity, and "
                << "relationship to the legal issue.\n";
        }
        else if (lower.find("case") != std::string::npos) {
            std::cout
                << "We can organize the case into facts, "
                << "issues, applicable law, evidence, "
                << "and possible arguments.\n";
        }
        else {
            std::cout
                << "Your question has been received. "
                << "A full legal assessment requires "
                << "applicable legal sources and facts.\n";
        }

        std::cout
            << "This is legal information, not a "
            << "verified legal opinion.\n";
    }

    void showMenu() const {
        line();

        std::cout
            << "1. Introduce BlackLawAI9\n"
            << "2. Change jurisdiction\n"
            << "3. Create case file\n"
            << "4. Add legal issue\n"
            << "5. Add evidence\n"
            << "6. Add timeline event\n"
            << "7. Analyze latest case\n"
            << "8. Legal research framework\n"
            << "9. Ask BlackLawAI9\n"
            << "0. Exit\n";

        line();
    }

    void run() {
        initialize();

        bool running = true;

        while (running) {
            showMenu();

            std::cout << "SELECT: ";

            std::string choice;
            std::getline(std::cin, choice);

            if (choice == "1") introduce();
            else if (choice == "2") setJurisdiction();
            else if (choice == "3") createCase();
            else if (choice == "4") addIssue();
            else if (choice == "5") addEvidence();
            else if (choice == "6") addTimelineEvent();
            else if (choice == "7") analyzeCase();
            else if (choice == "8") legalFramework();
            else if (choice == "9") assistant();
            else if (choice == "0") {
                std::cout
                    << "\nBlackLawAI9 shutting down.\n";
                running = false;
            }
            else {
                std::cout << "Invalid selection.\n";
            }
        }
    }
};

} // namespace BlackLawAI9

int main() {
    BlackLawAI9::BlackLawAI9Engine engine;
    engine.run();

    return 0;
}
