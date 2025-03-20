#include <iostream>

struct Time { 
  int hours = 0, minutes = 0, seconds = 0;
};

Time time_add(Time start, Time interval){
  Time timeResult;
  timeResult.seconds = (start.seconds + interval.seconds) % 60;
  timeResult.minutes = (start.minutes + interval.minutes + \
                       (start.seconds + interval.seconds) / 60) % 60;
  timeResult.hours = (start.hours + interval.hours + \
                     (start.minutes + interval.minutes + \
                     (start.seconds + interval.seconds) / 60) / 60) % 24;
  return timeResult; 
}

int main(){
  Time start;
  std::cin >> start.hours >> start.minutes >> start.seconds;
  Time interval;
  std::cin >> interval.hours >> interval.minutes >> interval.seconds;
  Time result = time_add(start, interval);
  std::cout << result.hours << " " << result.minutes << " " << result.seconds;
}
