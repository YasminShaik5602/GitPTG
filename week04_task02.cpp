#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer","Nanometer","Temperaturemeter"};
    set<string> staticWidgets = {"Logo","WarningLights"};

    cout<<"***Dyanamic Widgets: ***"<<endl;
    for(auto it=dynamicWidgets.begin();it!=dynamicWidgets.end();it++)
    {
        cout<<*it<<endl;
    }

    auto found_staticwid = staticWidgets.find("WarningLights");
    if(found_staticwid != staticWidgets.end())
    {
        cout<<"\n"<<*found_staticwid<<" is found in Static Widgets."<<endl;
    }
    else
    {
        cout<<"\nWarning Lights is not found in Static Widgets."<<endl;
    }

    vector<string> combinedWidget(dynamicWidgets.size() + staticWidgets.size());
    copy(dynamicWidgets.begin(), dynamicWidgets.end(), combinedWidget.begin());
    copy(staticWidgets.begin(), staticWidgets.end(), combinedWidget.begin() + dynamicWidgets.size());

    cout<<"\n***Combined Widgets: ***"<<endl;
    for(auto ele: combinedWidget)
    {
        cout<<ele<<endl;
    }

    auto found_combwid = find(combinedWidget.begin(), combinedWidget.end(), "Logo");
    if(found_combwid != combinedWidget.end())
    {
        cout<<"\n"<<*found_combwid<<" is found in Combined Widgets list."<<endl;
    }
    else
    {
        cout<<"\nLogo is not found in Combined Widgets list."<<endl;
    }
    return 0;
}
