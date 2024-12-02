#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Control
{
    int id;
    string type;
    string state;
};

int main()
{
    int num;
    vector<Control> c1;

    c1.push_back(Control{1,"Button","Visible"});
    c1.push_back(Control{2,"Slider","Disabled"});
    c1.push_back(Control{3,"Button","Visible"});
    c1.push_back(Control{4,"Slider","Invisible"});
    c1.push_back(Control{5,"Button","Inisible"});
    c1.push_back(Control{6,"Slider","Disabled"});
    c1.push_back(Control{7,"Button","Invisible"});
    c1.push_back(Control{8,"Button","Visible"});
    c1.push_back(Control{9,"Slider","Visible"});
    c1.push_back(Control{10,"Slider","Invisible"});

    cout<<"Given Data: "<<endl;
    for(auto ele: c1)
    {
        cout<<"Id: "<<ele.id<<" "<<"Type: "<<ele.type<<" "<<"State: "<<ele.state<<endl;
    }

    auto findId = find_if(c1.begin(),c1.end(),[](Control &ele){return ele.id ==4;});
    if(findId != c1.end())
    {
        cout<<"\nFound control with specific ID: "<<findId->id<<" Type: "<<findId->type<<" State: "<<findId->state<<endl;
    }
    else
    {
        cout<<"\nCannot find control with ID 4"<<endl;
    }

    auto firstInvisible = find_if(c1.begin(),c1.end(),[](Control &ele){return ele.state == "Invisible";});
    cout<<"\nFirst Invisible control Id: "<<firstInvisible->id<<" Type: "<<firstInvisible->type<<" State: "<<firstInvisible->state<<endl;

    auto adj = adjacent_find(c1.begin(),c1.end(),[](Control &a, Control &b){return a.state == b.state;});
    cout<<"\nFirst consecutive adjacent Id's with same state is: ID-"<<adj->id<<" ID-"<<(adj+1)->id<<endl;

    int count_Visible = count_if(c1.begin(),c1.end(),[](Control &a){return a.state == "Visible";});
    cout<<"\nNumber of Visible Controls: "<<count_Visible<<endl;

    int count_slider_disabled = count_if(c1.begin(),c1.end(),[](Control &b){return b.type=="Slider" && b.state=="Disabled";});
    cout<<"\nCounting sliders that are disabled: "<<count_slider_disabled<<endl;

    bool sub_equal = equal(c1.begin(),c1.end()-6,c1.begin()+5,c1.end(),[](const Control& x, Control& y)
                           {
                               return x.type == y.type && x.state == y.state;
                           });
    cout << "Checking if subranges are equal or not: " << sub_equal << endl;

}
