#include <iostream>
#include <map>
#include <string>
using namespace std;
class Theme
{
public:
    string backgroundColor;
    string fontColor;
    int fontSize;
    string iconStyle;

    Theme(string backgroundColor ="Purple",string fontColor ="Brown", int fontSize = 10, string iconStyle = "Standard")
    {
        this->backgroundColor = backgroundColor;
        this->fontColor = fontColor;
        this->fontSize = fontSize;
        this->iconStyle = iconStyle;
    }

    void previewTheme() const
    {
        cout <<"\n"<<iconStyle << " Theme:\n";
        cout << "Background Color: " << backgroundColor << "\n";
        cout << "Font Color: " << fontColor << "\n";
        cout << "Font Size: " << fontSize << "\n";
        cout << "Icon Style: " << iconStyle << "\n";
    }
};
int main()
{
    Theme t1;
    t1.previewTheme();
    Theme classic ={"White", "Pink", 24, "Classic"};
    Theme sport ={"Red", "Yellow", 17, "Sport"};
    Theme eco ={"Green", "Orange", 19, "Eco"};

    map<string,Theme> themes;
    themes["Classic"] = classic;
    themes["Sport"] = sport;
    themes["Eco"] = eco;

    cout << "\nSelect a theme: \n";
    cout << "1. Classic\n2. Sport\n3. Eco\n";
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch(choice)
    {
    case 1:
        themes["Classic"].previewTheme();
        cout<<"Successfully changed the theme to Classic."<<endl;
        break;
    case 2:
        themes["Sport"].previewTheme();
        cout<<"Successfully changed the theme to Sport."<<endl;
        break;
    case 3:
        themes["Eco"].previewTheme();
        cout<<"Successfully changed the theme to Eco."<<endl;
        break;
    default:
        cout << "Invalid choice. Please select a valid theme (1-3).\n";
    }
}
