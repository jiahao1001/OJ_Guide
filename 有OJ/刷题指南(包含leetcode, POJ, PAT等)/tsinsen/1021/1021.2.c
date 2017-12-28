#include <iostream>
#include <algorithm>
#include <vector>

//采用STL实现

using namespace std;

int main(){

    vector<int> va,vb,vc;
    vector<int>::iterator it;

    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        va.push_back(j);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int j;
        cin>>j;
        vb.push_back(j);
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());

    vc.resize(va.size()+vb.size());

    it=set_intersection(va.begin(),va.end(),vb.begin(),vb.end(),vc.begin());

    vc.resize( it-vc.begin() );  
    for( unsigned i=0; i!=vc.size(); ++i )
        cout << vc[i] << " ";
    cout << endl; 

    vc.resize( va.size() + vb.size() );
    it = set_union( va.begin(), va.end(), vb.begin(), vb.end(), vc.begin() );

    vc.resize( it-vc.begin() );  
    for( unsigned i=0; i!=vc.size(); ++i )
        cout << vc[i] << " ";
    cout << endl; 

    it = set_difference( va.begin(), va.end(), vb.begin(), vb.end(), vc.begin() );
    
    vc.resize( it-vc.begin() );  
    for( unsigned i=0; i!=vc.size(); ++i )
        cout << vc[i] << " ";
    cout << endl; 

}
