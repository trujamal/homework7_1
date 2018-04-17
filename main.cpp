#include <iostream>
#include <vector>
#include <algorithm>

struct time_structure {
    int hourvalue1, hourvalue2, minutevalue1,minutevalue2,start_time, end_time;
};

bool sort_helper(const time_structure &a ,const time_structure &b)
{
    if(a.start_time == b.start_time)return a.end_time > b.end_time;
    return a.start_time < b.start_time;
}

int main() {

    int N; //Number of appointments
    int Day{0}; // Day that is currently at hand
    time_structure time = {};
    std::vector<time_structure> times_vec;
    std::string input_line; // Holds extra information

    while ((std::cin >> N)) {

        if(N == 0)
            break;

        Day++; // Incrementing the amount of days per call
        // Code Goes here
        while (N--) {

            char startSeparator = 0, endSeparator = 0;
            std::cin >> time.hourvalue1 >> startSeparator >> time.minutevalue1 >> time.hourvalue2 >> endSeparator >>
                     time.minutevalue2;
            getline(std::cin, input_line);

            time.start_time = (time.hourvalue1) * 60 + time.minutevalue1; // In accordance to 24 Hour time removed -10
            time.end_time = (time.hourvalue2) * 60 + time.minutevalue2; // In accordance to 24 Hour time removed -10

            times_vec.push_back(time); // Everything being placed into vector
        }
        std::sort(times_vec.begin(), times_vec.end(),sort_helper); // Handles the sorting

        int end_time = 600, result = 0, start_time = 0; // 600 = 18:00

        for (auto i : times_vec) {
            if (abs(end_time - i.start_time) > result)
                result = abs(end_time - i.start_time), start_time = end_time;
            end_time = i.end_time;
        }

        if(abs(18*60 - end_time) > result)
            result = abs(18*60 - end_time), start_time = end_time;
        printf("Day #%d: the longest nap starts at ", Day);
        printf("%02d:%02d and will last for ", start_time/60, start_time%60);

        if(result >= 60)
            printf("%d hours and ", result/60);
        printf("%d minutes.\n", result%60);

        times_vec.clear(); // So that the information can be overwrited
    }
    return 0;
}