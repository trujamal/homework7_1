#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stack>
#include <iomanip>
#include<cmath>
#include<set>
#include<iterator>

struct time_structure {
    int hourvalue1, hourvalue2, minutevalue1,minutevalue2;
};

bool sort_helper(time_structure one, time_structure two) {
    // Handles the initial comparison
    if(one.hourvalue1 < two.minutevalue1)
        return true;
    else if(one.hourvalue1 > two.minutevalue1)
        return false;

    // Handling the minute conversions
    if(one.minutevalue1 < two.hourvalue1)
        return true;
    else if(one.minutevalue1 > two.minutevalue1)
        return false;

    // Handling the second hour conversions
    if(one.hourvalue2 < two.hourvalue2)
        return true;
    else if(one.hourvalue2 > two.hourvalue2)
        return false;

    // Handling the minute conversions
    if(one.minutevalue2 < two.minutevalue2)
        return true;
    else if(one.minutevalue2 > two.minutevalue2)
        return false;
}


void display_output(int value, int Day, int hours, int minutes) {
    if (value >= 60) {
        printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", Day,
               hours / 60 + 10, hours % 60, minutes / 60, minutes % 60);
    } else {
        printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", Day,
               hours / 60 + 10, hours % 60, minutes);
    }
}

int main() {

    int N; //Number of appointments
    int Day{0}; // Day that is currently at hand
    std::vector<time_structure> times_vec;
    std::string input_line; // Holds extra information

    while (std::cin >> N) {
        Day++; // Incrementing the amount of days per call
        // Code Goes here
        time_structure time;

        while (N--) {

            char startSeparator, endSeparator;
            std::cin >> time.hourvalue1 >> startSeparator >> time.minutevalue1 >> time.hourvalue2 >> endSeparator >>
                     time.minutevalue2;
            getline(std::cin, input_line);

//            time.start_time = (time.hourvalue1 - 10) * 60 + time.minutevalue1;
//            time.end_time = (time.hourvalue2 - 10) * 60 + time.minutevalue2;

            times_vec.push_back(time); // Everything being placed into vector

        }
        sort(times_vec.begin(), times_vec.end(),sort_helper); // Handles the sorting

        int max_sleep = -1, max_hour_value, max_minute_value;

        if (times_vec[0].hourvalue1 != 10 || times_vec[0].minutevalue1 != 0)
        {
            max_sleep = times_vec[0].hourvalue1*60 + times_vec[0].minutevalue1 - 10*60;
            max_hour_value = 10;
            max_minute_value = 0;

        }

        for (int i = 0; i < times_vec.size(); ++i) {
            if ((times_vec[i-1].hourvalue2 != times_vec[i].hourvalue1 || times_vec[i-1].minutevalue2 != times_vec[i].minutevalue1) &&
                max_sleep < times_vec[i].hourvalue1*60 + times_vec[i].minutevalue1 - times_vec[i-1].hourvalue2*60 - times_vec[i-1].minutevalue2)
            {
                max_sleep = times_vec[i].hourvalue1*60 + times_vec[i].minutevalue1 - times_vec[i-1].hourvalue2*60 - times_vec[i-1].minutevalue2;
                max_hour_value = times_vec[i-1].hourvalue2;
                max_minute_value = times_vec[i-1].minutevalue2;
            }

        }

        if (times_vec.back().hourvalue2 != 18 && max_sleep < 18*60 - times_vec.back().hourvalue2*60 - times_vec.back().minutevalue2)
        {
            max_sleep = 18*60 - times_vec.back().hourvalue2*60 - times_vec.back().minutevalue2;
            max_hour_value = times_vec.back().hourvalue2;
            max_minute_value = times_vec.back().minutevalue2;

        }

        display_output(max_sleep,Day,max_hour_value,max_minute_value);

        times_vec.clear(); // So that the information can be overwrited
    }

    return 0;
}

