#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Control
{
    int id;
    string name;
};

bool operator <(const Control& a,const Control& b)
{
    return a.id < b.id;
}

int main()
{
    vector<Control> v1 = {{2,"Control_B"},{4,"Control_D"},{2,"Control_C"},{6,"Control_F"}};
    vector<Control> v2 = {{1,"Control_A"},{3,"Control_W"},{4,"Control_D"},{5,"Control_E"}};
    vector<Control> mergedVector;

    sort(v1.begin(),v1.end());
    cout<<"Sorted Vector 1: "<<endl;
    for (auto ele: v1)
    {
        cout<<ele.id<<" "<<ele.name<<endl;
    }

    stable_sort(v1.begin(),v1.end());
    cout<<"\n\nStable sort Vector 1: "<<endl;
    for (auto ele: v1)
    {
        cout<<ele.id<<" "<<ele.name<<endl;
    }

    Control target{4,"Control_G"};
    auto lower = lower_bound(v1.begin(),v1.end(),Control{target});
    if(lower != v1.end())
    {
        cout<<"\n\nLower bound of 4: "<<lower->id<<" "<<lower->name<<endl;
    }
    else
    {
        cout<<"\n\nLower bound is not found"<<endl;
    }

    auto upper = upper_bound(v1.begin(),v1.end(),Control{target});
    if(upper != v1.end())
    {
        cout<<"\nUpper bound of 4: "<<upper->id<<" "<<upper->name<<endl;
    }
    else
    {
        cout<<"\nUpper bound is not found"<<endl;
    }

    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(mergedVector));
    cout<<"\nMerged vector: "<<endl;
    for(auto item: mergedVector)
    {
        cout<<item.id<<" "<<item.name<<endl;
    }

    inplace_merge(mergedVector.begin(),mergedVector.begin()+3,mergedVector.end());
    cout<<"\nInplace merged vector: "<<endl;
    for(auto item: mergedVector)
    {
        cout<<item.id<<" "<<item.name<<endl;
    }

    vector<Control> result;
    set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(result));
    cout<<"\nSet Union: "<<endl;
    for(auto item: result)
    {
        cout<<item.id<<" "<<item.name<<endl;
    }

    vector<Control> result1;
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(result1));
    cout<<"\nSet Intersection: "<<endl;
    for(auto item: result1)
    {
        cout<<item.id<<" "<<item.name<<endl;
    }

    return 0;
}
