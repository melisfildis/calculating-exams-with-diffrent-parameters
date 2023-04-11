#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Exam {
public:
	string name;
	double tot_score;
	int day,month,year;
};
class TOEFL :public Exam {
public:
	int correct_reading;
	int correct_listening;
	int correct_writing;
	int correct_speaking;
	

};
class IELTS :public Exam {
public:
	int correct_reading;
	int correct_listening;
	int correct_writing;
	int correct_speaking;
	double find_band_score(int mark_range) {
		double band_score;

		if (mark_range == 40)
			band_score = 9.0;
		else if (mark_range == 39)
			band_score = 8.5;
		else if (mark_range == 38)
			band_score = 8.0;
		else if ((mark_range == 37) || (mark_range == 36))
			band_score = 7.5;
		else if ((mark_range == 35) || (mark_range == 34))
			band_score = 7.0;
		else if ((mark_range == 33) || (mark_range == 32))
			band_score = 6.5;
		else if ((mark_range == 31) || (mark_range == 30))
			band_score = 6.0;
		else if ((mark_range <= 29) && (mark_range >= 26))
			band_score = 5.5;
		else if ((mark_range <= 25) && (mark_range >= 23))
			band_score = 5.0;
		else if ((mark_range <= 22) && (mark_range >= 19))
			band_score = 4.5;
		else if ((mark_range <= 18) && (mark_range >= 15))
			band_score = 4.0;
		else if ((mark_range <= 14) && (mark_range >= 12))
			band_score = 3.5;
		else if ((mark_range <= 11) && (mark_range >= 8))
			band_score = 3.0;
		else if ((mark_range <= 7) && (mark_range >= 5))
			band_score = 2.5;
		else if ((mark_range <= 4) && (mark_range >= 2))
			band_score = 2.0;
		else if (mark_range == 1)
			band_score = 1.0;
		else
			band_score = 0.0;

		return band_score;
	}


};

class Yokdil :public Exam {
public:
	int correct_ans;
	double score;
	
};
int main() {
	string name, option;
	char choice;
	int day, month, year,fin=0;
	Yokdil yokdil;
	TOEFL toefl;
	IELTS ielts;
	
	while (fin == 0) {
		cout << "Enter the name of student: ";
		cin >> name;
		cout << "Enter the date of exam: ";
		cin >> day >> month >> year;
		cout << "Enter T for TOEFL, I for IELTS or Y for Yokdil: ";
		cin >> option;

		if ((option == "T") || (option == "t")) {
			//total question=120
			cout << "Enter score for Reading: "  << endl;
			cin >> toefl.correct_reading;

			cout << "Enter score for Writing: "  << endl;
			cin >> toefl.correct_writing;

			cout << "Enter score for Listening: " << endl;
			cin >> toefl.correct_listening;

			cout << "Enter score for Speaking: "  << endl;
			cin >> toefl.correct_speaking;

			cout << "Name : " << name << " Exam : TOEFL " << "Date of exam : " << day << "/" << month << "/" << year << endl;
			cout << "Reading : " << toefl.correct_reading << " Writing : " << toefl.correct_writing << " Listening : " << toefl.correct_listening << " Speaking : " << toefl.correct_speaking << endl;
	
			toefl.tot_score = toefl.correct_listening + toefl.correct_writing + toefl.correct_reading + toefl.correct_speaking;
			cout << "Total Score:" << toefl.tot_score << endl;

		}
		else if ((option == "I") || (option == "i")) {
			//total question=160
			cout << "Enter score for Reading: " << endl;
			cin >> ielts.correct_reading;

			cout << "Enter score for Writing: " << endl;
			cin >> ielts.correct_writing;

			cout << "Enter score for Listening: " << endl;
			cin >> ielts.correct_listening;

			cout << "Enter score for Speaking: " << endl;
			cin >> ielts.correct_speaking;

			double cr, cl, cw, cs;
			double average;
			cr = ielts.find_band_score(ielts.correct_reading);
			cl = ielts.find_band_score(ielts.correct_listening);
			cw = ielts.find_band_score(ielts.correct_writing);
			cs = ielts.find_band_score(ielts.correct_speaking);
			average = (cr + cl + cw + cs) / 4;
			ielts.tot_score = round(average * 2) / 2;
		
			cout << "Name : " << name << " Exam : IELTS " << "Date of exam : " << day << "/" << month << "/" << year << endl;
			cout << "Reading : " << cr << " Writing : " << cw << " Listening : " << cl << " Speaking : " << cs << endl;
			cout << "Total Score:" << ielts.tot_score << endl;

		}
		else if ((option == "Y") || (option == "y")) {
			//total question=80
			cout << "Enter number of correct answers: " << endl;
			cin >> yokdil.correct_ans;

			cout << "Name : " << name << " Exam : YOKDIL " << "Date of exam : " << day << "/" << month << "/" << year << endl;
			
			yokdil.score = yokdil.correct_ans * 1.25;
			cout << "Total Score:" << yokdil.score << endl;

		}
		else { cout << "Wrong Option!"; }

		cout << "Do you want to continue? Y/N" << endl;
		cin >> choice;
			if((choice == 'N') || (choice == 'n')) { fin++; }
			
	}
}