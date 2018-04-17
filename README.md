# homework7_1
<p align="center">
<img src= https://media.giphy.com/media/WWdJ4bEzFomUE/giphy.gif>
</p>
Notes for Longest Nap: 

 

Just to get you all heading in the right direction here is the very general outline of the code 

// longest_nap.cpp 
// Created by Greg LaKomski on 4/12/18. 
// 
 
 
#include<iostream> 
#include<cmath> 
#include<stdio.h> 
#include<string> 
#include<set> 
#include<iterator> 
using std::cout; 
using std::endl; 

 

... any functions or structs 

 

int main() { 

.... potentially stuff 

int N; 

int Day{0}; 

std::string trash; 

 

while(std::cin >> N) { 

Day++; 

..... 

 

while (N--){ 
 

int startHr, startMin, endHr, endMin; 
int startTime, endTime; 
char startSeparator, endSeparator; 
 
std::cin >> startHr >> startSeparator >> startMin >> endHr >> endSeparator >> endMin; 
getline(std::cin, trash); 

 

startTime = (startHr - 10) * 60 + startMin; 
endTime = (endHr - 10) * 60 + endMin; 

................ code for however you are storing the appts -------- 

} 

.......... 

......... 

OK - got your best nap time for a given day - sorry about the wrapping :( 

if (nap >= 60){ 
  printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n",Day, startNap / 60 + 10, startNap % 60, nap / 60, nap % 60);} 
else 
  printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", Day, startNap / 60 + 10, startNap % 60, nap); 

} 

Some things to note: 

 

There is no guarantee that the appts will be in time order 

You have to make sure to check at both ends too 

You must deal with duplicates and if there are two best naps with the same length, pick the earliest!  I didn't pass on first submission because of this. 

 

 

Coding: 

 

There are many ways of doing this problem but in the end you have to sort.  I used two multimaps since multimaps are ok with duplicate entries and created custom sorting functors to sort them.   If you google "sorting set by custom function" you will see how to do this.  I also created a printing function for each multimap so I could print it in order and see what it looked like.  Little tricky since I was storing structs for the appts and the times between the appts.  Ooops  I just gave my solution totally away.   

 

I think my solution is O(log N) 

 

Greg 
