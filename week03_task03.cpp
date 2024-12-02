#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Event
{
public:
    string eventType;
    int x, y;
    time_t timestamp;

    Event(const string& type, int posX, int posY)
        : eventType(type), x(posX), y(posY) {
        timestamp = time(nullptr);
    }
};
queue<Event> eventQueue;

void handleEvent(const Event& event)
{
    if (event.eventType == "Tap")
    {
        cout << "Tap event at (" << event.x << ", " << event.y << ")" << endl;
    }
    else if (event.eventType == "Swipe")
    {

        string direction;
        if (abs(event.x) > abs(event.y))
        {
            direction = event.x > 0 ? "Right" : "Left";
        } else
        {
            direction = event.y > 0 ? "Down" : "Up";
        }
        cout << "Swipe event towards " << direction << endl;
    }
}

void processEvents()
{
    while (!eventQueue.empty())
    {
        Event event = eventQueue.front();
        eventQueue.pop();
        handleEvent(event);
    }
}
void generateRandomEvents(int numEvents)
{
    for (int i = 0; i < numEvents; ++i)
    {
        int type = rand() % 2;
        int x = rand() % 100 - 50;
        int y = rand() % 100 - 50;

        string eventType = (type == 0) ? "Tap" : "Swipe";
        eventQueue.push(Event(eventType, x, y));
    }
}

int main()
{
    srand(time(0));
    generateRandomEvents(10);
    processEvents();
    return 0;
}
