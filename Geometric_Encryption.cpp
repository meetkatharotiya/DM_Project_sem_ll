        
#include <bits/stdc++.h>
using namespace std;

struct point
{
    long double x;
    long double y;
};

long double abso(long double x)
{
    if(x<0)
    x*=(-1);
    return x;
}

int roundoff(long double x)
{
    int trc=x;
    long double frac=x-trc;

    if(frac > 0.5)
    return trc+1;
    
    if(frac<0.5)
    return trc;

    if(frac==0.5 && trc%2==0)
    return trc;

    if(frac==0.5 && trc%2!=0)
    return trc+1;    
}

class keys
{
    private:
    long double theta,k,a,b,c;
    string decrypter(vector <point> p)
    {
        string s;
        int n=p.size();
        for(int i=0;i<n;++i)
        s+=(char)roundoff(p[i].x+(abso(a*p[i].x+b*p[i].y+c)/(a*a+b*b))*((a*(1+1/k)*(sign(p[i].x,p[i].y)))-b*tan(theta*3.1475/180.0)));
        return s;
    }

    int sign(long double x,long double y)
    {
        if(a*x+b*y+c<0)
        return 1;
        if(a*x+b*y+c>0)
        return -1;
        if(a*x+b*y+c==0)
        return 0;
    }
    public:
    keys(){}
    keys(long double t,long double k1,long double a1,long double b1,long double c1):theta(t),k(k1),a(a1),b(b1),c(c1){}
    

      string call(vector<point> p)
      {
          return decrypter(p);
      }

    vector<point> encrypter(string s,int j)
    {
        int size=s.size();
       vector<point> op;

        for(int i=0;i<size;++i)
        {
            point p;
            int v=s[i];
            p.x=v+(abso(a*v+b*j+c)/(a*a+b*b))*(b*k*tan(theta*3.1475/180.0)+a*(k+1)*(sign(v,j)));
            p.y= j + (abso(a*v+b*j+c)/(a*a+b*b))*( b*(k+1)*(sign(v,j))-a*k*tan(theta*3.1475/180.0));
   
            cout<<(char)v<<"->"<<'('<<p.x<<','<<p.y<<')'<<endl;
            op.push_back(p);
        }
        cout<<endl;
        return op;
    }

};

int main()
{    
    long double theta,k,a,b,c,y;
    string s;
    cout<<"hi! alice please set your value for theta: "<<endl;
    cin>>theta;
    cout<<"please set your value for k (k>0): "<<endl;
    cin>>k;
    cout<<"please set your value for a: "<<endl;
    cin>>a;
    cout<<"please set your value for b: "<<endl;
    cin>>b;
    cout<<"please set your value for c: "<<endl;
    cin>>c;
    keys alice(theta,k,a,b,c);
    cout<<"Hi! Bob choose a random number coordinate for encryption: "<<endl;
    cin>>y;
    cout<<"Hi! Bob drop the message for alice: "<<endl;
    getchar();
    getline(cin,s);
    cout<<"the encrypted message(point form) is ..."<<endl;
    vector p=alice.encrypter(s,y);
    cout<<"\n\nHi! Alice you have a message from Bob press any key to view the message...\n\n"<<endl;
    getchar();
    cout<<alice.call(p)<<endl;
}



        
            
        
    