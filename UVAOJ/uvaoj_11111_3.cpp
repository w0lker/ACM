#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<cstdio>
using namespace std;

struct Type
{
    Type(const int &a,const int &b):size_(a),capacity_(b) {}
    int size_,capacity_;
};

int main3()
{
    /*
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    //*/

    string line;
    while(getline(cin,line))
    {
        istringstream sin(line);
        stack<Type> s;
        bool success(true);
        int t;
        while(sin>>t)
        {
            if(t<0)
            {
                if(s.empty())
                    s.push(Type(t,t));
                else
                {
                    if(s.top().capacity_<t)
                        s.push(Type(t,t));
                    else
                    {
                        success=false;
                        break;
                    }
                }
            }
            else
            {
                if(s.empty())
                {
                    success=false;
                    break;
                }
                else
                {
                    if(s.top().size_+t!=0)
                    {
                        success=false;
                        break;
                    }
                    else
                    {
                        s.pop();
                        if(!s.empty())
                            s.top().capacity_+=t;
                    }
                }
            }
            /*
            stack<Type> st(s);
            while(!st.empty())
            {
                cout<<st.top().size_<<" "<<st.top().capacity_<<endl;
                st.pop();
            }
            cout<<endl;
            //*/
        }

        if(success && s.empty())
            cout<<":-) Matrioshka!"<<endl;
        else
            cout<<":-( Try again."<<endl;
    }

    return 0;
}