#include <iostream>
#include <thread>
#include <chrono>
#include <random>
using namespace std;
class VehicleData
{
private:
    int speed;
    int fuelLevel;
    int engineTemperature;

public:
    VehicleData(): speed(0), fuelLevel(100), engineTemperature(75) {}
    void updateData()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> speedDist(30, 120);
        uniform_int_distribution<> fuelDist(0, 100);
        uniform_int_distribution<> tempDist(60, 150);
        speed = speedDist(gen);
        fuelLevel = fuelDist(gen);
        engineTemperature = tempDist(gen);
    }

    int getSpeed(){ return speed; }
    int getFuelLevel(){ return fuelLevel; }
    int getEngTemp(){ return engineTemperature; }
};
class Display
{
private:
    VehicleData &vehicleData;

public:
    Display(VehicleData &data) : vehicleData(data) {}
    void showData()
    {
        while (true)
        {
            cout << "Speed: "<<vehicleData.getSpeed()<< " km/h "<< "Fuel: "
                 <<vehicleData.getFuelLevel()<<"% "<< "Temperature: "<< vehicleData.getEngTemp()
                 <<"°C "<<endl;
                if (vehicleData.getEngTemp() > 100)
            {
                cout << " [Warning: Overheating the Engine!] "<<endl;
            }
            if (vehicleData.getFuelLevel() < 10)
            {
                cout << " [Warning: Low Fuel!] "<<endl;
            }
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};
int main() {
    VehicleData vehicleData;
    Display display(vehicleData);

    thread updateThread([&vehicleData]() {
        while (true) {
            vehicleData.updateData();
            this_thread::sleep_for(chrono::seconds(1));
        }
    });
    thread displayThread([&display]() {display.showData();});

    updateThread.join();
    displayThread.join();
}
