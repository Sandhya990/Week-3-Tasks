#include <iostream>
#include <map>
#include <string>
using namespace std;

class Theme
{
public:
    string backgroundColour;
    string fontColour;
    int fontSize;
    string iconStyle;

    Theme() :backgroundColour("Indigo"), fontColour("maroon"), fontSize(3344), iconStyle("Friendly") {};

    Theme(const string& bg, const string& font, int size, const string& style) : backgroundColour(bg), fontColour(font), fontSize(size), iconStyle(style) {}

    void applyTheme() const
    {
        cout << "  Theme applying started!!!" << endl;
        cout << "  Background colour is : " << backgroundColour << endl;
        cout << "  Font colour is : " << fontColour << endl;
        cout << "  Font size is : " << fontSize << endl;
        cout << "  Icon style is : " << iconStyle << endl;
    }

    void displayTheme() const
    {
        cout << "  Theme overview is : " << endl;
        cout << "  Background colour is : " << backgroundColour << " , " << "Font colour is : " << fontColour << " , " << "Font size is : " << fontSize << " , " << "Icon style is : " << iconStyle << endl;
    }

};

void display(const map<int, Theme>& themes)
{
    cout << "  Available themes are : " << endl;
    for (const auto& t : themes)
    {
        cout << "  " << t.first << ". " << t.second.iconStyle << " Theme" << endl;
    }
}

int main()
{
    map<int, Theme> th;
    th[1] = Theme("  Navy Blue", "Olive Green", 18, "Royal");
    th[2] = Theme("  Aqua", "Magenta", 7, "Classic");
    th[3] = Theme("  Red Wine", "Beige", 17, "Eco");
    th[4] = Theme("  Ruby Pink", "Lavender", 20, "Sport");

    int choice;

    while (true)
    {
        display(th);

        cout << "  Enter the number to apply the theme (0 to exit): ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "  You choose to exit this themes program!!!" << endl;
            break;
        }
        else if (th.find(choice) != th.end())
        {
            th[choice].applyTheme();
            th[choice].displayTheme();
        }
        else
        {
            cout << "  Please enter from the valid theme number only!!!" << endl;
        }
    }

    return 0;
}


