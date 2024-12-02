#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> controlStates = {"Visible","Invisible","Enabled","Disable","Visible","Enabled"};
    vector<string> backupStates(controlStates.size());

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,6);

    generate(backupStates.begin(), backupStates.end(), [&]() {
        return controlStates[distrib(gen)];});
    cout<<"Generate random states: "<<endl;
    for (auto ele: backupStates)
    {
        cout<<ele<<" ";
    }

    copy(controlStates.begin(),controlStates.end(),backupStates.begin());
    cout<<"\n\nBackup Control states using Copy: "<<endl;
    for(auto ele: backupStates)
    {
        cout<<ele<<" ";
    }

    fill(backupStates.begin(),backupStates.end(),"Disable");
    cout<<"\n\nFilling all Control states with Disable: "<<endl;
    for(auto ele: backupStates)
    {
        cout<<ele<<" ";
    }

    transform(controlStates.begin(),controlStates.end(),controlStates.begin(),[](const string &state){
        return state =="Visible" ?"Invisible":state;});
    cout<<"\n\nUsing transform change Visible to Invisible: "<<endl;
    for(auto ele: controlStates)
    {
        cout<<ele<<" ";
    }

    replace(controlStates.begin(),controlStates.end(),"Disable","Enabled");
    cout<<"\n\nReplacing Disabled to Enabled: "<<endl;
    for (auto ele: controlStates)
    {
        cout<<ele<<" ";
    }

    controlStates.erase(remove_if(controlStates.begin(),controlStates.end(),[](string s1){
                            return s1=="Invisible";
                        }),controlStates.end());
    cout<<"\n\nUsing remove_if, removing Invisible from list: "<<endl;
    for (auto ele: controlStates)
    {
        cout<<ele<<" ";
    }

    controlStates.push_back("Invisible");
    controlStates.push_back("Disable");
    controlStates.push_back("Invisible");
    cout<<"\n\nAfter appending some states, Control states: "<<endl;
    for (auto ele: controlStates)
    {
        cout<<ele<<" ";
    }

    reverse(controlStates.begin(),controlStates.end());
    cout<<"\n\nReverse the Control states: "<<endl;
    for (auto ele: controlStates)
    {
        cout<<ele<<" ";
    }

    partition(controlStates.begin(),controlStates.end(),[](string s){
        return s=="Invisible";
    });
    cout<<"\n\nPartition the grouped Invisible states: "<<endl;
    for (auto ele: controlStates)
    {
        cout<<ele<<" ";
    }
    return 0;
}
