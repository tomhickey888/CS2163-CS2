#include <iostream>
#include <iomanip>
#include "common.h"

using namespace std;

//Displays completed array
int displayData(student studentData[], int H)
{
	int acc=0;

    for(int i=0; i < H; i++)
    {
        cout << "Student #" << studentData[i].ID << " is a ";

        // Determines classification and eligibility of each student
        if(studentData[i].hours < 30)
            cout << "freshman with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << "." << setw(21) << "Not eligible.";

        else if(studentData[i].hours < 60)
        {
            cout << "sophomore with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << ".";

            if(studentData[i].GPA >= 3.75)
            {
                cout << setw(20) << "Eligible.";
                acc++;
		    }

		    else
		        cout << setw(20) << "Not eligible.";
	    }

        else if(studentData[i].hours < 90)
        {
            cout << "junior with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << ".";

            if(studentData[i].GPA >= 3.5)
		    {
			    cout << setw(23) << "Eligible.";
		        acc++;
		    }

		    else
		        cout << setw(23) << "Not eligible.";
	    }

        else
        {
            cout << "senior with a GPA of " << showpoint << setprecision(3) << studentData[i].GPA << ".";

            if(studentData[i].GPA >= 3.25)
	        {
			    cout << setw(23) << "Eligible.";
		        acc++;
		    }

		    else
		        cout << setw(23) << "Not eligible.";
	    }

        cout << endl;
      }

    return acc;
}
