#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    vector<MenuItem*> subItems;
    MenuItem* parent;

    MenuItem(string name) : name(name), parent(nullptr) {}

    void addSubItem(MenuItem* item) {
        subItems.push_back(item);
        item->parent = this;
    }

    void display() {
        cout << name << endl;
        for (size_t i = 0; i < subItems.size(); ++i) {
            cout << i + 1 << ". " << subItems[i]->name << endl;
        }
    }
};

class MenuSystem {
private:
    MenuItem* currentMenu;

public:
    MenuSystem(MenuItem* rootMenu) : currentMenu(rootMenu) {}

    void displayMenu() {
        currentMenu->display();
    }

    void navigate(int option) {
        if (option == 0) {
            if (currentMenu->parent != nullptr) {
                currentMenu = currentMenu->parent;
            }
        } else {
            if (option > 0 && option <= currentMenu->subItems.size()) {
                currentMenu = currentMenu->subItems[option - 1];
            }
        }
    }
};

int main() {
    MenuItem* mainMenu = new MenuItem("Main Menu");
    MenuItem* settings = new MenuItem("Settings");
    MenuItem* media = new MenuItem("Media");
    MenuItem* displaySettings = new MenuItem("Display Settings");
    MenuItem* audioSettings = new MenuItem("Audio Settings");
    MenuItem* radio = new MenuItem("Radio");
    MenuItem* bluetoothAudio = new MenuItem("Bluetooth Audio");

    mainMenu->addSubItem(settings);
    mainMenu->addSubItem(media);
    settings->addSubItem(displaySettings);
    settings->addSubItem(audioSettings);
    media->addSubItem(radio);
    media->addSubItem(bluetoothAudio);

    MenuSystem menuSystem(mainMenu);

    int choice;
    do {
        menuSystem.displayMenu();
        cout << "Enter your choice (0 to go back, -1 to exit): ";
        cin >> choice;
        menuSystem.navigate(choice);
    } while (choice != -1);

    return 0;
}

