#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// Class representing a menu item
class MenuItem {
public:
    string name;
    vector<shared_ptr<MenuItem>> subMenu;

    // Constructor
    MenuItem(const string& name) : name(name) {}

    // Add sub-menu item
    void addSubItem(const shared_ptr<MenuItem>& item) {
        subMenu.push_back(item);
    }
};

// Class representing the menu system
class MenuSystem {
private:
    shared_ptr<MenuItem> root;               // The root menu
    shared_ptr<MenuItem> currentMenu;        // The current menu that is being displayed
    vector<shared_ptr<MenuItem>> menuPath;   // Keeps track of the menu path for back navigation

    // Display the current menu and its submenus
    void displayMenu() {
        cout << "\n-- " << currentMenu->name << " --\n";
        for (size_t i = 0; i < currentMenu->subMenu.size(); ++i) {
            cout << i + 1 << ". " << currentMenu->subMenu[i]->name << "\n";
        }
        cout << "0. Back\n";
    }

    // Navigate up to the previous menu
    void navigateUp() {
        if (!menuPath.empty()) {
            currentMenu = menuPath.back();
            menuPath.pop_back();
        }
        else {
            cout << "Already at the top level.\n";
        }
    }

    // Navigate down to a submenu
    void navigateDown(int index) {
        if (index > 0 && index <= static_cast<int>(currentMenu->subMenu.size())) {
            menuPath.push_back(currentMenu);
            currentMenu = currentMenu->subMenu[index - 1];
        }
        else {
            cout << "Invalid selection. Try again.\n";
        }
    }

public:
    MenuSystem(const shared_ptr<MenuItem>& rootMenu) : root(rootMenu), currentMenu(rootMenu) {}

    void run() {
        while (true) {
            displayMenu();
            cout << "\nEnter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                navigateUp();
            }
            else {
                navigateDown(choice);
            }

            if (currentMenu == root && menuPath.empty()) {
                cout << "Exited the menu system.\n";
                break;
            }
        }
    }
};

int main() {
    // Building the menu structure
    auto mainMenu = make_shared<MenuItem>("Main Menu");
    auto settings = make_shared<MenuItem>("Settings");
    auto media = make_shared<MenuItem>("Media");

    auto displaySettings = make_shared<MenuItem>("Display Settings");
    auto audioSettings = make_shared<MenuItem>("Audio Settings");
    // auto networkSettings = make_shared<MenuItem>("Network Settings");
    // auto soundSettings = make_shared<MenuItem>("Sound Settings");
    // auto privacySettings = make_shared<MenuItem>("Privacy Settings");

    auto radio = make_shared<MenuItem>("Radio");
    auto bluetoothAudio = make_shared<MenuItem>("Bluetooth Audio");
    // auto videoPlayer = make_shared<MenuItem>("Video Player");
    // auto podcast = make_shared<MenuItem>("Podcast");
    // auto musicPlayer = make_shared<MenuItem>("Music Player");

    // Adding submenus under Settings
    settings->addSubItem(displaySettings);
    settings->addSubItem(audioSettings);
    // settings->addSubItem(networkSettings);
    // settings->addSubItem(soundSettings);
    // settings->addSubItem(privacySettings);

    // Adding submenus under Media
    media->addSubItem(radio);
    media->addSubItem(bluetoothAudio);
    // media->addSubItem(videoPlayer);
    // media->addSubItem(podcast);
    // media->addSubItem(musicPlayer);

    // Adding the main menu options
    mainMenu->addSubItem(settings);
    mainMenu->addSubItem(media);

    // Creating the menu system and running it
    MenuSystem menuSystem(mainMenu);
    menuSystem.run();

    return 0;
}